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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "preferences.h"
#include "mainwindow.h"

#include <QtNetwork>
#include <QObject>
#include <gconf/gconf-client.h>
#include <QtSql>
#include <QStandardItemModel>
#include <QMainWindow>

namespace Notify {
    class Notification;
}

namespace Ui {
    class MainWindow;
}

/**
 * @brief
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_ENUMS(Source);

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    enum Source { LOCAL, REMOTE };

private:
    QMetaEnum sourceEnum;
    Source source;

    Ui::MainWindow *ui;                     /**< TODO */

    QTimer  *updateTimer;                   /**< TODO */

//    About       *about;                     /**< TODO */
    Preferences *preferences;               /**< TODO */

    QSqlTableModel *wallpaperTable;         /**< TODO */
    QSqlDatabase    sqliteDatabase;         /**< TODO */

    GConfClient* gconfClient;               /**< TODO */

    QNetworkAccessManager *networkManager;            /**< TODO */
    QNetworkReply         *reply;           /**< TODO */

    int delaySeconds;                       /**< TODO */
    int timerSeconds;                       /**< TODO */

    QSettings settings;                     /**< TODO */
    bool desktopNotification;               /**< TODO */
    bool soundNotification;                 /**< TODO */

    bool running;

    Notify::Notification *notification;

    void loadSettings();
    void pruneList();
    void removeDisk();
    void openFolder();
    void addItems(QStringList imageList);
    void closeEvent(QCloseEvent*);
    void desktopNotify(QString qimage);
    void soundNotify();
    void updateProgressBar();
    void changeBackground(QString picture);
    void getRemoteWallpaper(QUrl url);
    void changeWallpaperToCurrent();
    void changeModel(Source source);

    static bool isValidImage(const QString &image);

private Q_SLOTS:
    void on_previousButton_clicked();
    void on_nextButton_clicked();
    void on_itemView_doubleClicked(QModelIndex index);
    void on_itemView_itemSelectionChanged();
    void on_itemView_customContextMenuRequested(QPoint position);

    void on_addButton_clicked();
    void on_addfolder_clicked();
    void on_removeallButton_clicked();
    void on_removeButton_clicked();
    void on_stopButton_clicked();
    void on_startButton_clicked();
    void on_refreshButton_clicked();

    void on_timerSlider_valueChanged(int value);
    void on_webSourceRadio_toggled(bool checked);

    void timeUpdater();

    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

    void dbusAction(const QString &msg);

    void on_actionAddAlbum_triggered();
    void on_actionAbout_triggered();
    void on_actionPreferences_triggered();
    void on_actionSaveAlbum_triggered();
    void on_actionSaveGnome_triggered();

    void downloadFinished(QNetworkReply*);
    void randomImage();
};

#endif // MAINWINDOW_H
