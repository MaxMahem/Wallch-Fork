/********************************************************************************
** Form generated from reading UI file 'statistics.ui'
**
** Created: Wed Aug 31 18:10:15 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICS_H
#define UI_STATISTICS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statistics
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *uptime;
    QLabel *launchedtimes;
    QLabel *images_n;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *reset;
    QPushButton *ok;

    void setupUi(QDialog *statistics)
    {
        if (statistics->objectName().isEmpty())
            statistics->setObjectName(QString::fromUtf8("statistics"));
        statistics->resize(392, 170);
        statistics->setMinimumSize(QSize(392, 170));
        statistics->setMaximumSize(QSize(392, 170));
        label = new QLabel(statistics);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 351, 31));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(statistics);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 261, 17));
        label_3 = new QLabel(statistics);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 75, 261, 17));
        label_4 = new QLabel(statistics);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 261, 17));
        uptime = new QLabel(statistics);
        uptime->setObjectName(QString::fromUtf8("uptime"));
        uptime->setGeometry(QRect(280, 50, 101, 17));
        uptime->setText(QString::fromUtf8("0"));
        launchedtimes = new QLabel(statistics);
        launchedtimes->setObjectName(QString::fromUtf8("launchedtimes"));
        launchedtimes->setGeometry(QRect(280, 75, 101, 17));
        launchedtimes->setText(QString::fromUtf8("0"));
        images_n = new QLabel(statistics);
        images_n->setObjectName(QString::fromUtf8("images_n"));
        images_n->setGeometry(QRect(280, 100, 101, 17));
        images_n->setText(QString::fromUtf8("0"));
        layoutWidget = new QWidget(statistics);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 130, 211, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        reset = new QPushButton(layoutWidget);
        reset->setObjectName(QString::fromUtf8("reset"));

        horizontalLayout->addWidget(reset);

        ok = new QPushButton(layoutWidget);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setDefault(true);

        horizontalLayout->addWidget(ok);

        QWidget::setTabOrder(reset, ok);

        retranslateUi(statistics);

        QMetaObject::connectSlotsByName(statistics);
    } // setupUi

    void retranslateUi(QDialog *statistics)
    {
        statistics->setWindowTitle(QApplication::translate("statistics", "Statistics", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("statistics", "Statistics", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("statistics", "Program's uptime:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("statistics", "Launched times of program:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("statistics", "Total number of changed wallpapers:", 0, QApplication::UnicodeUTF8));
        reset->setText(QApplication::translate("statistics", "&Reset", 0, QApplication::UnicodeUTF8));
        ok->setText(QApplication::translate("statistics", "&OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class statistics: public Ui_statistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICS_H
