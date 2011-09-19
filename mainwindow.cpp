/*Wallch - WallpaperChanger
A tool for changing Desktop Wallpapers automatically
with lots of features
Copyright © 2011 by Alex Solanos and Leon Vytanos

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 3
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.*/

#define QT_NO_KEYWORDS

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "preferences.h"
#include "about.h"
#include "raitingdelegate.h"

#include <fstream>
#include <iostream>

#include <QMessageBox>
#include <QtDBus>
#include <QUrl>
#include <QDrag>
#include <QProgressDialog>
#include <QFileDialog>
#include <QAction>
#include <QSettings>
#include <QMenu>
#include <QShortcut>
#include <QDropEvent>

#include <QWidget>
#include <QtConcurrentRun>
#include <QtXml>

#include <QtNetwork>
#include <QDesktopServices>

#include <SFML/Audio.hpp>

#include <libnotifymm/init.h>
#include <libnotifymm/notification.h>

using namespace std;

/**
 * @brief
 *
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    //after all the basic checks, setting up the UI
    ui->setupUi(this);

    // listening to DBUS for another wallch instance/or to open a new album/or to do some action
    QDBusConnection::sessionBus().connect(QString(),QString(), "do.action", "wallch_message", this, SLOT(dbus_action(QString)));

    // set up database connection
    this->sqliteDatabase = QSqlDatabase::addDatabase("QSQLITE");
    this->sqliteDatabase.setDatabaseName("wallpaper.db");

    if (!this->sqliteDatabase.open()) {
        QMessageBox::critical(this, qApp->tr("Cannot open database"),
            qApp->tr("Error connecting to the sqlite database, this program will now exit."), QMessageBox::Ok);
        qDebug() << "Error connecting to sqlite database.";
        QCoreApplication::exit(1);
    }

    QSqlQuery("CREATE TABLE IF NOT EXISTS wallpapers (id INTEGER PRIMARY KEY,"
                                                     "filename TEXT NOT NULL,"
                                                     "fullpath TEXT NOT NULL UNIQUE,"
                                                     "filesize TEXT NOT NULL,"
                                                     "imagesize TEXT NOT NULL,"
                                                     "ratio TEXT NOT NULL,"
                                                     "raiting INTEGER)");

    this->itemTableModel = new QSqlTableModel(this, this->sqliteDatabase);
    this->itemTableModel->setTable("wallpapers");
    this->itemTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->itemTableModel->select();

    ui->itemView->setModel(this->itemTableModel);

    ui->itemView->hideColumn(0);
    this->itemTableModel->setHeaderData(1, Qt::Horizontal, tr("Filename"));
    this->itemTableModel->setHeaderData(2, Qt::Horizontal, tr("Path"));
    this->itemTableModel->setHeaderData(3, Qt::Horizontal, tr("Filesize"));
    this->itemTableModel->setHeaderData(4, Qt::Horizontal, tr("Imagesize"));
    this->itemTableModel->setHeaderData(5, Qt::Horizontal, tr("Ratio"));
    this->itemTableModel->setHeaderData(6, Qt::Horizontal, tr("Raiting"));

    ui->itemView->setItemDelegateForColumn(6, new RaitingDelegate);

    // set the item count
    ui->wallpaperCountLabel->setText(QString::number(this->itemTableModel->rowCount()));

    // load settings
    MainWindow::loadSettings();

    // build the GConfConnection
    gconfClient = gconf_client_get_default();

    // initilise the RNG
    qsrand(QDateTime::currentMSecsSinceEpoch());

    // Setting up the timer
    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(timeUpdater()));

    // Set up Notifications
    Notify::init(QCoreApplication::applicationName().toStdString());
    notification = new Notify::Notification(tr("Wallpaper Changed").toStdString(), "Filename");

    //SIGNAL-SLOT action here
    connect(ui->action_About, SIGNAL(triggered()), this, SLOT(menushowabout()));
    connect(ui->actionPreferences, SIGNAL(triggered()), this, SLOT(ShowPreferences()));
    connect(ui->actionQuit_Ctrl_Q, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->action_Start, SIGNAL(triggered()), this, SLOT(on_startButton_clicked()));
    connect(ui->actionS_top, SIGNAL(triggered()), this, SLOT(on_stopButton_clicked()));
    connect(ui->actionRemove_list, SIGNAL(triggered()), this, SLOT(pruneList()));
    connect(ui->actionPreviousImage, SIGNAL(triggered()), this, SLOT(on_previousButton_clicked()));
    connect(ui->action_Next_Image, SIGNAL(triggered()), this, SLOT(on_nextButton_clicked()));
    connect(ui->save_as, SIGNAL(triggered()), this, SLOT(saveAlbum()));

    //setting up the shortcut keys!
    (void) new QShortcut(Qt::CTRL + Qt::Key_Q,             this, SLOT(close()));
    (void) new QShortcut(Qt::CTRL + Qt::Key_P,             this, SLOT(ShowPreferences()));
    (void) new QShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_S, this, SLOT(on_startButton_clicked()));
    (void) new QShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_O, this, SLOT(on_stopButton_clicked()));
    (void) new QShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_N, this, SLOT(on_nextButton_clicked()));
    (void) new QShortcut(Qt::CTRL + Qt::Key_I,             this, SLOT(on_addButton_clicked()));
    (void) new QShortcut(Qt::CTRL + Qt::Key_F,             this, SLOT(on_addfolder_clicked()));
    (void) new QShortcut(Qt::Key_Delete,                   this, SLOT(on_removeButton_clicked()));
    (void) new QShortcut(Qt::Key_Return,                   this, SLOT(changeWallpaperToCurrent()));
    (void) new QShortcut(Qt::SHIFT + Qt::CTRL + Qt::Key_P, this, SLOT(on_previousButton_clicked()));

    ui->startButton->setIcon(QIcon::fromTheme("media-playback-start"));
    ui->action_Start->setIcon(QIcon::fromTheme("media-playback-start"));
    ui->stopButton->setIcon(QIcon::fromTheme("media-playback-stop"));
    ui->actionS_top->setIcon(QIcon::fromTheme("media-playback-stop"));
    ui->previousButton->setIcon(QIcon::fromTheme("media-seek-backward"));
    ui->actionPreviousImage->setIcon(QIcon::fromTheme("media-seek-backward"));
    ui->nextButton->setIcon(QIcon::fromTheme("media-seek-forward"));
    ui->action_Next_Image->setIcon(QIcon::fromTheme("media-seek-forward"));
    ui->removeButton->setIcon(QIcon::fromTheme("list-remove"));
    ui->removeallButton->setIcon(QIcon::fromTheme("edit-delete"));
    ui->addfolder->setIcon(QIcon::fromTheme("folder-new"));
    ui->actionAddFolder->setIcon(QIcon::fromTheme("folder-new"));
    ui->addButton->setIcon(QIcon::fromTheme("list-add"));
    ui->actionQuit_Ctrl_Q->setIcon(QIcon::fromTheme("application-exit"));
    ui->actionPreferences->setIcon(QIcon::fromTheme("preferences-desktop"));
    ui->actionAddImages->setIcon(QIcon::fromTheme("insert-image"));
    ui->actionAddAlbum->setIcon(QIcon::fromTheme("list-add"));
    ui->action_Start->setIcon(QIcon::fromTheme("media-playback-start"));


    on_timerSlider_valueChanged(ui->timerSlider->value());

    // fire off a random Image on start, will need to add a group of startup options later.
    MainWindow::randomImage();
}

void MainWindow::loadSettings() {
    //Putting the values back
    ui->timerSlider->setValue(this->settings.value("general/timeSlider", 1).toInt());

    this->desktopNotification = this->settings.value("preferences/desktopNotification", false).toBool();
    this->soundNotification   = this->settings.value("preferences/playSound",           false).toBool();
//                            = this->settings.value("preferences/customSound",         false).toBool();
            // TODO: Add logic for putting in custom sound
}

/**
 * @brief
 *
 * @param
 */
