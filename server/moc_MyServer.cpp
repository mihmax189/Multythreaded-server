/****************************************************************************
** Meta object code from reading C++ file 'MyServer.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyServer.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyServer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreadWorkUpClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_ThreadWorkUpClient[] = {
    "ThreadWorkUpClient\0"
};

void ThreadWorkUpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ThreadWorkUpClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadWorkUpClient::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadWorkUpClient,
      qt_meta_data_ThreadWorkUpClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadWorkUpClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadWorkUpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadWorkUpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadWorkUpClient))
        return static_cast<void*>(const_cast< ThreadWorkUpClient*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadWorkUpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_MyServer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      30,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyServer[] = {
    "MyServer\0\0slotNewConnection()\0"
    "slotReadClient()\0"
};

void MyServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyServer *_t = static_cast<MyServer *>(_o);
        switch (_id) {
        case 0: _t->slotNewConnection(); break;
        case 1: _t->slotReadClient(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MyServer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyServer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyServer,
      qt_meta_data_MyServer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyServer))
        return static_cast<void*>(const_cast< MyServer*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
