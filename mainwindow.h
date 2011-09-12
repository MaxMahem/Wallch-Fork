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
#include "about.h"
#include "ui_mainwindow.h"
#include "preferences.h"

#include <QtNetwork>
#include <QObject>
#include <gconf/gconf-client.h>
#include <QtSql>

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

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;             /**< TODO */

    QTimer  *updateTimer;           /**< TODO */

    QAction *Start_action;          /**< TODO */
    QAction *Stop_action;           /**< TODO */
    QAction *Next_action;           /**< TODO */
    QAction *Previous_action;       /**< TODO */
    QAction *Show_action;           /**< TODO */
    QAction *Settings_action;       /**< TODO */
    QAction *About_action;          /**< TODO */
    QAction *Quit_action;           /**< TODO */

    about       *About;             /**< TODO */
    Preferences *preferences;       /**< TODO */

    QSqlTableModel *itemTableModel;
    QSqlDatabase    sqliteDatabase;

    GConfClient* gconfClient;       /**< TODO */

    QUrl                  url;      /**< TODO */
    QNetworkAccessManager qnam;     /**< TODO */
    QNetworkReply         *reply;   /**< TODO */

    int delaySeconds;               /**< TODO */
    int timerSeconds;               /**< TODO */

    QSettings settings;             /**< TODO */
    bool desktopNotification;       /**< TODO */
    bool soundNotification;         /**< TODO */
    bool customSound;               /**< TODO */
    bool running;                   /**< TODO */

    QList<int> badRows;             /**< TODO */

    Notify::Notification *notification;

    void loadSettings();
    void addItems(QStringList imageList);
    void closeEvent(QCloseEvent*);
    void randomImage();
    void desktopNotify(QString qimage);
    void soundNotify();
    void updateProgressBar();
    void changeBackground(QString picture);
    void changeWallpaperToCurrent();
    static bool isValidImage(const QString &image);

private Q_SLOTS:
    void on_previousButton_clicked();
    void on_addfolder_clicked();
    void on_listWidget_customContextMenuRequested();
    void on_itemView_doubleClicked(QModelIndex index);
    void on_itemView_itemSelectionChanged();
    void on_removeallButton_clicked();
    void on_removeButton_clicked();
    void on_addButton_clicked();
    void on_stopButton_clicked();
    void on_nextButton_clicked();
    void on_startButton_clicked();
    void on_timerSlider_valueChanged(int value);

    void timeUpdater();

    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

    void dbus_action(const QString &msg);

    void on_webSourceRadio_toggled(bool checked);

    void on_randomButton_clicked();


public Q_SLOTS:

    void ShowPreferences();
    void menushowabout();
    void pruneList();
    void removeDisk();
    void load();
    void Openfolder();
    void copyImage();
    void copyPath();
    void save_album();
};

#endif // MAINWINDOW_H