void MainWindow::closeEvent(QCloseEvent *)
{
    QApplication::setQuitOnLastWindowClosed(true);

    QSettings settingsPreferences;
    settingsPreferences.setValue("general/timeSlider", ui->timerSlider->value());
    settingsPreferences.sync();

    this->sqliteDatabase.close();
}

/**
 * @brief Destructor - delete items.
 *
 */
MainWindow::~MainWindow() {
    delete ui;
    delete this->notification;
}

void MainWindow::addItems(QStringList imageList) {
    QStringList     warningMessage;
    QProgressDialog progressDialog(qApp->tr("Adding %1 Wallpapers...").arg(imageList.count()), qApp->tr("Cancel"), 0, imageList.count(), this);
    int             progress = 1;

    progressDialog.show();

    // itterate over the given entries, if we get nothing, there will be nothing to do.
    Q_FOREACH(QString imagePath, imageList) {
        // check to see if we were cancled.
        if (progressDialog.wasCanceled())
            break;

        progressDialog.setValue(progress);

        // we only want to operate on valid images
        // TODO: Consider checking insert/duplicates first, faster then checking valid images, so can bail out sooner.
        // TODO: Speed up validation!
        QImage    image(imagePath);
        QFileInfo imageInfo(imagePath);

        if (!image.isNull()) {
            // get a record item
            QSqlRecord record = this->itemTableModel->record();

            // set it's values
            record.setValue(1, imageInfo.fileName());
            record.setValue(2, imagePath);
            record.setValue(3, QLocale(QLocale::system()).toString(double(imageInfo.size() / 1024), 'f', 0) + "kb");
            record.setValue(4, QString::number(image.size().width()) + "x" + QString::number(image.size().height()));
            record.setValue(5, QString::number(image.size().width()) + ":" + QString::number(image.size().height()));

            // add image to database
            this->itemTableModel->insertRecord(-1, record);
            if (!this->itemTableModel->submitAll()) {
                warningMessage.append(qApp->tr("Error inserting: ") + QFileInfo(imagePath).fileName());
                qDebug() << this->itemTableModel->lastError();

                // if this happens, we need to have the itemTableModel revert it changes.
                this->itemTableModel->revertAll();
            }
        } else {
            warningMessage.append(qApp->tr("Invalid Image: ") + QFileInfo(imagePath).fileName());
        }

        progress++;
    }

    progressDialog.setValue(progress);

    if (warningMessage.count()) {
        QMessageBox::warning(this, qApp->tr("Item Addition Errors"), warningMessage.join("\n"));
    }

    this->itemTableModel->select();
}

