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

#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
#include <QObject>
#include <QSettings>
#include <gconf/gconf-client.h>
#include <SFML/Audio.hpp>

#define DEFAULTSOUNDFILE "/usr/share/wallch/files/notification.ogg";

namespace Ui { class Preferences; }

class Preferences : public QDialog {
    Q_OBJECT
    Q_ENUMS(startupEnum)
    Q_ENUMS(backgroundSettingEnum)

public:
    Preferences(QWidget *parent = 0);
    ~Preferences();

    enum startupEnum           { run, once, liveEarth };
    enum backgroundSettingEnum { wallpaper, zoom, centered, scaled, streched,  spanned };

private:
    Ui::Preferences *ui;

    QSettings    settings;
    sf::Music    sound;
    GConfClient* gconfClient;

    QHash<QString, int> backgroundSettingNames;

    bool    settingsPlaySound;
    bool    settingsCustomSound;
    bool    settingsMinimizeToTray;
    bool    settingsDesktopNotification;
    QString settingsStartup;
    QString soundFileName;
    QString settingsBackgroundSetting;
    QString settingsHistory;

private Q_SLOTS:
    void on_resetPreferencesButton_clicked();
    void on_browseSoundButton_clicked();
    void on_saveButton_clicked();
    void on_closeButton_clicked();
    void on_testSoundButton_clicked();
    void on_customSoundRadio_toggled(bool);
};

#endif // PREFERENCES_H
