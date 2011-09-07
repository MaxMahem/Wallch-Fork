/****************************************************************************
** Meta object code from reading C++ file 'screenshot.h'
**
** Created: Tue Aug 23 03:06:48 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "screenshot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screenshot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_screenshot[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      22,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      84,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     131,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_screenshot[] = {
    "screenshot\0\0hide_it()\0show_it()\0"
    "on_QuitButton_clicked()\0"
    "on_saveScreenshot_clicked()\0"
    "on_newScreenshotButton_clicked()\0"
    "shootScreen()\0updateCheckBox()\0"
};

const QMetaObject screenshot::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_screenshot,
      qt_meta_data_screenshot, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &screenshot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *screenshot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *screenshot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_screenshot))
        return static_cast<void*>(const_cast< screenshot*>(this));
    return QDialog::qt_metacast(_clname);
}

int screenshot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: hide_it(); break;
        case 1: show_it(); break;
        case 2: on_QuitButton_clicked(); break;
        case 3: on_saveScreenshot_clicked(); break;
        case 4: on_newScreenshotButton_clicked(); break;
        case 5: shootScreen(); break;
        case 6: updateCheckBox(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void screenshot::hide_it()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void screenshot::show_it()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
