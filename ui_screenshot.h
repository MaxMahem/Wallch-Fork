/********************************************************************************
** Form generated from reading UI file 'screenshot.ui'
**
** Created: Wed Aug 31 18:10:15 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENSHOT_H
#define UI_SCREENSHOT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screenshot
{
public:
    QCheckBox *hideThisWindowCheckBox;
    QLabel *screenshotLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *newScreenshotButton;
    QPushButton *saveScreenshot;
    QPushButton *QuitButton;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *delaySpinBox;
    QCheckBox *hideMainWindow;

    void setupUi(QDialog *screenshot)
    {
        if (screenshot->objectName().isEmpty())
            screenshot->setObjectName(QString::fromUtf8("screenshot"));
        screenshot->resize(393, 349);
        screenshot->setMinimumSize(QSize(393, 349));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Pictures/wallpaper.png"), QSize(), QIcon::Normal, QIcon::Off);
        screenshot->setWindowIcon(icon);
        hideThisWindowCheckBox = new QCheckBox(screenshot);
        hideThisWindowCheckBox->setObjectName(QString::fromUtf8("hideThisWindowCheckBox"));
        hideThisWindowCheckBox->setGeometry(QRect(30, 245, 221, 22));
        hideThisWindowCheckBox->setFocusPolicy(Qt::NoFocus);
        hideThisWindowCheckBox->setChecked(true);
        screenshotLabel = new QLabel(screenshot);
        screenshotLabel->setObjectName(QString::fromUtf8("screenshotLabel"));
        screenshotLabel->setGeometry(QRect(70, 20, 251, 161));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(screenshotLabel->sizePolicy().hasHeightForWidth());
        screenshotLabel->setSizePolicy(sizePolicy);
        screenshotLabel->setMinimumSize(QSize(251, 161));
        screenshotLabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(screenshot);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 300, 354, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        newScreenshotButton = new QPushButton(layoutWidget);
        newScreenshotButton->setObjectName(QString::fromUtf8("newScreenshotButton"));

        horizontalLayout_2->addWidget(newScreenshotButton);

        saveScreenshot = new QPushButton(layoutWidget);
        saveScreenshot->setObjectName(QString::fromUtf8("saveScreenshot"));

        horizontalLayout_2->addWidget(saveScreenshot);

        QuitButton = new QPushButton(layoutWidget);
        QuitButton->setObjectName(QString::fromUtf8("QuitButton"));

        horizontalLayout_2->addWidget(QuitButton);

        layoutWidget_2 = new QWidget(screenshot);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 210, 321, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        delaySpinBox = new QSpinBox(layoutWidget_2);
        delaySpinBox->setObjectName(QString::fromUtf8("delaySpinBox"));
        delaySpinBox->setSuffix(QString::fromUtf8(" s"));
        delaySpinBox->setMaximum(60);

        horizontalLayout->addWidget(delaySpinBox);

        hideMainWindow = new QCheckBox(screenshot);
        hideMainWindow->setObjectName(QString::fromUtf8("hideMainWindow"));
        hideMainWindow->setGeometry(QRect(30, 270, 241, 22));
        hideMainWindow->setMinimumSize(QSize(241, 0));
        hideMainWindow->setFocusPolicy(Qt::NoFocus);
        hideMainWindow->setChecked(true);

        retranslateUi(screenshot);

        QMetaObject::connectSlotsByName(screenshot);
    } // setupUi

    void retranslateUi(QDialog *screenshot)
    {
        screenshot->setWindowTitle(QApplication::translate("screenshot", "Take Screenshot", 0, QApplication::UnicodeUTF8));
        hideThisWindowCheckBox->setText(QApplication::translate("screenshot", "Hide This Window", 0, QApplication::UnicodeUTF8));
        screenshotLabel->setText(QString());
        newScreenshotButton->setText(QApplication::translate("screenshot", "New Screenshot", 0, QApplication::UnicodeUTF8));
        saveScreenshot->setText(QApplication::translate("screenshot", "Save Screenshot", 0, QApplication::UnicodeUTF8));
        QuitButton->setText(QApplication::translate("screenshot", "Quit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("screenshot", "Screenshot Delay:", 0, QApplication::UnicodeUTF8));
        hideMainWindow->setText(QApplication::translate("screenshot", "Hide Wallch's Main Window", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class screenshot: public Ui_screenshot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSHOT_H
