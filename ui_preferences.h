/********************************************************************************
** Form generated from reading UI file 'preferences.ui'
**
** Created: Wed Sep 7 00:41:12 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Preferences
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *startupOptionsGroupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *startupRunRadio;
    QRadioButton *startupChangeOnceRadio;
    QRadioButton *startupLiveEarthRadio;
    QFormLayout *comboFormLayout;
    QLabel *backgroundSettingsLabel;
    QComboBox *backgroundSettingsCombo;
    QCheckBox *desktopNotificationCheckBox;
    QHBoxLayout *horizontalLayout;
    QLabel *speakerLLabel;
    QGroupBox *soundNotificationGroupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *standardSoundRadio;
    QRadioButton *customSoundRadio;
    QPushButton *browseSoundButton;
    QPushButton *testSoundButton;
    QLabel *speakerRLabel;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *checkBox;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QRadioButton *liveEarthRadioRectangular;
    QLabel *liveEarthRectangularLabel;
    QLabel *liveEarthHemisphereLabel;
    QRadioButton *liveEarthRadioHemisphere;
    QHBoxLayout *controlHorizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *resetPreferencesButton;
    QPushButton *closeButton;
    QPushButton *saveButton;
    QButtonGroup *customSoundOptionsGroup;
    QButtonGroup *startupOptionsGroup;

    void setupUi(QDialog *Preferences)
    {
        if (Preferences->objectName().isEmpty())
            Preferences->setObjectName(QString::fromUtf8("Preferences"));
        Preferences->resize(450, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Preferences->sizePolicy().hasHeightForWidth());
        Preferences->setSizePolicy(sizePolicy);
        Preferences->setMinimumSize(QSize(450, 500));
        Preferences->setMaximumSize(QSize(1000, 1000));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Pictures/wallpaper.png"), QSize(), QIcon::Normal, QIcon::Off);
        Preferences->setWindowIcon(icon);
        Preferences->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(Preferences);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(Preferences);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        startupOptionsGroupBox = new QGroupBox(tab);
        startupOptionsGroupBox->setObjectName(QString::fromUtf8("startupOptionsGroupBox"));
        startupOptionsGroupBox->setFlat(false);
        startupOptionsGroupBox->setCheckable(true);
        startupOptionsGroupBox->setChecked(true);
        verticalLayout_3 = new QVBoxLayout(startupOptionsGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 9);
        startupRunRadio = new QRadioButton(startupOptionsGroupBox);
        startupOptionsGroup = new QButtonGroup(Preferences);
        startupOptionsGroup->setObjectName(QString::fromUtf8("startupOptionsGroup"));
        startupOptionsGroup->addButton(startupRunRadio);
        startupRunRadio->setObjectName(QString::fromUtf8("startupRunRadio"));
        startupRunRadio->setFocusPolicy(Qt::NoFocus);
        startupRunRadio->setChecked(true);
        startupRunRadio->setAutoExclusive(true);

        verticalLayout_3->addWidget(startupRunRadio);

        startupChangeOnceRadio = new QRadioButton(startupOptionsGroupBox);
        startupOptionsGroup->addButton(startupChangeOnceRadio);
        startupChangeOnceRadio->setObjectName(QString::fromUtf8("startupChangeOnceRadio"));
        startupChangeOnceRadio->setFocusPolicy(Qt::NoFocus);
        startupChangeOnceRadio->setChecked(false);

        verticalLayout_3->addWidget(startupChangeOnceRadio);

        startupLiveEarthRadio = new QRadioButton(startupOptionsGroupBox);
        startupOptionsGroup->addButton(startupLiveEarthRadio);
        startupLiveEarthRadio->setObjectName(QString::fromUtf8("startupLiveEarthRadio"));
        startupLiveEarthRadio->setEnabled(true);
        startupLiveEarthRadio->setFocusPolicy(Qt::NoFocus);
        startupLiveEarthRadio->setCheckable(true);
        startupLiveEarthRadio->setChecked(false);

        verticalLayout_3->addWidget(startupLiveEarthRadio);


        verticalLayout_5->addWidget(startupOptionsGroupBox);

        comboFormLayout = new QFormLayout();
        comboFormLayout->setObjectName(QString::fromUtf8("comboFormLayout"));
        comboFormLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        comboFormLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comboFormLayout->setContentsMargins(6, 0, 6, 0);
        backgroundSettingsLabel = new QLabel(tab);
        backgroundSettingsLabel->setObjectName(QString::fromUtf8("backgroundSettingsLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        backgroundSettingsLabel->setFont(font);

        comboFormLayout->setWidget(0, QFormLayout::LabelRole, backgroundSettingsLabel);

        backgroundSettingsCombo = new QComboBox(tab);
        backgroundSettingsCombo->setObjectName(QString::fromUtf8("backgroundSettingsCombo"));
        backgroundSettingsCombo->setFocusPolicy(Qt::NoFocus);

        comboFormLayout->setWidget(0, QFormLayout::FieldRole, backgroundSettingsCombo);

        desktopNotificationCheckBox = new QCheckBox(tab);
        desktopNotificationCheckBox->setObjectName(QString::fromUtf8("desktopNotificationCheckBox"));
        desktopNotificationCheckBox->setFocusPolicy(Qt::NoFocus);
        desktopNotificationCheckBox->setChecked(true);

        comboFormLayout->setWidget(1, QFormLayout::SpanningRole, desktopNotificationCheckBox);


        verticalLayout_5->addLayout(comboFormLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 10, -1, -1);
        speakerLLabel = new QLabel(tab);
        speakerLLabel->setObjectName(QString::fromUtf8("speakerLLabel"));
        speakerLLabel->setMinimumSize(QSize(96, 128));
        speakerLLabel->setMaximumSize(QSize(256, 256));
        speakerLLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/Pictures/speakerL.png")));
        speakerLLabel->setScaledContents(true);
        speakerLLabel->setMargin(5);

        horizontalLayout->addWidget(speakerLLabel);

        soundNotificationGroupBox = new QGroupBox(tab);
        soundNotificationGroupBox->setObjectName(QString::fromUtf8("soundNotificationGroupBox"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        soundNotificationGroupBox->setFont(font1);
        soundNotificationGroupBox->setAutoFillBackground(false);
        soundNotificationGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        soundNotificationGroupBox->setFlat(true);
        soundNotificationGroupBox->setCheckable(true);
        soundNotificationGroupBox->setChecked(false);
        verticalLayout_2 = new QVBoxLayout(soundNotificationGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 9, 0, 9);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 0, -1, -1);
        standardSoundRadio = new QRadioButton(soundNotificationGroupBox);
        customSoundOptionsGroup = new QButtonGroup(Preferences);
        customSoundOptionsGroup->setObjectName(QString::fromUtf8("customSoundOptionsGroup"));
        customSoundOptionsGroup->addButton(standardSoundRadio);
        standardSoundRadio->setObjectName(QString::fromUtf8("standardSoundRadio"));
        standardSoundRadio->setChecked(true);

        verticalLayout_4->addWidget(standardSoundRadio);

        customSoundRadio = new QRadioButton(soundNotificationGroupBox);
        customSoundOptionsGroup->addButton(customSoundRadio);
        customSoundRadio->setObjectName(QString::fromUtf8("customSoundRadio"));
        customSoundRadio->setFocusPolicy(Qt::NoFocus);
        customSoundRadio->setChecked(false);

        verticalLayout_4->addWidget(customSoundRadio);


        verticalLayout_2->addLayout(verticalLayout_4);

        browseSoundButton = new QPushButton(soundNotificationGroupBox);
        browseSoundButton->setObjectName(QString::fromUtf8("browseSoundButton"));
        browseSoundButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Pictures/audio-x-generic.png"), QSize(), QIcon::Normal, QIcon::Off);
        browseSoundButton->setIcon(icon1);
        browseSoundButton->setIconSize(QSize(20, 20));
        browseSoundButton->setAutoDefault(false);

        verticalLayout_2->addWidget(browseSoundButton);

        testSoundButton = new QPushButton(soundNotificationGroupBox);
        testSoundButton->setObjectName(QString::fromUtf8("testSoundButton"));

        verticalLayout_2->addWidget(testSoundButton);


        horizontalLayout->addWidget(soundNotificationGroupBox);

        speakerRLabel = new QLabel(tab);
        speakerRLabel->setObjectName(QString::fromUtf8("speakerRLabel"));
        speakerRLabel->setMinimumSize(QSize(96, 128));
        speakerRLabel->setMaximumSize(QSize(256, 256));
        speakerRLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/Pictures/speakerR.png")));
        speakerRLabel->setScaledContents(true);
        speakerRLabel->setMargin(5);

        horizontalLayout->addWidget(speakerRLabel);


        verticalLayout_5->addLayout(horizontalLayout);

        tabWidget->addTab(tab, QString());
        startupOptionsGroupBox->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_6 = new QVBoxLayout(tab_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_6->addWidget(checkBox);

        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setCheckable(true);
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        liveEarthRadioRectangular = new QRadioButton(groupBox);
        liveEarthRadioRectangular->setObjectName(QString::fromUtf8("liveEarthRadioRectangular"));
        liveEarthRadioRectangular->setChecked(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, liveEarthRadioRectangular);

        liveEarthRectangularLabel = new QLabel(groupBox);
        liveEarthRectangularLabel->setObjectName(QString::fromUtf8("liveEarthRectangularLabel"));
        liveEarthRectangularLabel->setMinimumSize(QSize(200, 100));
        liveEarthRectangularLabel->setMaximumSize(QSize(400, 100));
        liveEarthRectangularLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/Pictures/world_sunlight_map_rectangular_small.jpg")));
        liveEarthRectangularLabel->setScaledContents(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, liveEarthRectangularLabel);

        liveEarthHemisphereLabel = new QLabel(groupBox);
        liveEarthHemisphereLabel->setObjectName(QString::fromUtf8("liveEarthHemisphereLabel"));
        liveEarthHemisphereLabel->setMinimumSize(QSize(200, 100));
        liveEarthHemisphereLabel->setMaximumSize(QSize(400, 100));
        liveEarthHemisphereLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/Pictures/world_sunlight_map_hemisphere_small.jpg")));
        liveEarthHemisphereLabel->setScaledContents(false);
        liveEarthHemisphereLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, liveEarthHemisphereLabel);

        liveEarthRadioHemisphere = new QRadioButton(groupBox);
        liveEarthRadioHemisphere->setObjectName(QString::fromUtf8("liveEarthRadioHemisphere"));

        formLayout->setWidget(1, QFormLayout::LabelRole, liveEarthRadioHemisphere);


        verticalLayout_6->addWidget(groupBox);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        controlHorizontalLayout = new QHBoxLayout();
        controlHorizontalLayout->setObjectName(QString::fromUtf8("controlHorizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        controlHorizontalLayout->addItem(horizontalSpacer);

        resetPreferencesButton = new QPushButton(Preferences);
        resetPreferencesButton->setObjectName(QString::fromUtf8("resetPreferencesButton"));
        resetPreferencesButton->setAutoDefault(true);

        controlHorizontalLayout->addWidget(resetPreferencesButton);

        closeButton = new QPushButton(Preferences);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setAutoDefault(true);

        controlHorizontalLayout->addWidget(closeButton);

        saveButton = new QPushButton(Preferences);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setAutoDefault(true);
        saveButton->setDefault(true);

        controlHorizontalLayout->addWidget(saveButton);


        verticalLayout->addLayout(controlHorizontalLayout);

#ifndef QT_NO_SHORTCUT
        backgroundSettingsLabel->setBuddy(backgroundSettingsCombo);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(closeButton, saveButton);
        QWidget::setTabOrder(saveButton, tabWidget);
        QWidget::setTabOrder(tabWidget, startupOptionsGroupBox);
        QWidget::setTabOrder(startupOptionsGroupBox, soundNotificationGroupBox);
        QWidget::setTabOrder(soundNotificationGroupBox, standardSoundRadio);
        QWidget::setTabOrder(standardSoundRadio, testSoundButton);
        QWidget::setTabOrder(testSoundButton, resetPreferencesButton);
        QWidget::setTabOrder(resetPreferencesButton, checkBox);
        QWidget::setTabOrder(checkBox, groupBox);
        QWidget::setTabOrder(groupBox, liveEarthRadioRectangular);
        QWidget::setTabOrder(liveEarthRadioRectangular, liveEarthRadioHemisphere);

        retranslateUi(Preferences);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Preferences);
    } // setupUi

    void retranslateUi(QDialog *Preferences)
    {
        Preferences->setWindowTitle(QApplication::translate("Preferences", "Preferences", 0, QApplication::UnicodeUTF8));
        startupOptionsGroupBox->setTitle(QApplication::translate("Preferences", "Launch on Startup", 0, QApplication::UnicodeUTF8));
        startupRunRadio->setText(QApplication::translate("Preferences", "Start Changing Desktop Wallpapers", 0, QApplication::UnicodeUTF8));
        startupChangeOnceRadio->setText(QApplication::translate("Preferences", "Change Wallpaper Once", 0, QApplication::UnicodeUTF8));
        startupLiveEarthRadio->setText(QApplication::translate("Preferences", "Start Live Earth Wallpaper", 0, QApplication::UnicodeUTF8));
        backgroundSettingsLabel->setText(QApplication::translate("Preferences", "Background Settings:", 0, QApplication::UnicodeUTF8));
        backgroundSettingsCombo->clear();
        backgroundSettingsCombo->insertItems(0, QStringList()
         << QApplication::translate("Preferences", "Tile", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Preferences", "Zoom", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Preferences", "Center", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Preferences", "Scale", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Preferences", "Stretch", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Preferences", "Span", 0, QApplication::UnicodeUTF8)
        );
        desktopNotificationCheckBox->setText(QApplication::translate("Preferences", "Desktop Notification", 0, QApplication::UnicodeUTF8));
        speakerLLabel->setText(QString());
        soundNotificationGroupBox->setTitle(QApplication::translate("Preferences", "Audiable Notification", 0, QApplication::UnicodeUTF8));
        standardSoundRadio->setText(QApplication::translate("Preferences", "Standard Sound", 0, QApplication::UnicodeUTF8));
        customSoundRadio->setText(QApplication::translate("Preferences", "Custom Sound", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        browseSoundButton->setToolTip(QApplication::translate("Preferences", "Click to select your own sound", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        browseSoundButton->setText(QApplication::translate("Preferences", "(None)", 0, QApplication::UnicodeUTF8));
        testSoundButton->setText(QApplication::translate("Preferences", "Test Sound", 0, QApplication::UnicodeUTF8));
        speakerRLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Preferences", "Notification", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Preferences", "CheckBox", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Preferences", "GroupBox", 0, QApplication::UnicodeUTF8));
        liveEarthRadioRectangular->setText(QApplication::translate("Preferences", "&Rectangular", 0, QApplication::UnicodeUTF8));
        liveEarthRectangularLabel->setText(QString());
        liveEarthHemisphereLabel->setText(QString());
        liveEarthRadioHemisphere->setText(QApplication::translate("Preferences", "&Hemisphere", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Preferences", "Source", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        resetPreferencesButton->setToolTip(QApplication::translate("Preferences", "Reset preferences to the default onces", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        resetPreferencesButton->setText(QApplication::translate("Preferences", "&Reset", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("Preferences", "&Cancel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("Preferences", "Save and close the dialog", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QApplication::translate("Preferences", "&Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Preferences: public Ui_Preferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H