/**
 * @brief Adds an item to the item model/sql database
 *
 */
void MainWindow::on_addButton_clicked()
{
    QStringList imageList = QFileDialog::getOpenFileNames(this, tr("Choose Pictures"), QDir::homePath(),
                                                          "Images (*.png *.gif *.bmp *.jpg *.jpeg);;"
                                                          "All Files (*.*)");

    MainWindow::addItems(imageList);
}

/**
 * @brief Removes the currently selected item.
 *
 */
void MainWindow::on_removeButton_clicked()
{
    qDebug() << ui->itemView->currentIndex();
    qDebug() << this->itemTableModel->removeRow(ui->itemView->currentIndex().row());
    qDebug() << this->itemTableModel->lastError().text();
    qDebug() << this->itemTableModel->submitAll();
    qDebug() << this->itemTableModel->lastError().text();
}

/**
 * @brief Displays a warning, and then removes all wallpapers from the DB.
 *
 */
void MainWindow::on_removeallButton_clicked()
{
    if (QMessageBox::question(this, qApp->tr("Delete all wallpapers"), qApp->tr("All wallpapers will be removed."),
                              QMessageBox::Ok | QMessageBox::Cancel)
            == QMessageBox::Ok) {
        this->sqliteDatabase.exec("DELETE FROM wallpapers");
        this->itemTableModel->select();
    }
}

