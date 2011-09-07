/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created: Thu Sep 1 03:16:37 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_history
{
public:
    QListWidget *info;
    QTreeWidget *treeWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *closeButton;

    void setupUi(QDialog *history)
    {
        if (history->objectName().isEmpty())
            history->setObjectName(QString::fromUtf8("history"));
        history->resize(714, 479);
        info = new QListWidget(history);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(250, 10, 461, 421));
        info->setFocusPolicy(Qt::NoFocus);
        treeWidget = new QTreeWidget(history);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(5, 10, 231, 421));
        treeWidget->setMaximumSize(QSize(231, 16777215));
        treeWidget->setFocusPolicy(Qt::NoFocus);
        treeWidget->setFrameShape(QFrame::StyledPanel);
        treeWidget->setFrameShadow(QFrame::Sunken);
        treeWidget->setAnimated(true);
        pushButton = new QPushButton(history);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 442, 151, 27));
        pushButton_2 = new QPushButton(history);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(450, 442, 131, 27));
        closeButton = new QPushButton(history);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(590, 442, 111, 27));
        closeButton->setDefault(true);

        retranslateUi(history);

        QMetaObject::connectSlotsByName(history);
    } // setupUi

    void retranslateUi(QDialog *history)
    {
        history->setWindowTitle(QApplication::translate("history", "History", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("history", "&Remove History", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("history", "&Update List", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("history", "&Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class history: public Ui_history {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
