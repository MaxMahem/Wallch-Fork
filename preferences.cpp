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

#include "preferences.h"
#include "ui_preferences.h"
#include "glob.h"

#include <QSettings>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QShortcut>

#include <QtDebug>
#include <QMetaEnum>

#include <sys/stat.h>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief
 *
 * @param parent
 */
Preferences::Preferences(QWidget *parent) : QDialog(parent), ui(new Ui::Preferences) {
    ui->setupUi(this);

    // build Startup Options Group
    ui->startupOptionsGroup->setId(ui->startupChangeOnceRadio, Preferences::once);
    ui->startupOptionsGroup->setId(ui->startupRunRadio,        Preferences::run);
    ui->startupOptionsGroup->setId(ui->startupLiveEarthRadio,  Preferences::liveEarth);

    // set icons
    ui->testSoundButton->setIcon(QIcon::fromTheme("audio-volume-high"));
    ui->browseSoundButton->setIcon(QIcon::fromTheme("audio-x-generic"));

    QMetaEnum startupMetaEnum = Preferences::staticMetaObject.enumerator(
                Preferences::staticMetaObject.indexOfEnumerator("startupEnum"));
    QMetaEnum backgroundMetaEnum = Preferences::staticMetaObject.enumerator(
                Preferences::staticMetaObject.indexOfEnumerator("backgroundSettingEnum"));

    // convience variables
    QString startupOption    = settings.value("preferences/startupOption",    "run").toString();
    QString backgroundOption = settings.value("preferences/backgroundOption", "wallpaper").toString();
    QString soundFileName    = settings.value("preferences/soundFileName").toString();
    bool    customSound      = settings.value("preferences/customSound", false).toBool();

    // load settings to ui
    ui->startupOptionsGroupBox->setChecked(settings.value("preferences/startup", false).toBool());
    ui->startupOptionsGroup->button(startupMetaEnum.keyToValue(startupOption.toLocal8Bit()))->setChecked(true);
    ui->backgroundSettingsCombo->setCurrentIndex(backgroundMetaEnum.keyToValue(backgroundOption.toLocal8Bit()));
    ui->soundNotificationGroupBox->setChecked(settings.value("preferences/playSound", false).toBool());
    ui->customSoundRadio->setChecked(customSound);
    Preferences::on_customSoundRadio_toggled(customSound);       // calling this sets the other button states appropriately
    ui->desktopNotificationCheckBox->setChecked(settings.value("preferences/desktopNotification", false).toBool());

    // set the browse sound button text
    if (!ui->browseSoundButton->isEnabled()) {
        ui->browseSoundButton->setText(tr("(None)"));
        soundFileName = DEFAULTSOUNDFILE;
    } else {
        ui->browseSoundButton->setText(soundFileName);
    }
}

/**
 * @brief
 *
 */
Preferences::~Preferences() { delete ui; }

/**
 * @brief
 *
 */
void Preferences::on_closeButton_clicked() { close(); }

/**
 * @brief
 *
 */