/**
 * @brief
 *
 */
void MainWindow::on_itemView_itemSelectionChanged()
{
    qDebug() << "Fix Me";
//    QImage image(ui->listWidget->currentItem()->text());
//    ui->wallpaperPreviewLabel->setPixmap(QPixmap::fromImage(image));
}

/**
 * @brief Prunes the list of any invalid enteries, uses QtConcurrent for speed.
 *
 * Currently have not found a great way to make it work parsing QListWidgetItems directly, so we parse the
 * text they contain, and attempt to remove the bad items. Currently haven't got that working yet though!
 */
void MainWindow::pruneList()
{   
        qDebug() << "Fix Me";
//    QStringList items;
//    for (int r = 0; r < ui->listWidget->count() - 1;  r++) {
//        items.append(ui->listWidget->item(r)->text());
//    }

////    QList<QListWidgetItem*> items = ui->listWidget->findItems("*", Qt::MatchWildcard | Qt::MatchWrap);

//    QFutureWatcher<void> futureWatcher;
//    QFuture<void> badList = QtConcurrent::filter(items, MainWindow::isValidImage);
//    futureWatcher.setFuture(badList);

//    QProgressDialog progressDialog(tr("Processing Images..."), tr("Cancel"), badList.progressMinimum(), badList.progressMaximum());

//    QObject::connect(&futureWatcher, SIGNAL(finished()), &progressDialog, SLOT(reset()));
////    QObject::connect(progressDialog, SIGNAL(canceled()), &futureWatcher, SLOT(cancel()));
//    QObject::connect(&futureWatcher, SIGNAL(progressValueChanged(int)), &progressDialog, SLOT(setValue(int)));

//    progressDialog.exec();

//    badList.waitForFinished();

//    QString badItemsForDialog = "";
//    for (int r = 0; r < items.count() - 1; r++) {
//        badItemsForDialog.append(items.value(r) + QString("\n"));
//    }

//    badItemsForDialog.prepend(tr("Invalid Wallpapers found:") + QString("\n"));

//    if (QMessageBox::question(this, tr("Remove wallpapers from list?"), badItemsForDialog,
//                          QMessageBox::Ok | QMessageBox::Cancel)) {
//        for (int r = 0; r < items.count() - 1; r++) {
//            QList<QListWidgetItem*> itemsToDelete = ui->listWidget->findItems(items.value(r), Qt::MatchExactly);
//            for (int i = 0; r < itemsToDelete.count() - 1; i++)
//                delete itemsToDelete.value(i);
////            delete ui->listWidget->findItems(items.value(r), Qt::MatchExactly);
//        }
//    }
}

/**
 * @brief
 *
 */
void MainWindow::removeDisk()
{
    qDebug() << "Fix Me";
//    if (QMessageBox::warning(this, tr("Image Deltion"), "The image you selected will be permently deleted from your disk.",
//                         QMessageBox::Ok | QMessageBox::Cancel)
//            == QMessageBox::Ok)
//        QFile::remove(ui->listWidget->currentItem()->text());

//    delete ui->listWidget->currentItem();
}

bool MainWindow::isValidImage (const QString &image) {
    return !QImage(image).isNull();
}

/**
 * @brief
 *
 */
void MainWindow::on_addfolder_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Choose Folder"), QDir::homePath());

    // if we have items returned, path.count won't be 0 and so we process, otherwise we fall through.
    if (path.count()) {
        QStringList  extensionList = (QStringList() << "png" << "gif" << "bmp" << "jpg" << "jpeg");
        QDirIterator dirIterator(path, QDir::Files, QDirIterator::Subdirectories);
        QStringList  imageList;

        // walk the directory and its sub-directories, adding any files therin.
        while(dirIterator.hasNext()) {
            if (extensionList.contains(dirIterator.fileInfo().suffix(), Qt::CaseInsensitive))
                imageList.append(dirIterator.fileInfo().absoluteFilePath());

            dirIterator.next();
        }

        this->addItems(imageList);
    }
}

