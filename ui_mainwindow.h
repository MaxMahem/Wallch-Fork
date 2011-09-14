/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Sep 12 02:02:10 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Preferences;
    QAction *action_About;
    QAction *actionQuit_Ctrl_Q;
    QAction *action_Start;
    QAction *actionS_top;
    QAction *action_Pause;
    QAction *action_Next_Image;
    QAction *actionRemove_list;
    QAction *action_Load;
    QAction *actionAdd_single_images;
    QAction *actionAdd_Folder;
    QAction *actionAdd_a_Wallch_album;
    QAction *actionHistory;
    QAction *action_Previous_Image_Shift_Ctrl_B;
    QAction *actionExtras;
    QAction *save_as;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addButton;
    QPushButton *pushButton;
    QPushButton *addfolder;
    QPushButton *removeButton;
    QPushButton *removeallButton;
    QPushButton *sortButton;
    QProgressBar *time_for_next;
    QLabel *wallpaperPreviewLabel;
    QLabel *wallpaperCountLabel;
    QGridLayout *commandButtonGridLayout;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *startButton;
    QPushButton *stopButton;
    QGridLayout *gridLayout;
    QLabel *timerSliderLabel;
    QSlider *timerSlider;
    QGroupBox *wallpaperSourceGroupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *localSourceRadio;
    QRadioButton *webSourceRadio;
    QRadioButton *radioButton;
    QPushButton *randomButton;
    QTableView *itemView;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuAdd_Files;
    QMenu *menu_Edit;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QButtonGroup *localControlButtonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 500);
        MainWindow->setMinimumSize(QSize(1000, 500));
        MainWindow->setMaximumSize(QSize(2000, 1000));
        MainWindow->setWindowTitle(QString::fromUtf8("Wallch"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Pictures/wallpaper.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_Preferences = new QAction(MainWindow);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        action_Preferences->setIconVisibleInMenu(true);
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        actionQuit_Ctrl_Q = new QAction(MainWindow);
        actionQuit_Ctrl_Q->setObjectName(QString::fromUtf8("actionQuit_Ctrl_Q"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Pictures/Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit_Ctrl_Q->setIcon(icon1);
        actionQuit_Ctrl_Q->setIconVisibleInMenu(true);
        action_Start = new QAction(MainWindow);
        action_Start->setObjectName(QString::fromUtf8("action_Start"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Buttons/Pictures/Buttons/button_play_red.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Start->setIcon(icon2);
        action_Start->setIconVisibleInMenu(true);
        actionS_top = new QAction(MainWindow);
        actionS_top->setObjectName(QString::fromUtf8("actionS_top"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Buttons/Pictures/Buttons/button_stop_red.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionS_top->setIcon(icon3);
        actionS_top->setIconVisibleInMenu(true);
        action_Pause = new QAction(MainWindow);
        action_Pause->setObjectName(QString::fromUtf8("action_Pause"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Buttons/Pictures/Buttons/button_pause_red.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Pause->setIcon(icon4);
        action_Pause->setIconVisibleInMenu(true);
        action_Next_Image = new QAction(MainWindow);
        action_Next_Image->setObjectName(QString::fromUtf8("action_Next_Image"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Buttons/Pictures/Buttons/button_fastforward_red.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Next_Image->setIcon(icon5);
        action_Next_Image->setIconVisibleInMenu(true);
        actionRemove_list = new QAction(MainWindow);
        actionRemove_list->setObjectName(QString::fromUtf8("actionRemove_list"));
        action_Load = new QAction(MainWindow);
        action_Load->setObjectName(QString::fromUtf8("action_Load"));
        action_Load->setIconVisibleInMenu(true);
        actionAdd_single_images = new QAction(MainWindow);
        actionAdd_single_images->setObjectName(QString::fromUtf8("actionAdd_single_images"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/Pictures/picture_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_single_images->setIcon(icon6);
        actionAdd_single_images->setIconVisibleInMenu(true);
        actionAdd_Folder = new QAction(MainWindow);
        actionAdd_Folder->setObjectName(QString::fromUtf8("actionAdd_Folder"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/Pictures/folder-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Folder->setIcon(icon7);
        actionAdd_Folder->setIconVisibleInMenu(true);
        actionAdd_a_Wallch_album = new QAction(MainWindow);
        actionAdd_a_Wallch_album->setObjectName(QString::fromUtf8("actionAdd_a_Wallch_album"));
        actionHistory = new QAction(MainWindow);
        actionHistory->setObjectName(QString::fromUtf8("actionHistory"));
        actionHistory->setIconVisibleInMenu(true);
        action_Previous_Image_Shift_Ctrl_B = new QAction(MainWindow);
        action_Previous_Image_Shift_Ctrl_B->setObjectName(QString::fromUtf8("action_Previous_Image_Shift_Ctrl_B"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Buttons/Pictures/Buttons/button_fastbackward_red.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Previous_Image_Shift_Ctrl_B->setIcon(icon8);
        action_Previous_Image_Shift_Ctrl_B->setIconVisibleInMenu(true);
        actionExtras = new QAction(MainWindow);
        actionExtras->setObjectName(QString::fromUtf8("actionExtras"));
        actionExtras->setIconVisibleInMenu(true);
        save_as = new QAction(MainWindow);
        save_as->setObjectName(QString::fromUtf8("save_as"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        addButton = new QPushButton(centralWidget);
        localControlButtonGroup = new QButtonGroup(MainWindow);
        localControlButtonGroup->setObjectName(QString::fromUtf8("localControlButtonGroup"));
        localControlButtonGroup->addButton(addButton);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setFocusPolicy(Qt::NoFocus);
        addButton->setIconSize(QSize(20, 20));

        verticalLayout_2->addWidget(addButton);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFlat(false);

        verticalLayout_2->addWidget(pushButton);

        addfolder = new QPushButton(centralWidget);
        localControlButtonGroup->addButton(addfolder);
        addfolder->setObjectName(QString::fromUtf8("addfolder"));
        addfolder->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(addfolder);

        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setFocusPolicy(Qt::NoFocus);
        removeButton->setIconSize(QSize(20, 20));

        verticalLayout_2->addWidget(removeButton);

        removeallButton = new QPushButton(centralWidget);
        removeallButton->setObjectName(QString::fromUtf8("removeallButton"));
        removeallButton->setFocusPolicy(Qt::NoFocus);
        removeallButton->setIconSize(QSize(20, 20));

        verticalLayout_2->addWidget(removeallButton);

        sortButton = new QPushButton(centralWidget);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));

        verticalLayout_2->addWidget(sortButton);


        gridLayout_3->addLayout(verticalLayout_2, 0, 1, 1, 1);

        time_for_next = new QProgressBar(centralWidget);
        time_for_next->setObjectName(QString::fromUtf8("time_for_next"));
        time_for_next->setValue(0);

        gridLayout_3->addWidget(time_for_next, 1, 2, 1, 1);

        wallpaperPreviewLabel = new QLabel(centralWidget);
        wallpaperPreviewLabel->setObjectName(QString::fromUtf8("wallpaperPreviewLabel"));
        wallpaperPreviewLabel->setFrameShape(QFrame::WinPanel);
        wallpaperPreviewLabel->setScaledContents(true);

        gridLayout_3->addWidget(wallpaperPreviewLabel, 0, 2, 1, 1);

        wallpaperCountLabel = new QLabel(centralWidget);
        wallpaperCountLabel->setObjectName(QString::fromUtf8("wallpaperCountLabel"));
        wallpaperCountLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(wallpaperCountLabel, 1, 1, 1, 1);

        commandButtonGridLayout = new QGridLayout();
        commandButtonGridLayout->setSpacing(6);
        commandButtonGridLayout->setObjectName(QString::fromUtf8("commandButtonGridLayout"));
        previousButton = new QPushButton(centralWidget);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));
        previousButton->setFocusPolicy(Qt::NoFocus);
        previousButton->setIconSize(QSize(20, 20));
        previousButton->setAutoDefault(false);
        previousButton->setDefault(false);

        commandButtonGridLayout->addWidget(previousButton, 0, 0, 1, 1);

        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setFocusPolicy(Qt::NoFocus);
        nextButton->setIconSize(QSize(20, 20));
        nextButton->setAutoDefault(false);
        nextButton->setDefault(false);

        commandButtonGridLayout->addWidget(nextButton, 0, 1, 1, 1);

        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setFocusPolicy(Qt::NoFocus);
        startButton->setIconSize(QSize(20, 20));
        startButton->setAutoDefault(false);
        startButton->setDefault(false);

        commandButtonGridLayout->addWidget(startButton, 1, 0, 1, 1);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setFocusPolicy(Qt::NoFocus);
        stopButton->setIconSize(QSize(20, 20));
        stopButton->setAutoDefault(false);
        stopButton->setDefault(false);

        commandButtonGridLayout->addWidget(stopButton, 1, 1, 1, 1);


        gridLayout_3->addLayout(commandButtonGridLayout, 2, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        timerSliderLabel = new QLabel(centralWidget);
        timerSliderLabel->setObjectName(QString::fromUtf8("timerSliderLabel"));
        timerSliderLabel->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(timerSliderLabel, 0, 0, 1, 1);

        timerSlider = new QSlider(centralWidget);
        timerSlider->setObjectName(QString::fromUtf8("timerSlider"));
        timerSlider->setFocusPolicy(Qt::NoFocus);
        timerSlider->setStyleSheet(QString::fromUtf8(""));
        timerSlider->setMinimum(0);
        timerSlider->setMaximum(10);
        timerSlider->setPageStep(1);
        timerSlider->setValue(1);
        timerSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(timerSlider, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        wallpaperSourceGroupBox = new QGroupBox(centralWidget);
        wallpaperSourceGroupBox->setObjectName(QString::fromUtf8("wallpaperSourceGroupBox"));
        horizontalLayout = new QHBoxLayout(wallpaperSourceGroupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        localSourceRadio = new QRadioButton(wallpaperSourceGroupBox);
        localSourceRadio->setObjectName(QString::fromUtf8("localSourceRadio"));
        localSourceRadio->setChecked(true);

        horizontalLayout->addWidget(localSourceRadio);

        webSourceRadio = new QRadioButton(wallpaperSourceGroupBox);
        webSourceRadio->setObjectName(QString::fromUtf8("webSourceRadio"));

        horizontalLayout->addWidget(webSourceRadio);

        radioButton = new QRadioButton(wallpaperSourceGroupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);


        gridLayout_3->addWidget(wallpaperSourceGroupBox, 2, 0, 1, 1);

        randomButton = new QPushButton(centralWidget);
        randomButton->setObjectName(QString::fromUtf8("randomButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(randomButton->sizePolicy().hasHeightForWidth());
        randomButton->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(randomButton, 2, 1, 1, 1);

        itemView = new QTableView(centralWidget);
        itemView->setObjectName(QString::fromUtf8("itemView"));
        itemView->setContextMenuPolicy(Qt::CustomContextMenu);
        itemView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        itemView->setSelectionMode(QAbstractItemView::SingleSelection);
        itemView->setSelectionBehavior(QAbstractItemView::SelectRows);
        itemView->setSortingEnabled(true);
        itemView->setCornerButtonEnabled(false);
        itemView->horizontalHeader()->setCascadingSectionResizes(true);
        itemView->horizontalHeader()->setStretchLastSection(true);
        itemView->verticalHeader()->setVisible(false);

        gridLayout_3->addWidget(itemView, 0, 0, 1, 1);

        gridLayout_3->setColumnStretch(0, 5);
        gridLayout_3->setColumnStretch(2, 5);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 25));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuAdd_Files = new QMenu(menu_File);
        menuAdd_Files->setObjectName(QString::fromUtf8("menuAdd_Files"));
        menuAdd_Files->setTearOffEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/Pictures/add2.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAdd_Files->setIcon(icon9);
        menuAdd_Files->setSeparatorsCollapsible(false);
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menu_File->addAction(menuAdd_Files->menuAction());
        menu_File->addAction(save_as);
        menu_File->addSeparator();
        menu_File->addAction(action_Start);
        menu_File->addAction(actionS_top);
        menu_File->addAction(action_Next_Image);
        menu_File->addAction(action_Previous_Image_Shift_Ctrl_B);
        menu_File->addSeparator();
        menu_File->addAction(actionQuit_Ctrl_Q);
        menuAdd_Files->addAction(action_Load);
        menuAdd_Files->addAction(actionAdd_single_images);
        menuAdd_Files->addAction(actionAdd_Folder);
        menu_Edit->addAction(action_Preferences);
        menuHelp->addSeparator();
        menuHelp->addSeparator();
        menuHelp->addAction(action_About);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        action_Preferences->setText(QApplication::translate("MainWindow", "&Preferences          Ctrl+P", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        actionQuit_Ctrl_Q->setText(QApplication::translate("MainWindow", "Quit                                    Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Start->setText(QApplication::translate("MainWindow", "&Start                                    Shift+Ctrl+S", 0, QApplication::UnicodeUTF8));
        action_Start->setIconText(QApplication::translate("MainWindow", "&Start                        Shift+Ctrl+S", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Start->setToolTip(QApplication::translate("MainWindow", "&Start                        Shift+Ctrl+S", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionS_top->setText(QApplication::translate("MainWindow", "S&top                                    Shift+Ctrl+O", 0, QApplication::UnicodeUTF8));
        action_Pause->setText(QApplication::translate("MainWindow", "&Pause                                 Shift+Ctrl+P", 0, QApplication::UnicodeUTF8));
        action_Next_Image->setText(QApplication::translate("MainWindow", "&Next Image                     Shift+Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionRemove_list->setText(QApplication::translate("MainWindow", "Remove non-existent files", 0, QApplication::UnicodeUTF8));
        action_Load->setText(QApplication::translate("MainWindow", "Add a Wallch Album         Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionAdd_single_images->setText(QApplication::translate("MainWindow", "Add single images             Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionAdd_Folder->setText(QApplication::translate("MainWindow", "Add Folder                             Ctrl+F", 0, QApplication::UnicodeUTF8));
        actionAdd_a_Wallch_album->setText(QApplication::translate("MainWindow", "Add a Wallch album", 0, QApplication::UnicodeUTF8));
        actionHistory->setText(QApplication::translate("MainWindow", "&History                    Ctrl+H", 0, QApplication::UnicodeUTF8));
        action_Previous_Image_Shift_Ctrl_B->setText(QApplication::translate("MainWindow", "&Previous Image            Shift+Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionExtras->setText(QApplication::translate("MainWindow", "&Extras                      Ctrl+E", 0, QApplication::UnicodeUTF8));
        save_as->setText(QApplication::translate("MainWindow", "Save images as a wallch album", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        addButton->setStatusTip(QApplication::translate("MainWindow", "Add images", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        addButton->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Add Site", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addfolder->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        addfolder->setStatusTip(QApplication::translate("MainWindow", "Add all images from a folder and its subfolders", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        addfolder->setText(QApplication::translate("MainWindow", "Add Folder", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        removeButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        removeButton->setStatusTip(QApplication::translate("MainWindow", "Remove selected image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        removeButton->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        removeallButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        removeallButton->setStatusTip(QApplication::translate("MainWindow", "Remove all images from list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        removeallButton->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        sortButton->setText(QApplication::translate("MainWindow", "Sort", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        time_for_next->setStatusTip(QApplication::translate("MainWindow", "Estimated time for next wallpaper", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        time_for_next->setFormat(QString());
        wallpaperPreviewLabel->setText(QString());
        wallpaperCountLabel->setText(QString());
#ifndef QT_NO_STATUSTIP
        previousButton->setStatusTip(QApplication::translate("MainWindow", "Proceed to previous image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        previousButton->setText(QApplication::translate("MainWindow", "&Previous", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        nextButton->setStatusTip(QApplication::translate("MainWindow", "Proceed to next image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        nextButton->setText(QApplication::translate("MainWindow", "&Next", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        startButton->setStatusTip(QApplication::translate("MainWindow", "Start/Pause the wallpaper changing module", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        startButton->setText(QApplication::translate("MainWindow", "&Start", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        stopButton->setStatusTip(QApplication::translate("MainWindow", "Stop the wallpaper changing module", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        stopButton->setText(QApplication::translate("MainWindow", "St&op", 0, QApplication::UnicodeUTF8));
        timerSliderLabel->setText(QApplication::translate("MainWindow", "Timer Slider:", 0, QApplication::UnicodeUTF8));
        wallpaperSourceGroupBox->setTitle(QApplication::translate("MainWindow", "Wallpaper Source", 0, QApplication::UnicodeUTF8));
        localSourceRadio->setText(QApplication::translate("MainWindow", "Local", 0, QApplication::UnicodeUTF8));
        webSourceRadio->setText(QApplication::translate("MainWindow", "Web", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "RadioButton", 0, QApplication::UnicodeUTF8));
        randomButton->setText(QApplication::translate("MainWindow", "&Random", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuAdd_Files->setTitle(QApplication::translate("MainWindow", "Add Files", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
