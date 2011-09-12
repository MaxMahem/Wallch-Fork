/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Sep 11 23:23:31 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      63,   11,   11,   11, 0x08,
     106,   11,   11,   11, 0x08,
     139,   11,   11,   11, 0x08,
     175,   11,   11,   11, 0x08,
     204,   11,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,
     253,   11,   11,   11, 0x08,
     277,   11,   11,   11, 0x08,
     301,   11,   11,   11, 0x08,
     332,  326,   11,   11, 0x08,
     365,   11,   11,   11, 0x08,
     385,  379,   11,   11, 0x08,
     418,  379,   11,   11, 0x08,
     445,  441,   11,   11, 0x08,
     474,  466,   11,   11, 0x08,
     506,   11,   11,   11, 0x08,
     532,   11,   11,   11, 0x0a,
     550,   11,   11,   11, 0x0a,
     566,   11,   11,   11, 0x0a,
     578,   11,   11,   11, 0x0a,
     591,   11,   11,   11, 0x0a,
     598,   11,   11,   11, 0x0a,
     611,   11,   11,   11, 0x0a,
     623,   11,   11,   11, 0x0a,
     634,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_previousButton_clicked()\0"
    "on_addfolder_clicked()\0"
    "on_listWidget_customContextMenuRequested()\0"
    "on_tableView_itemDoubleClicked()\0"
    "on_tableView_itemSelectionChanged()\0"
    "on_removeallButton_clicked()\0"
    "on_removeButton_clicked()\0"
    "on_addButton_clicked()\0on_stopButton_clicked()\0"
    "on_nextButton_clicked()\0"
    "on_startButton_clicked()\0value\0"
    "on_timerSlider_valueChanged(int)\0"
    "timeUpdater()\0event\0"
    "dragEnterEvent(QDragEnterEvent*)\0"
    "dropEvent(QDropEvent*)\0msg\0"
    "dbus_action(QString)\0checked\0"
    "on_webSourceRadio_toggled(bool)\0"
    "on_randomButton_clicked()\0ShowPreferences()\0"
    "menushowabout()\0pruneList()\0removeDisk()\0"
    "load()\0Openfolder()\0copyImage()\0"
    "copyPath()\0save_album()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_previousButton_clicked(); break;
        case 1: on_addfolder_clicked(); break;
        case 2: on_listWidget_customContextMenuRequested(); break;
        case 3: on_tableView_itemDoubleClicked(); break;
        case 4: on_tableView_itemSelectionChanged(); break;
        case 5: on_removeallButton_clicked(); break;
        case 6: on_removeButton_clicked(); break;
        case 7: on_addButton_clicked(); break;
        case 8: on_stopButton_clicked(); break;
        case 9: on_nextButton_clicked(); break;
        case 10: on_startButton_clicked(); break;
        case 11: on_timerSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: timeUpdater(); break;
        case 13: dragEnterEvent((*reinterpret_cast< QDragEnterEvent*(*)>(_a[1]))); break;
        case 14: dropEvent((*reinterpret_cast< QDropEvent*(*)>(_a[1]))); break;
        case 15: dbus_action((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: on_webSourceRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: on_randomButton_clicked(); break;
        case 18: ShowPreferences(); break;
        case 19: menushowabout(); break;
        case 20: pruneList(); break;
        case 21: removeDisk(); break;
        case 22: load(); break;
        case 23: Openfolder(); break;
        case 24: copyImage(); break;
        case 25: copyPath(); break;
        case 26: save_album(); break;
        default: ;
        }
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