/**
 * @brief
 *
 * @param event
 */
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasText())
        event->acceptProposedAction();
}

/**
 * @brief
 *
 * @param event
 */
void MainWindow::dropEvent(QDropEvent *event)
{
    qDebug() << "Test Me";

//    QList<QUrl> urlList = event->mimeData()->urls();
//    Q_FOREACH (QUrl url, urlList) {
//       ui->listWidget->addItem(strFile1);
//       }
//       if(url.toString().endsWith(".wallch")) {
//           QString file1 = url.toString().mid(7,url.toString().length()-2);
//           char *path = file1.toUtf8().data();
//           FILE *file = fopen ( path, "r" );
//           if (file != NULL) {
//               ifstream file( path ) ;
//               string line ;
//               while(std::getline( file, line)) {
//                   QString qstr = QString::fromUtf8(line.c_str());
//                   QListWidgetItem *item = new QListWidgetItem;
//                   item->setText(qstr);
//                   item->setStatusTip(tr("Double-click to set an item from the list as Background"));
//                   ui->listWidget->addItem(item);
//               }
//           }
//           fclose ( file );
//       }
//    }

//    event->acceptProposedAction();
}

/**
 * @brief
 *
 * @param msg
 */
void MainWindow::dbus_action(const QString &msg) //QDBus signal handling
{
    if (msg=="FOCUS") { //another application instance has come without any arguments, so focus to the already running process!
        this->showNormal();
        this->setFocusPolicy(Qt::StrongFocus);
        this->setFocus();
        this->raise();
        this->setVisible(1);
        this->activateWindow();    
    } else if(msg=="--start") {
        on_startButton_clicked();
    } else if(msg=="--pause") {
        on_startButton_clicked();
    } else if(msg=="--stop") {
        on_stopButton_clicked();
    } else if(msg=="--next") {
        on_nextButton_clicked();
    } else if(msg=="--previous") {
        on_previousButton_clicked();
    } else if(msg=="--constant") {
        on_startButton_clicked();
    } else if(msg=="--once") {
        MainWindow::randomImage();
    } else
        cerr << QString("Program received the unknown dbus message: " + msg +"\n").toLocal8Bit().data();
}


/**
 * @brief The startButton controls starting and stopping of playback, it is actually functions as a play/pause toggle
 *
 */
void MainWindow::on_startButton_clicked() {
    if (this->running == false) {
        // start the timer
        this->timerSeconds = this->delaySeconds;
        this->updateTimer->start(1000);

        this->running = true;
    } else {
        // stop the timer
        this->updateTimer->stop();

        this->running = false;
    }
}

/**
 * @brief Selects a random image from the current list and changes the background to it
 *
 */
void MainWindow::randomImage()
{
    // if we currently have no rows we don't want to run any of this code, we'll divide by 0!
    if (this->itemTableModel->rowCount()) {
        // get a random image... this all could be compressed, but we do it this way to be readable.
        int         randomRow   = (qrand() % this->itemTableModel->rowCount());
        QModelIndex randomIndex = this->itemTableModel->index(randomRow, 2);
        QString     randomImage = randomIndex.data().toString();

        // recieved a good background so we are good to go.
        MainWindow::changeBackground(randomImage);
        ui->itemView->setCurrentIndex(randomIndex);
    }
}

/**
 * @brief
 *
 */
void MainWindow::updateProgressBar()
{
    ui->time_for_next->setValue(timerSeconds);

    int hours   = timerSeconds / 60 / 60;
    int minutes = timerSeconds / 60 % 60;
    int seconds = timerSeconds % 60;

    QString progressBarText = "";

    if (hours > 0)                     progressBarText += QString::number(hours)   + " hrs ";
    if (minutes > 0)                   progressBarText += QString::number(minutes) + " min ";
    if (((seconds > 0) && (hours == 0)) ||
        (timerSeconds == 0))           progressBarText += QString::number(seconds) + " sec";

    ui->time_for_next->setFormat(progressBarText.simplified());
}


