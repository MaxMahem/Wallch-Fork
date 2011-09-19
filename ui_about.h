/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created: Sat Sep 17 05:21:08 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QPushButton *closeButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *page_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QTextBrowser *textBrowser_2;
    QWidget *page_3;
    QPlainTextEdit *plain;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QString::fromUtf8("about"));
        about->resize(371, 294);
        about->setMinimumSize(QSize(371, 294));
        about->setMaximumSize(QSize(371, 294));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Pictures/wallpaper.png"), QSize(), QIcon::Normal, QIcon::Off);
        about->setWindowIcon(icon);
        closeButton = new QPushButton(about);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(280, 250, 81, 31));
        closeButton->setAutoDefault(false);
        pushButton_2 = new QPushButton(about);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 250, 91, 31));
        pushButton_2->setCheckable(false);
        pushButton_2->setAutoDefault(false);
        pushButton_3 = new QPushButton(about);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 250, 81, 31));
        pushButton_3->setCheckable(false);
        pushButton_3->setAutoDefault(false);
        pushButton = new QPushButton(about);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 250, 71, 31));
        pushButton->setCheckable(false);
        pushButton->setChecked(false);
        pushButton->setAutoDefault(false);
        stackedWidget = new QStackedWidget(about);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 371, 251));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 40, 71, 71));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/Pictures/wallch.png")));
        label->setScaledContents(true);
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 200, 371, 20));
        QFont font;
        font.setPointSize(8);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 138, 371, 41));
        label_3->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 106, 371, 41));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setText(QString::fromUtf8("Wallch 2.0"));
        label_2->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 220, 371, 20));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QString::fromUtf8("http://wallch.t35.com/"));
#endif // QT_NO_TOOLTIP
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setOpenExternalLinks(true);
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 180, 151, 20));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        tabWidget = new QTabWidget(page_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 331, 201));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 331, 171));
        textBrowser->setOpenExternalLinks(true);
        textBrowser->setOpenLinks(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        textBrowser_2 = new QTextBrowser(tab_2);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(0, 0, 331, 171));
        textBrowser_2->setOpenExternalLinks(true);
        tabWidget->addTab(tab_2, QString());
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        plain = new QPlainTextEdit(page_3);
        plain->setObjectName(QString::fromUtf8("plain"));
        plain->setGeometry(QRect(13, 17, 341, 221));
        plain->setPlainText(QString::fromUtf8("Wallch (Wallpaper Changer) is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.\n"
"\n"
"Wallch (Wallpaper Changer) is distributed in the hope that it will be useful,\n"
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"GNU General Public License for more details.\n"
"\n"
"You should have received a copy of the GNU General Public License\n"
"along with Wallch (Wallpaper Changer); if not, write to the Free Software Foundation, Inc.,\n"
"51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA\n"
"\n"
"For further information you can also visit http://www.gnu.org/licenses/gpl.html"));
        stackedWidget->addWidget(page_3);

        retranslateUi(about);

        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QApplication::translate("about", "About Wallch", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("about", "Close", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("about", "Credits", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("about", "Licence", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("about", "About", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_4->setText(QString());
        label_3->setText(QApplication::translate("about", "Wallch allows your desktop\n"
"wallpaper to change automatically ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_6->setText(QApplication::translate("about", "(GNOME 2 VERSION)", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("about", "Written by", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("about", "Translated by", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
