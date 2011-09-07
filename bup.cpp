/****************************************************************************
** Meta object code from reading C++ file 'preferences.h'
**
** Created: Sun Aug 21 09:25:51 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "preferences.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preferences.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_preferences[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   12,   12,   12, 0x08,
      55,   12,   12,   12, 0x08,
      81,   12,   12,   12, 0x08,
     105,   12,   12,   12, 0x08,
     136,   12,   12,   12, 0x08,
     169,   12,   12,   12, 0x08,
     200,   12,   12,   12, 0x08,
     224,   12,   12,   12, 0x08,
     249,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_preferences[] = {
    "preferences\0\0savePreferences()\0"
    "on_checkBox_5_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_browsesoundButton_clicked()\0"
    "on_customsoundcheckBox_clicked()\0"
    "on_playsoundcheckBox_clicked()\0"
    "on_aplyButton_clicked()\0"
    "on_closeButton_clicked()\0"
    "on_testSoundButton_clicked()\0"
};

const QMetaObject preferences::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_preferences,
      qt_meta_data_preferences, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &preferences::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *preferences::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *preferences::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_preferences))
        return static_cast<void*>(const_cast< preferences*>(this));
    return QDialog::qt_metacast(_clname);
}

int preferences::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: savePreferences(); break;
        case 1: on_launchOnStartupCheckBox_clicked(); break;
        case 2: on_resetPreferencesButton_clicked(); break;
        case 3: on_pushButton_clicked(); break;
        case 4: on_browsesoundButton_clicked(); break;
        case 5: on_customSoundRadio_clicked(); break;
        case 6: on_playsoundcheckBox_clicked(); break;
        case 7: on_aplyButton_clicked(); break;
        case 8: on_closeButton_clicked(); break;
        case 9: on_testSoundButton_clicked(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void preferences::savePreferences()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