/**
 * @brief
 *
 * @param value
 */
void MainWindow::on_timerSlider_valueChanged(int value)
{
    if (value == 0) {                                       // setting  0
        this->delaySeconds = 60 * 1;                        // 1 minute
    } else if ((1 <= value) && (value <= 3))  {             // settings 1-3
        this->delaySeconds = (value - 0) * 60 * 5;          // multiples of  5 minutes (5, 10 15 minutes)
    } else if ((4 <= value) && (value <= 5))  {             // settings 4-5
        this->delaySeconds = (value - 3) * 60 * 30;         // multiples of 30 minutes (30, 60 minutes)
    } else if ((6 <= value) && (value <= 8))  {             // settings 6-8
        this->delaySeconds = (value - 5) * 60 * 60 * 2;     // multiples of  2 hours   (2, 4, 6 hours)
    } else if (9 <= value) {                                // settings 9-10
        this->delaySeconds = (value - 8) * 60 * 60 * 12;    // multiples of 12 hours   (12, 24 hours)
    } else {                                                // shouldn't be able to get here
        qDebug() << "invalid slider value sent, somethings messed up";
        ui->timerSlider->setValue(5);
    }

    // if the timer is dragged under the current delay, set the delay to equal the current value
    if (this->timerSeconds < this->delaySeconds)
        this->timerSeconds = this->delaySeconds;

    QString timerSliderText;

    if (value == 0)
        timerSliderText = "1 " + tr("minute");
    else if ((value > 0) && (value < 6))
        timerSliderText = QString::number(delaySeconds / 60) + " " + tr("minutes");
    else
        timerSliderText = QString::number(delaySeconds / 60 / 60)  + " " + tr(" hours");

    ui->timerSliderLabel->setText(timerSliderText);

    ui->time_for_next->setMaximum(delaySeconds);
    ui->time_for_next->setValue(timerSeconds);
}

/**
 * @brief Called every second while the timer is running, updates the progress bar and/or displays the next wall
 *
 */
void MainWindow::timeUpdater() {
    if (this->running) {
        if(this->timerSeconds != 0) {
            // still time left on the clock
            this->timerSeconds--;                       // deduct the clock
            MainWindow::updateProgressBar();            // update the progress bar
        } else {
            // no time left on the clock
            MainWindow::randomImage();                  // change wallpaper to random image
            MainWindow::updateProgressBar();            // progress bar is updated first so that it can get to 0
            this->timerSeconds = this->delaySeconds;    // reset the clock
        }
    }
}

/**
 * @brief
 *
 */
void MainWindow::on_stopButton_clicked()
{
    this->timerSeconds = this->delaySeconds;    // reset the clock
    MainWindow::updateProgressBar();
    this->running = false;

    this->updateTimer->stop();
}

/**
 * @brief
 *
 */
void MainWindow::on_nextButton_clicked()
{
    if (this->itemTableModel->rowCount()) {
        QModelIndex currentIndex = ui->itemView->currentIndex();
        QModelIndex newIndex;

        if ((currentIndex.row() + 2) <= this->itemTableModel->rowCount())
            newIndex = this->itemTableModel->index(currentIndex.row() + 1, 2);
        else
            newIndex = this->itemTableModel->index(0, 2);

        ui->itemView->setCurrentIndex(newIndex);
        MainWindow::changeBackground(newIndex.data().toString());
    }
}

/**
 * @brief
 *
 */
