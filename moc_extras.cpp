/****************************************************************************
** Meta object code from reading C++ file 'extras.h'
**
** Created: Thu Sep 1 03:16:47 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "extras.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'extras.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Extras[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      27,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,    7,    7,    7, 0x08,
      72,    7,    7,    7, 0x08,
      99,    7,    7,    7, 0x08,
     136,    7,    7,    7, 0x08,
     170,    7,    7,    7, 0x08,
     197,    7,    7,    7, 0x08,
     222,    7,    7,    7, 0x08,
     236,    7,    7,    7, 0x08,
     277,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Extras[] = {
    "Extras\0\0start_live_earth()\0stop_live_earth()\0"
    "on_pushButton_11_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_use_current_radioButton_clicked()\0"
    "on_image_from_disk_lock_clicked()\0"
    "on_pushButton_12_clicked()\0"
    "on_closeButton_clicked()\0set_current()\0"
    "on_liveEarthActivatePushButton_clicked()\0"
    "on_liveEarthDeactivatePushButton_clicked()\0"
};

const QMetaObject Extras::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Extras,
      qt_meta_data_Extras, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Extras::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Extras::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Extras::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Extras))
        return static_cast<void*>(const_cast< Extras*>(this));
    return QDialog::qt_metacast(_clname);
}

int Extras::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: start_live_earth(); break;
        case 1: stop_live_earth(); break;
        case 2: on_pushButton_11_clicked(); break;
        case 3: on_pushButton_10_clicked(); break;
        case 4: on_use_current_radioButton_clicked(); break;
        case 5: on_image_from_disk_lock_clicked(); break;
        case 6: on_pushButton_12_clicked(); break;
        case 7: on_closeButton_clicked(); break;
        case 8: set_current(); break;
        case 9: on_liveEarthActivatePushButton_clicked(); break;
        case 10: on_liveEarthDeactivatePushButton_clicked(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Extras::start_live_earth()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Extras::stop_live_earth()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
