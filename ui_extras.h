/********************************************************************************
** Form generated from reading UI file 'extras.ui'
**
** Created: Thu Sep 1 03:16:37 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTRAS_H
#define UI_EXTRAS_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Extras
{
public:
    QToolBox *toolBox;
    QWidget *page;
    QLabel *label_12;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_7;
    QPushButton *liveEarthActivatePushButton;
    QPushButton *liveEarthDeactivatePushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QRadioButton *liveEarthRadioHemisphere;
    QRadioButton *liveEarthRadioRectangular;
    QLabel *liveEarthRectangularLabel;
    QLabel *liveEarthHemisphereLabel;
    QWidget *page_2;
    QRadioButton *use_current_radioButton;
    QPushButton *pushButton_11;
    QRadioButton *image_from_disk_lock;
    QPushButton *pushButton_10;
    QLabel *preview_lock;
    QPushButton *pushButton_12;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QPushButton *closeButton;
    QButtonGroup *liveEarthTypeGroup;

    void setupUi(QDialog *Extras)
    {
        if (Extras->objectName().isEmpty())
            Extras->setObjectName(QString::fromUtf8("Extras"));
        Extras->resize(529, 552);
        Extras->setMinimumSize(QSize(529, 552));
        Extras->setMaximumSize(QSize(529, 552));
        toolBox = new QToolBox(Extras);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(10, 10, 511, 481));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 511, 419));
        label_12 = new QLabel(page);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 0, 511, 61));
        label_12->setAlignment(Qt::AlignCenter);
        layoutWidget1 = new QWidget(page);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 70, 331, 62));
        verticalLayout_7 = new QVBoxLayout(layoutWidget1);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        liveEarthActivatePushButton = new QPushButton(layoutWidget1);
        liveEarthActivatePushButton->setObjectName(QString::fromUtf8("liveEarthActivatePushButton"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        liveEarthActivatePushButton->setFont(font);

        verticalLayout_7->addWidget(liveEarthActivatePushButton);

        liveEarthDeactivatePushButton = new QPushButton(layoutWidget1);
        liveEarthDeactivatePushButton->setObjectName(QString::fromUtf8("liveEarthDeactivatePushButton"));
        liveEarthDeactivatePushButton->setFont(font);

        verticalLayout_7->addWidget(liveEarthDeactivatePushButton);

        formLayoutWidget = new QWidget(page);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(89, 156, 331, 221));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        liveEarthRadioHemisphere = new QRadioButton(formLayoutWidget);
        liveEarthTypeGroup = new QButtonGroup(Extras);
        liveEarthTypeGroup->setObjectName(QString::fromUtf8("liveEarthTypeGroup"));
        liveEarthTypeGroup->addButton(liveEarthRadioHemisphere);
        liveEarthRadioHemisphere->setObjectName(QString::fromUtf8("liveEarthRadioHemisphere"));

        formLayout->setWidget(0, QFormLayout::LabelRole, liveEarthRadioHemisphere);

        liveEarthRadioRectangular = new QRadioButton(formLayoutWidget);
        liveEarthTypeGroup->addButton(liveEarthRadioRectangular);
        liveEarthRadioRectangular->setObjectName(QString::fromUtf8("liveEarthRadioRectangular"));
        liveEarthRadioRectangular->setChecked(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, liveEarthRadioRectangular);

        liveEarthRectangularLabel = new QLabel(formLayoutWidget);
        liveEarthRectangularLabel->setObjectName(QString::fromUtf8("liveEarthRectangularLabel"));
        liveEarthRectangularLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/Pictures/world_sunlight_map_rectangular_small.jpg")));

        formLayout->setWidget(1, QFormLayout::FieldRole, liveEarthRectangularLabel);

        liveEarthHemisphereLabel = new QLabel(formLayoutWidget);
        liveEarthHemisphereLabel->setObjectName(QString::fromUtf8("liveEarthHemisphereLabel"));
        liveEarthHemisphereLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/Pictures/world_sunlight_map_hemisphere_small.jpg")));

        formLayout->setWidget(0, QFormLayout::FieldRole, liveEarthHemisphereLabel);

        toolBox->addItem(page, QString::fromUtf8("Live Earth Wallpaper"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 511, 419));
        use_current_radioButton = new QRadioButton(page_2);
        use_current_radioButton->setObjectName(QString::fromUtf8("use_current_radioButton"));
        use_current_radioButton->setGeometry(QRect(0, 10, 511, 22));
        use_current_radioButton->setFocusPolicy(Qt::NoFocus);
        use_current_radioButton->setChecked(true);
        pushButton_11 = new QPushButton(page_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setEnabled(false);
        pushButton_11->setGeometry(QRect(70, 360, 161, 51));
        image_from_disk_lock = new QRadioButton(page_2);
        image_from_disk_lock->setObjectName(QString::fromUtf8("image_from_disk_lock"));
        image_from_disk_lock->setGeometry(QRect(0, 40, 511, 22));
        image_from_disk_lock->setFocusPolicy(Qt::NoFocus);
        image_from_disk_lock->setCheckable(true);
        image_from_disk_lock->setChecked(false);
        pushButton_10 = new QPushButton(page_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setEnabled(false);
        pushButton_10->setGeometry(QRect(30, 70, 121, 27));
        preview_lock = new QLabel(page_2);
        preview_lock->setObjectName(QString::fromUtf8("preview_lock"));
        preview_lock->setGeometry(QRect(148, 129, 230, 143));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(preview_lock->sizePolicy().hasHeightForWidth());
        preview_lock->setSizePolicy(sizePolicy);
        preview_lock->setScaledContents(true);
        pushButton_12 = new QPushButton(page_2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(276, 360, 151, 51));
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(160, 70, 301, 27));
        lineEdit_2->setReadOnly(true);
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 120, 245, 201));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/Pictures/screen.png")));
        label->setScaledContents(true);
        toolBox->addItem(page_2, QString::fromUtf8("Lock Screen Background"));
        label->raise();
        use_current_radioButton->raise();
        pushButton_11->raise();
        image_from_disk_lock->raise();
        pushButton_10->raise();
        pushButton_12->raise();
        lineEdit_2->raise();
        preview_lock->raise();
        closeButton = new QPushButton(Extras);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(400, 510, 109, 27));

        retranslateUi(Extras);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Extras);
    } // setupUi

    void retranslateUi(QDialog *Extras)
    {
        Extras->setWindowTitle(QApplication::translate("Extras", "Extras", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Extras", "Live earth wallpaper automatically configures your desktop wallpaper\n"
"to be a live earth background that updates every \302\275 hour.\n"
"Internet connection required.", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        liveEarthActivatePushButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        liveEarthActivatePushButton->setText(QApplication::translate("Extras", "Activate Live Earth Wallpaper", 0, QApplication::UnicodeUTF8));
        liveEarthDeactivatePushButton->setText(QApplication::translate("Extras", "Deactivate Live Earth Wallpaper", 0, QApplication::UnicodeUTF8));
        liveEarthRadioHemisphere->setText(QApplication::translate("Extras", "&Hemisphere", 0, QApplication::UnicodeUTF8));
        liveEarthRadioRectangular->setText(QApplication::translate("Extras", "&Rectangular", 0, QApplication::UnicodeUTF8));
        liveEarthRectangularLabel->setText(QString());
        liveEarthHemisphereLabel->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Extras", "Live Earth Wallpaper", 0, QApplication::UnicodeUTF8));
        use_current_radioButton->setText(QApplication::translate("Extras", "Use current desktop wallpaper", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("Extras", "CHANGE", 0, QApplication::UnicodeUTF8));
        image_from_disk_lock->setText(QApplication::translate("Extras", "Select Image From Disk", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("Extras", "Browse", 0, QApplication::UnicodeUTF8));
        preview_lock->setText(QString());
        pushButton_12->setText(QApplication::translate("Extras", "REVERT", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("Extras", "Lock Screen Background", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("Extras", "&Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Extras: public Ui_Extras {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRAS_H