void MainWindow::on_previousButton_clicked()
{
    if (this->itemTableModel->rowCount()) {
        QModelIndex currentIndex = ui->itemView->currentIndex();
        QModelIndex newIndex;

        if (currentIndex.row() > 0)
            newIndex = this->itemTableModel->index(currentIndex.row() - 1, 2);
        else
            newIndex = this->itemTableModel->index(this->itemTableModel->rowCount() - 1, 2);

        ui->itemView->setCurrentIndex(newIndex);
        MainWindow::changeBackground(newIndex.data().toString());
    }
}

/**
 * @brief
 *
 * @param qimage
 */
void MainWindow::desktopNotify(QString image)
{
    if(!QImage(image).isNull()) {
        this->notification->update(tr("Wallpaper Changed").toStdString(), QFileInfo(image).fileName().toStdString(),
                                   image.toStdString());
        this->notification->show();
    }
}

/**
 * @brief
 *
 * @param picture
 * @return bool
 */
void MainWindow::changeBackground(QString picture) {
    // Change the Background
    if (gconf_client_set_string(gconfClient, "/desktop/gnome/background/picture_filename", picture.toLatin1(), NULL)) {
        // Show notifications, play sounds, and update history, according to preferences.
        if(this->desktopNotification)  QtConcurrent::run(this, &MainWindow::desktopNotify, picture);
        if(this->soundNotification)    QtConcurrent::run(this, &MainWindow::soundNotify);
    } else {
        qDebug() << "Unable to change background, check .gconf permissions";
    }
}

/**
 * @brief
 *
 */
void MainWindow::soundNotify() {
    QString soundFile;

    // TODO: Add logic for playing custom sound
    soundFile = "/usr/share/wallch/files/notification.ogg";

    // Load the sound
    sf::Music sound;

    if (!sound.OpenFromFile(soundFile.toStdString())) {
        qDebug() << "Sound didn't open right.";
        return;
    }

    sound.Play();
    // Loop while the music is playing
    while (sound.GetStatus() == sf::Music::Playing) {
        // Leave some CPU time for other threads
        sf::Sleep(0.1f);
    }
}

/**
 * @brief
 *
 */
void MainWindow::menushowabout() {
    About = new about(this);
    About->show();
}

/**
 * @brief Displays the Preferences window
 *
 */
void MainWindow::ShowPreferences()
{
    preferences = new Preferences(this);
    preferences->exec(); //executing the preferences dialog.
    MainWindow::loadSettings();
}

/**
 * @brief
 *
 */
void MainWindow::openFolder()
{
    QModelIndex currentIndex = ui->itemView->currentIndex();
    QModelIndex rightIndex   = this->itemTableModel->index(currentIndex.row(), 2);
    QDesktopServices::openUrl(QUrl("file:///" + rightIndex.data().toString()));
}

/**
 * @brief
 *
 */
void MainWindow::saveAlbum() {
    // get the filename from the user.
    QString initialPath = QDir::currentPath() + "/album.wallch";
    QString fileName    = QFileDialog::getSaveFileName(this, tr("Save As"), initialPath,
                                                       tr("Wallch Files (*.wallch);;All Files (*)"));

    // create/open the file
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    // check to see if we got any errors
    if (file.error() == QFile::NoError) {
        QDomDocument album("album");

        QDomElement root = album.createElementNS("http://maxmahem.net/album.xsd", "album");
        root.setAttribute("version", "1.0");
        album.appendChild(root);

        for (int i = 0; i < this->itemTableModel->rowCount(); ++i) {
            QDomElement wallpaper = album.createElement("wallpaper");

            QDomElement filenameElement = album.createElement("filename");
            filenameElement.appendChild(album.createTextNode(this->itemTableModel->record(i).value("Filename").toString()));

            QDomElement fullpathElement = album.createElement("fullpath");
            fullpathElement.appendChild(album.createTextNode(this->itemTableModel->record(i).value("Fullpath").toString()));

            QDomElement raitingElement = album.createElement("raiting");
            raitingElement.appendChild(album.createTextNode(this->itemTableModel->record(i).value("Raiting").toString()));

            wallpaper.appendChild(filenameElement);
            wallpaper.appendChild(fullpathElement);
            wallpaper.appendChild(raitingElement);

            root.appendChild(wallpaper);
        }

        QTextStream(&file) << album.toString();
    } else {
        QMessageBox::critical(this, tr("Error Writing File"), tr("Error writing file %1.").arg(file.fileName()));
        qCritical() << file.errorString();
    }
}

