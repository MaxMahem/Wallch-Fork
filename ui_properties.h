/********************************************************************************
** Form generated from reading UI file 'properties.ui'
**
** Created: Wed Sep 7 00:39:31 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIES_H
#define UI_PROPERTIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_properties
{
public:
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *image_name;
    QLabel *label_4;
    QLabel *image_size;
    QLabel *label_7;
    QLabel *image_width;
    QLabel *label_6;
    QLabel *image_height;
    QLabel *label_3;
    QLineEdit *image_type;
    QLabel *label_5;
    QLineEdit *image_location;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *properties)
    {
        if (properties->objectName().isEmpty())
            properties->setObjectName(QString::fromUtf8("properties"));
        properties->resize(356, 325);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Pictures/wallpaper.png"), QSize(), QIcon::Normal, QIcon::Off);
        properties->setWindowIcon(icon);
        formLayout = new QFormLayout(properties);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(properties);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        image_name = new QLabel(properties);
        image_name->setObjectName(QString::fromUtf8("image_name"));
        image_name->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout->setWidget(2, QFormLayout::FieldRole, image_name);

        label_4 = new QLabel(properties);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        image_size = new QLabel(properties);
        image_size->setObjectName(QString::fromUtf8("image_size"));

        formLayout->setWidget(3, QFormLayout::FieldRole, image_size);

        label_7 = new QLabel(properties);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        image_width = new QLabel(properties);
        image_width->setObjectName(QString::fromUtf8("image_width"));

        formLayout->setWidget(4, QFormLayout::FieldRole, image_width);

        label_6 = new QLabel(properties);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        image_height = new QLabel(properties);
        image_height->setObjectName(QString::fromUtf8("image_height"));

        formLayout->setWidget(5, QFormLayout::FieldRole, image_height);

        label_3 = new QLabel(properties);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_3);

        image_type = new QLineEdit(properties);
        image_type->setObjectName(QString::fromUtf8("image_type"));
        image_type->setReadOnly(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, image_type);

        label_5 = new QLabel(properties);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_5);

        image_location = new QLineEdit(properties);
        image_location->setObjectName(QString::fromUtf8("image_location"));
        image_location->setReadOnly(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, image_location);

        pushButton = new QPushButton(properties);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setDefault(true);

        formLayout->setWidget(8, QFormLayout::FieldRole, pushButton);

        label = new QLabel(properties);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(157, 101));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::SpanningRole, label);


        retranslateUi(properties);

        QMetaObject::connectSlotsByName(properties);
    } // setupUi

    void retranslateUi(QDialog *properties)
    {
        properties->setWindowTitle(QApplication::translate("properties", "Properties", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("properties", "Name:", 0, QApplication::UnicodeUTF8));
        image_name->setText(QString());
        label_4->setText(QApplication::translate("properties", "Size:", 0, QApplication::UnicodeUTF8));
        image_size->setText(QString());
        label_7->setText(QApplication::translate("properties", "Width:", 0, QApplication::UnicodeUTF8));
        image_width->setText(QString());
        label_6->setText(QApplication::translate("properties", "Height:", 0, QApplication::UnicodeUTF8));
        image_height->setText(QString());
        label_3->setText(QApplication::translate("properties", "Type:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("properties", "Location:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("properties", "&Close", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class properties: public Ui_properties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIES_H
