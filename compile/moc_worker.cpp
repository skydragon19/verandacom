/****************************************************************************
** Meta object code from reading C++ file 'worker.h'
**
** Created: Tue May 26 17:43:18 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../controller/worker.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Worker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,    8,    7,    7, 0x08,
      44,    8,    7,    7, 0x08,
     101,   77,    7,    7, 0x08,
     157,  141,    7,    7, 0x08,
     196,    7,    7,    7, 0x08,
     211,    7,    7,    7, 0x08,
     226,    7,    7,    7, 0x08,
     246,    7,    7,    7, 0x08,
     266,    7,    7,    7, 0x08,
     289,    7,    7,    7, 0x08,
     301,    7,    7,    7, 0x08,
     316,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Worker[] = {
    "Worker\0\0reply\0replyFinished(QNetworkReply*)\0"
    "allreplyFinished(QNetworkReply*)\0"
    "id_ship,startUTC,endUTC\0"
    "request_data_kapal(int,QString,QString)\0"
    "startUTC,endUTC\0request_data_semuanya(QString,QString)\0"
    "line_command()\0help_command()\0"
    "ship_list_command()\0download_all_ship()\0"
    "download_single_ship()\0ship_list()\0"
    "clear_screen()\0exit()\0"
};

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Worker *_t = static_cast<Worker *>(_o);
        switch (_id) {
        case 0: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->allreplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->request_data_kapal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->request_data_semuanya((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->line_command(); break;
        case 5: _t->help_command(); break;
        case 6: _t->ship_list_command(); break;
        case 7: _t->download_all_ship(); break;
        case 8: _t->download_single_ship(); break;
        case 9: _t->ship_list(); break;
        case 10: _t->clear_screen(); break;
        case 11: _t->exit(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Worker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Worker,
      qt_meta_data_Worker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Worker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Worker))
        return static_cast<void*>(const_cast< Worker*>(this));
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