void Preferences::on_saveButton_clicked() {
    // setup the enums
    QMetaEnum startupMetaEnum = Preferences::staticMetaObject.enumerator(
                Preferences::staticMetaObject.indexOfEnumerator("startupEnum"));
    QMetaEnum backgroundMetaEnum = Preferences::staticMetaObject.enumerator(
                Preferences::staticMetaObject.indexOfEnumerator("backgroundSettingEnum"));

    // set startup options
    if (ui->startupOptionsGroupBox->isChecked()) {
        QString options;
        QString comment;
        QString filename;

        switch (ui->startupOptionsGroup->checkedId()) {
        case Preferences::once:
            options = "--once";
            comment = "Change desktop background once.";
            filename = "WallchOnBoot.desktop";
            break;
        case Preferences::liveEarth:
            options  = "--earth";
            comment  = "Enable Live Earth Wallpaper.";
            filename = "WallchLiveEarthOnBoot.desktop";
            break;
        case Preferences::run:
            options  = "--constant";
            comment  = "Start changing desktop background after a certain time.";
            filename = "WallachOnBootConstantApp.desktop";
            break;
        default:
            // should never reach this fall through:
            qDebug() << "Somehow startupOptionsGroup was checked, but one of the options wasn't checked, or it missed the enum";
            break;
        }

        QString command = QString("echo \"\n"
                                  "[Desktop Entry]\n"
                                  "Type=Application\n"
                                  "Name=Wallch\n"
                                  "Exec=/usr/bin/wallch %1\n"
                                  "Terminal=false\n"
                                  "Icon=wallch\n"
                                  "Comment=%2\n"
                                  "Categories=Utility;Application;\""
                                  "> ~/.config/autostart/%3")
                .arg(options).arg(comment).arg(filename);

        if (system(command.toLocal8Bit()))
            qDebug() << "Error creating new startup command: " << filename.toLocal8Bit();
    } else { // startup option not set
        QFile::remove("~/.config/autostart/WallchOnBoot.desktop");
        QFile::remove("~/.config/autostart/WallchLiveEarthOnBoot.desktop");
        QFile::remove("~/.config/autostart/WallchOnBootConstantApp.desktop");
    }

    // save settings
    settings.setValue("preferences/startup",             ui->startupOptionsGroupBox->isChecked());
    settings.setValue("preferences/startupOption",       startupMetaEnum.key(ui->startupOptionsGroup->checkedId()));
    settings.setValue("preferences/backgroundOption",    backgroundMetaEnum.key(ui->backgroundSettingsCombo->currentIndex()));
    settings.setValue("preferences/desktopNotification", ui->desktopNotificationCheckBox->isChecked());
    settings.setValue("preferences/playSound",           ui->soundNotificationGroupBox->isChecked());
    settings.setValue("preferences/customSound"  ,       ui->customSoundRadio->isChecked());
    settings.setValue("preferences/soundFileName",       ui->browseSoundButton->text());

    settings.sync();

//    // set background gconf settings
//    if (!gconf_client_set_string(gconfClient, "/desktop/gnome/background/picture_options",
//                                  type.toLatin1(), NULL)) {
//        QMessageBox::warning(this, tr("Error Changing Settings"), tr("Error changing gconf settings, check permissions on home foler and .gconf."));
//        qDebug() << "Error while trying to change style. Check .gconf permissions.\n";
//    }

    close();
}

/**
 * @brief
 *
 */
void Preferences::on_browseSoundButton_clicked() {
    // get file from user
    QString userFileName;
    userFileName = QFileDialog::getOpenFileName(this, tr("Choose Custom Sound"), QDir::homePath(), "*.wav *.ogg");

    if (userFileName == "") return; // user clicked cancel

    // open the sound
    if (!sound.OpenFromFile(userFileName.toStdString())) {
        QMessageBox::warning(this, tr("Bad Sound File"), tr("Unable to load sound file, inncorrect permissions or bad file."));
        qDebug() << "Unable to open sound file!";
        return;
    }

    // check the sounds duration
    if (sound.GetDuration() > 5)
        if (QMessageBox::question(this, tr("Long Alert Sound"),
                                 tr("This sound is longer then 5 secounds,\n are you sure you want to use this sound?"),
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::No)
                != QMessageBox::Yes)
            return;

    ui->browseSoundButton->setText(soundFileName);
    soundFileName = userFileName;
}

/**
 * @brief
 *
 */
void Preferences::on_testSoundButton_clicked() {
    // open the sound
    if (!sound.OpenFromFile(soundFileName.toStdString())) {
        QMessageBox::warning(this, tr("Bad Sound File"), tr("Unable to load sound file, inncorrect permissions or bad file."));
        qDebug() << "Unable to open sound file!";
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
void Preferences::on_resetPreferencesButton_clicked()
{
    // Warning Dialog, return if not given yes.
    if (QMessageBox::question(this, tr("Reset Preferences"),
                              tr("Are you sure you want to reset your Wallch preferences?"),
                              QMessageBox::Yes | QMessageBox::No, QMessageBox::No)
            != QMessageBox::Yes)
        return;

    ui->customSoundRadio->setChecked(false);
    ui->startupOptionsGroupBox->setChecked(false);
    ui->soundNotificationGroupBox->setChecked(false);
}

/**
 * @brief
 *
 * @param state
 */
void Preferences::on_customSoundRadio_toggled(bool state)
{
    ui->browseSoundButton->setEnabled(state);

    if (!state) {                                       // if the customSoundRadio is toggled off
        soundFileName = DEFAULTSOUNDFILE;
        ui->browseSoundButton->setText(tr("(None)"));
    }
}
