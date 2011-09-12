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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "preferences.h"
#include "about.h"

#include <fstream>
#include <iostream>

#include <QMessageBox>
#include <QClipboard>
#include <QtDBus/QtDBus>
#include <QtDBus/QDBusMessage>
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

    // Read in the item list
    QSettings settingsItemList("Wallch", "ItemList");
    int size = settingsItemList.beginReadArray("listwidgetitem");
    for (int i = 0; i < size; ++i) {
        settingsItemList.setArrayIndex(i);
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(settingsItemList.value("item").toString());
        item->setStatusTip(tr("Double-click to set an item from the list as Background"));
        ui->listWidget->addItem(item);
    }
    settingsItemList.endArray();

    // set up database connection
    this->sqliteDatabase = QSqlDatabase::addDatabase("QSQLITE");
    this->sqliteDatabase.setDatabaseName(QDir::currentPath()+"/wallpaper.db");

    if (!this->sqliteDatabase.open()) {
        QMessageBox::critical(this, qApp->tr("Cannot open database"),
            qApp->tr("Error connecting to the sqlite database, this program will now exit."), QMessageBox::Ok);
        qDebug() << "Error connecting to sqlite database.";
        QCoreApplication::exit(1);
    }

    QSqlQuery("CREATE TABLE IF NOT EXISTS wallpapers (id INTEGER PRIMARY KEY,"
                                                     "filename TEXT NOT NULL,"
                                                     "fullpath TEXT NOT NULL UNIQUE);");

    itemTableModel = new QSqlTableModel(this, this->sqliteDatabase);
    itemTableModel->setTable("wallpapers");
    itemTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    itemTableModel->select();

    // set the item count
    ui->wallpaperCountLabel->setText(QString::number(ui->listWidget->count()));

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
    connect(ui->action_Preferences, SIGNAL(triggered()), this, SLOT(ShowPreferences()));
    connect(ui->actionQuit_Ctrl_Q, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->action_Start, SIGNAL(triggered()), this, SLOT(on_startButton_clicked()));
    connect(ui->actionS_top, SIGNAL(triggered()), this, SLOT(on_stopButton_clicked()));
    connect(ui->action_Load, SIGNAL(triggered()), this, SLOT(load()));
    connect(ui->actionRemove_list, SIGNAL(triggered()), this, SLOT(pruneList()));
    connect(ui->action_Previous_Image_Shift_Ctrl_B, SIGNAL(triggered()), this, SLOT(on_previousButton_clicked()));
    connect(ui->action_Next_Image, SIGNAL(triggered()), this, SLOT(on_nextButton_clicked()));
    connect(ui->actionAdd_single_images, SIGNAL(triggered()), this, SLOT(on_addButton_clicked()));
    connect(ui->actionAdd_Folder, SIGNAL(triggered()), this, SLOT(on_addfolder_clicked()));
    connect(ui->save_as, SIGNAL(triggered()), this, SLOT(save_album()));

    //setting up the shortcut keys!
    (void) new QShortcut(Qt::CTRL + Qt::Key_Q, this, SLOT(close()));
    (void) new QShortcut(Qt::CTRL + Qt::Key_P, this, SLOT(ShowPreferences()));
    (void) new QShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_S, this, SLOT(on_startButton_clicked()));
    (void) new QShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_O, this, SLOT(on_stopButton_clicked()));
    (void) new QShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_N, this, SLOT(on_nextButton_clicked()));
    (void) new QShortcut(Qt::CTRL + Qt::Key_O, this, SLOT(load()));
    (void) new QShortcut(Qt::CTRL + Qt::Key_I, this, SLOT(on_addButton_clicked()));
    (void) new QShortcut(Qt::CTRL + Qt::Key_F, this, SLOT(on_addfolder_clicked()));
    (void) new QShortcut(Qt::Key_Delete, this, SLOT(on_removeButton_clicked()));
    (void) new QShortcut(Qt::Key_Return, this, SLOT(on_listWidget_itemDoubleClicked()));
    (void) new QShortcut(Qt::SHIFT + Qt::CTRL + Qt::Key_P, this, SLOT(on_previousButton_clicked()));

    // SetMouseTracking to true so the items of the listwidget can have statusbar
    ui->listWidget->setMouseTracking(true);
    ui->startButton->setIcon(QIcon::fromTheme("media-playback-start"));
    ui->action_Start->setIcon(QIcon::fromTheme("media-playback-start"));
    ui->stopButton->setIcon(QIcon::fromTheme("media-playback-stop"));
    ui->actionS_top->setIcon(QIcon::fromTheme("media-playback-stop"));
    ui->previousButton->setIcon(QIcon::fromTheme("media-seek-backward"));
    ui->action_Previous_Image_Shift_Ctrl_B->setIcon(QIcon::fromTheme("media-seek-backward"));
    ui->nextButton->setIcon(QIcon::fromTheme("media-seek-forward"));
    ui->action_Next_Image->setIcon(QIcon::fromTheme("media-seek-forward"));
    ui->removeButton->setIcon(QIcon::fromTheme("list-remove"));
    ui->removeallButton->setIcon(QIcon::fromTheme("edit-delete"));
    ui->addfolder->setIcon(QIcon::fromTheme("folder-new"));
    ui->actionAdd_Folder->setIcon(QIcon::fromTheme("folder-new"));
    ui->addButton->setIcon(QIcon::fromTheme("list-add"));
    ui->actionQuit_Ctrl_Q->setIcon(QIcon::fromTheme("application-exit"));
    ui->action_Preferences->setIcon(QIcon::fromTheme("preferences-desktop"));
    ui->actionAdd_single_images->setIcon(QIcon::fromTheme("insert-image"));
    ui->actionAdd_a_Wallch_album->setIcon(QIcon::fromTheme("list-add"));
    ui->action_Start->setIcon(QIcon::fromTheme("media-playback-start"));
    ui->action_Load->setIcon(QIcon::fromTheme("folder"));

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
    QApplication::setQuitOnLastWindowClosed(1);

    QSettings settingsItemList("Wallch", "ItemList");
    settingsItemList.beginWriteArray("listwidgetitem");
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        settingsItemList.setArrayIndex(i);
        settingsItemList.setValue("item", ui->listWidget->item(i)->text() );
    }
    settingsItemList.endArray();
    settingsItemList.sync();

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
    QStringList     succesfulMessage;
    QProgressDialog progressDialog(qApp->tr("Adding Wallpapers..."), qApp->tr("Cancel"), 0, imageList.count(), this);
    int             progress = 1;

    progressDialog.show();

    // itterate over the given entries, if we get nothing, there will be nothing to do.
    Q_FOREACH(QString imagePath, imageList) {
        // check to see if we were cancled.
        if (progressDialog.wasCanceled())
            break;

        progressDialog.setValue(progress);
        progressDialog.setLabelText(qApp->tr("Adding file number %1 of %2...").arg(progress).arg(imageList.count()));

        // we only want to operate on valid images
        if (MainWindow::isValidImage(imagePath)) {
            // get a record item
            QSqlRecord record = this->itemTableModel->record();

            // set it's values
            record.setValue(1, QFileInfo(imagePath).fileName());
            record.setValue(2, imagePath);

            // add image to database
            this->itemTableModel->insertRecord(-1, record);
            if (!this->itemTableModel->submitAll()) {
                // submit failed, almost certianly because the item is already in the database.
                if (this->itemTableModel->lastError().number() == 19) {
                    warningMessage.append(qApp->tr("Duplicate Image: ") + QFileInfo(imagePath).fileName());
                } else {
                    warningMessage.append(qApp->tr("Error inserting: ") + QFileInfo(imagePath).fileName());
                    qDebug() << this->itemTableModel->lastError();
                }

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
 * @brief
 *
 */
void MainWindow::on_removeButton_clicked()
{
    delete ui->listWidget->currentItem();
}

/**
 * @brief
 *
 */
void MainWindow::on_removeallButton_clicked()
{
    ui->listWidget->clear();
}

/**
 * @brief
 *
 */
void MainWindow::on_listWidget_itemSelectionChanged()
{
    QImage image(ui->listWidget->currentItem()->text());
    ui->wallpaperPreviewLabel->setPixmap(QPixmap::fromImage(image));
}

/**
 * @brief
 *
 */
void MainWindow::on_listWidget_itemDoubleClicked()
{
    MainWindow::changeBackground(ui->listWidget->currentItem()->text());
}

/**
 * @brief Prunes the list of any invalid enteries, uses QtConcurrent for speed.
 *
 * Currently have not found a great way to make it work parsing QListWidgetItems directly, so we parse the
 * text they contain, and attempt to remove the bad items. Currently haven't got that working yet though!
 */
void MainWindow::pruneList()
{   
    QStringList items;
    for (int r = 0; r < ui->listWidget->count() - 1;  r++) {
        items.append(ui->listWidget->item(r)->text());
    }

//    QList<QListWidgetItem*> items = ui->listWidget->findItems("*", Qt::MatchWildcard | Qt::MatchWrap);

    QFutureWatcher<void> futureWatcher;
    QFuture<void> badList = QtConcurrent::filter(items, MainWindow::isValidImage);
    futureWatcher.setFuture(badList);

    QProgressDialog progressDialog(tr("Processing Images..."), tr("Cancel"), badList.progressMinimum(), badList.progressMaximum());

    QObject::connect(&futureWatcher, SIGNAL(finished()), &progressDialog, SLOT(reset()));
//    QObject::connect(progressDialog, SIGNAL(canceled()), &futureWatcher, SLOT(cancel()));
    QObject::connect(&futureWatcher, SIGNAL(progressValueChanged(int)), &progressDialog, SLOT(setValue(int)));

    progressDialog.exec();

    badList.waitForFinished();

    QString badItemsForDialog = "";
    for (int r = 0; r < items.count() - 1; r++) {
        badItemsForDialog.append(items.value(r) + QString("\n"));
    }

    badItemsForDialog.prepend(tr("Invalid Wallpapers found:") + QString("\n"));

    if (QMessageBox::question(this, tr("Remove wallpapers from list?"), badItemsForDialog,
                          QMessageBox::Ok | QMessageBox::Cancel)) {
        for (int r = 0; r < items.count() - 1; r++) {
            QList<QListWidgetItem*> itemsToDelete = ui->listWidget->findItems(items.value(r), Qt::MatchExactly);
            for (int i = 0; r < itemsToDelete.count() - 1; i++)
                delete itemsToDelete.value(i);
//            delete ui->listWidget->findItems(items.value(r), Qt::MatchExactly);
        }
    }
}

/**
 * @brief
 *
 */
void MainWindow::removeDisk() {
    if (QMessageBox::warning(this, tr("Image Deltion"), "The image you selected will be permently deleted from your disk.",
                         QMessageBox::Ok | QMessageBox::Cancel)
            == QMessageBox::Ok)
        QFile::remove(ui->listWidget->currentItem()->text());

    delete ui->listWidget->currentItem();
}

/**
 * @brief
 *
 */
void MainWindow::load() {
    QString selection = QFileDialog::getOpenFileName(this, tr("Choose Album"), QDir::homePath(), "*.wallch");

    if (selection.count()) {
        QFile file(selection);
        file.open(QIODevice::ReadOnly | QIODevice::Text);

        QStringList list;
        while (!file.atEnd()) {
            list << file.readLine().trimmed();
        }

        file.close();

        ui->listWidget->addItems(list);
    }
}

bool MainWindow::isValidImage (const QString &image) {
    return !QImage(image).isNull();
}

//bool MainWindow::validateImage (const QListWidgetItem &item) {
//    return QImage(item.text()).isNull();
//}

/**
 * @brief
 *
 */
void MainWindow::copyPath() {
    QClipboard *clip = QApplication::clipboard();
    clip->setText(ui->listWidget->currentItem()->text());
}

/**
 * @brief
 *
 */
void MainWindow::copyImage() {
    QClipboard *clip = QApplication::clipboard();
    clip->setImage(QImage(ui->listWidget->currentItem()->text()), QClipboard::Clipboard);
}

/**
 * @brief
 *
 */
void MainWindow::on_listWidget_customContextMenuRequested()
{
    QMenu menu;
    menu.addAction(tr("Set this item as Background"),this,SLOT(on_listWidget_itemDoubleClicked()));
    menu.addAction(tr("Remove non-existent Pictures"),this,SLOT(pruneList()));
    menu.addAction(tr("Delete image from disk"),this,SLOT(removeDisk()));
    menu.addAction(tr("Copy path to clipboard"),this,SLOT(copyPath()));
    menu.addAction(tr("Copy image to clipboard"),this,SLOT(copyImage()));
    menu.addAction(tr("Open folder"),this,SLOT(Openfolder()));;

    if (ui->listWidget->count() > 0)
        menu.exec(QCursor::pos());
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
    QList<QUrl> urlList = event->mimeData()->urls();
    for (QList<QUrl>::const_iterator i = urlList.begin(); i != urlList.end();i++)
    {
       QString strFile2 = (*i).toString();
       if(strFile2.endsWith(".png") || strFile2.endsWith(".gif") || strFile2.endsWith(".bmp") || strFile2.endsWith(".jpg") || strFile2.endsWith(".jpeg") || strFile2.endsWith(".PNG") || strFile2.endsWith(".GIF") || strFile2.endsWith(".BMP") || strFile2.endsWith(".JPG") || strFile2.endsWith(".JPEG")){
          QString strFile1 = strFile2.mid(7, strFile2.length() - 2);
          ui->listWidget->addItem(strFile1);
       }
       else if(strFile2.endsWith(".wallch"))
       {
           QString file1 = strFile2.mid(7,strFile2.length()-2);
           char *path = file1.toUtf8().data();
           FILE *file = fopen ( path, "r" );
                  if ( file != NULL )
                  {
                      ifstream file( path ) ;
                      string line ;
                      while( std::getline( file, line ) )
                      {
                          QString qstr = QString::fromUtf8(line.c_str());
                          QListWidgetItem *item = new QListWidgetItem;
                                           item->setText(qstr);
                                           item->setStatusTip(tr("Double-click to set an item from the list as Background"));
                          ui->listWidget->addItem(item);
                      }
                  }
                  fclose ( file );
       }
    }

    event->acceptProposedAction();
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
    // if the count is 0 (false) we don't want to run any of this code, we'll divide by 0!
    if (ui->listWidget->count()) {
        int randomRow = (qrand() % ui->listWidget->count());

        if (QImage(ui->listWidget->item(randomRow)->text()).isNull()) {
            // if a bad image file is passed we want to instead select another one, calling this function again.
            // currently the bad file is deleted from the item list, not sure if this is desired
            // removing it does prevent a potential infinate loop condition (if there was only one bad item).
            delete ui->listWidget->item(randomRow);
            MainWindow::randomImage();
            qDebug() << ui->listWidget->item(randomRow)->text() << "is invalid, check existance and permissions."
                     << "It has been removed from the list.";
        } else {
            // recieved a good background so we are good to go.
            MainWindow::changeBackground(ui->listWidget->item(randomRow)->text());
            ui->listWidget->setCurrentRow(randomRow);
        }
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
    if (ui->listWidget->count() != 0) {
        int row = ui->listWidget->currentRow() + 1;

        if (row >= ui->listWidget->count())
            row = 0;

        ui->listWidget->setCurrentRow(row);

        MainWindow::changeBackground(ui->listWidget->currentItem()->text());
    }
}

/**
 * @brief
 *
 */
void MainWindow::on_previousButton_clicked()
{
    if (ui->listWidget->count() != 0) {

        int row = ui->listWidget->currentRow() - 1;
        if (row < 0)
            row = ui->listWidget->count() - 1;

        ui->listWidget->setCurrentRow(row);

        MainWindow::changeBackground(ui->listWidget->currentItem()->text());
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
void MainWindow::Openfolder(){
    QDesktopServices::openUrl(QUrl("file:///" + ui->listWidget->currentItem()->text()));
}

/**
 * @brief
 *
 */
void MainWindow::save_album() {
    QString format = "wallch";
    QString initialPath = QDir::currentPath() + "/album." + format;
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                               initialPath,
                               tr("%1 Files (*.%2);;All Files (*)")
                               .arg(format.toUpper())
                               .arg(format));
    if(!fileName.isEmpty()){
        QFile file8( fileName );

        if( file8.open( QIODevice::WriteOnly ) ) {
          // file opened and is overwriten with WriteOnly
          QTextStream textStream( &file8 );
          for( int i=0; i < ui->listWidget->count(); ++i ){
             textStream << ui->listWidget->item(i)->text();
             textStream << '\n';
          }
          file8.close();
        }
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
