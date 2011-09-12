/****************************************************************************
** Meta object code from reading C++ file 'preferences.h'
**
** Created: Sun Sep 11 22:49:24 2011
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
static const uint qt_meta_data_Preferences[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       2,   44, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      49,   12,   12,   12, 0x08,
      80,   12,   12,   12, 0x08,
     104,   12,   12,   12, 0x08,
     129,   12,   12,   12, 0x08,
     158,   12,   12,   12, 0x08,

 // enums: name, flags, count, data
     192, 0x0,    3,   52,
     204, 0x0,    6,   58,

 // enum data: key, value
     226, uint(Preferences::run),
     230, uint(Preferences::once),
     235, uint(Preferences::liveEarth),
     245, uint(Preferences::wallpaper),
     255, uint(Preferences::zoom),
     260, uint(Preferences::centered),
     269, uint(Preferences::scaled),
     276, uint(Preferences::streched),
     285, uint(Preferences::spanned),

       0        // eod
};

static const char qt_meta_stringdata_Preferences[] = {
    "Preferences\0\0on_resetPreferencesButton_clicked()\0"
    "on_browseSoundButton_clicked()\0"
    "on_saveButton_clicked()\0"
    "on_closeButton_clicked()\0"
    "on_testSoundButton_clicked()\0"
    "on_customSoundRadio_toggled(bool)\0"
    "startupEnum\0backgroundSettingEnum\0run\0"
    "once\0liveEarth\0wallpaper\0zoom\0centered\0"
    "scaled\0streched\0spanned\0"
};

const QMetaObject Preferences::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Preferences,
      qt_meta_data_Preferences, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Preferences::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Preferences::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Preferences::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Preferences))
        return static_cast<void*>(const_cast< Preferences*>(this));
    return QDialog::qt_metacast(_clname);
}

int Preferences::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_resetPreferencesButton_clicked(); break;
        case 1: on_browseSoundButton_clicked(); break;
        case 2: on_saveButton_clicked(); break;
        case 3: on_closeButton_clicked(); break;
        case 4: on_testSoundButton_clicked(); break;
        case 5: on_customSoundRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
