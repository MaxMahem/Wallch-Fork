/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Sep 5 16:22:10 2011
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
      28,   14, // methods
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
     140,   11,   11,   11, 0x08,
     177,   11,   11,   11, 0x08,
     206,   11,   11,   11, 0x08,
     232,   11,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,
     279,   11,   11,   11, 0x08,
     303,   11,   11,   11, 0x08,
     334,  328,   11,   11, 0x08,
     367,   11,   11,   11, 0x08,
     387,  381,   11,   11, 0x08,
     420,  381,   11,   11, 0x08,
     447,  443,   11,   11, 0x08,
     476,  468,   11,   11, 0x08,
     508,   11,   11,   11, 0x08,
     534,   11,   11,   11, 0x0a,
     552,   11,   11,   11, 0x0a,
     568,   11,   11,   11, 0x0a,
     580,   11,   11,   11, 0x0a,
     593,   11,   11,   11, 0x0a,
     600,   11,   11,   11, 0x0a,
     617,   11,   11,   11, 0x0a,
     630,   11,   11,   11, 0x0a,
     642,   11,   11,   11, 0x0a,
     653,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_previousButton_clicked()\0"
    "on_addfolder_clicked()\0"
    "on_listWidget_customContextMenuRequested()\0"
    "on_listWidget_itemDoubleClicked()\0"
    "on_listWidget_itemSelectionChanged()\0"
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
    "load()\0showProperties()\0Openfolder()\0"
    "copyImage()\0copyPath()\0save_album()\0"
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
        case 3: on_listWidget_itemDoubleClicked(); break;
        case 4: on_listWidget_itemSelectionChanged(); break;
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
        case 23: showProperties(); break;
        case 24: Openfolder(); break;
        case 25: copyImage(); break;
        case 26: copyPath(); break;
        case 27: save_album(); break;
        default: ;
        }
        _id -= 28;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