void MainWindow::on_webSourceRadio_toggled(bool checked)
{
    QList<QAbstractButton *> buttons = ui->localControlButtonGroup->buttons();
    Q_FOREACH(QAbstractButton *button, ui->localControlButtonGroup->buttons()) {
        button->setVisible(!checked);
    }

}

void MainWindow::on_randomButton_clicked()
{
    MainWindow::randomImage();
}

void MainWindow::on_itemView_doubleClicked(QModelIndex index)
{
    // get the index that refers to the item double clicked row, but column 1.
    QModelIndex rightIndex = this->itemTableModel->index(index.row(), 2);
    // display it. We could do this on one line, but I use two for readability.
    MainWindow::changeBackground(rightIndex.data().toString());
}

void MainWindow::changeWallpaperToCurrent()
{
    // this function exists because I guess some callers can't pass along the right data to on_itemView_doubleClicked
    MainWindow::on_itemView_doubleClicked(ui->itemView->currentIndex());
}


/**
 * @brief Calls a custom context menu.
 *
 * @param position
 */
void MainWindow::on_itemView_customContextMenuRequested(QPoint position)
{
    // check to see if the cursor is on a valid item, we can't do any of this if it isn't.
    if (ui->itemView->indexAt(position) != QModelIndex()) {
        QMenu menu;
        menu.addAction(tr("Set this item as Background"),  this, SLOT(changeWallpaperToCurrent()));
        menu.addAction(tr("Delete image from disk"),       this, SLOT(removeDisk()));
        menu.addAction(tr("Open image"),                   this, SLOT(openFolder()));;
        menu.exec(QCursor::pos());
    }
}

/**
 * @brief
 *
 */
void MainWindow::on_actionAddAlbum_triggered()
{
    QString fileName    = QFileDialog::getOpenFileName(this, tr("Open"), QDir::currentPath(),
                                                       tr("Wallch Files (*.wallch);;All Files (*)"));

    // open the file
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    // check to see if we got any errors
    if (file.error() == QFile::NoError) {
        QDomDocument album;
        QString errorMessage;
        int errorLine;
        int errorColumn;

        // have Qt pase in the xml.
        album.setContent(&file, &errorMessage, &errorLine, &errorColumn);

        // check to see if the error message is null, if it is, we parsed w/ no problem.
        if (errorMessage.isNull()) {
            qCritical() << "Error reading error xml:" << errorMessage << "Line: " << errorLine << "Column:" << errorColumn;

            // get the root element
            QDomElement root = album.documentElement();

            // TODO: Re-evaluate document version validation.
            if (root.tagName() == "Album") {
                if (root.attribute("version") != "1.0")
                    qWarning() << "Processing different version xml. File Version:" << root.attribute("version");

                QDomNodeList wallpaperNodes = root.elementsByTagName("Wallpaper");
                QStringList fileNames;

                // step through the list of nodes, and add them to our item list.
                for (uint i = 0; i < wallpaperNodes.length(); i++) {
                    fileNames << wallpaperNodes.item(i).firstChildElement("Fullpath").text();
                }

                MainWindow::addItems(fileNames);
            }
        } else {
            // errors parsing xml.
            QMessageBox::critical(this, tr("Error Parsing XML"), tr("Error parsing xml in file."));
            qCritical() << "Error parsing xml:" << errorMessage << "Line: " << errorLine << "Column:" << errorColumn;
        }
    } else {
        // errors reading file.
        QMessageBox::critical(this, tr("Error Reading File"), tr("Error reading file %1.").arg(file.fileName()));
        qCritical() << "Error reading file:" << file.errorString();
    }
}
