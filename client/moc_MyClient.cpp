/****************************************************************************
** Meta object code from reading C++ file 'MyClient.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyClient.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyClient.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      26,    9,    9,    9, 0x08,
      66,    9,    9,    9, 0x08,
      85,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyClient[] = {
    "MyClient\0\0slotReadyRead()\0"
    "slotError(QAbstractSocket::SocketError)\0"
    "slotSendToServer()\0slotConnected()\0"
};

void MyClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyClient *_t = static_cast<MyClient *>(_o);
        switch (_id) {
        case 0: _t->slotReadyRead(); break;
        case 1: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->slotSendToServer(); break;
        case 3: _t->slotConnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyClient::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyClient,
      qt_meta_data_MyClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyClient))
        return static_cast<void*>(const_cast< MyClient*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
