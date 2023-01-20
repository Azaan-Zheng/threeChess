/****************************************************************************
** Meta object code from reading C++ file 'Humanplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../threeChess/Humanplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Humanplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Humanplay_t {
    QByteArrayData data[16];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Humanplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Humanplay_t qt_meta_stringdata_Humanplay = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Humanplay"
QT_MOC_LITERAL(1, 10, 11), // "modelReturn"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "modelPause"
QT_MOC_LITERAL(4, 34, 10), // "modelBegin"
QT_MOC_LITERAL(5, 45, 6), // "Player"
QT_MOC_LITERAL(6, 52, 2), // "p1"
QT_MOC_LITERAL(7, 55, 2), // "p2"
QT_MOC_LITERAL(8, 58, 9), // "theMinite"
QT_MOC_LITERAL(9, 68, 9), // "modelBack"
QT_MOC_LITERAL(10, 78, 9), // "modelLose"
QT_MOC_LITERAL(11, 88, 11), // "isWhiteFlag"
QT_MOC_LITERAL(12, 100, 11), // "isTimeLimit"
QT_MOC_LITERAL(13, 112, 9), // "modelSave"
QT_MOC_LITERAL(14, 122, 15), // "modelChangeSide"
QT_MOC_LITERAL(15, 138, 9) // "modelOver"

    },
    "Humanplay\0modelReturn\0\0modelPause\0"
    "modelBegin\0Player\0p1\0p2\0theMinite\0"
    "modelBack\0modelLose\0isWhiteFlag\0"
    "isTimeLimit\0modelSave\0modelChangeSide\0"
    "modelOver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Humanplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    3,   56,    2, 0x06 /* Public */,
       9,    0,   63,    2, 0x06 /* Public */,
      10,    2,   64,    2, 0x06 /* Public */,
      13,    0,   69,    2, 0x06 /* Public */,
      14,    0,   70,    2, 0x06 /* Public */,
      15,    0,   71,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, QMetaType::Int,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Humanplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Humanplay *_t = static_cast<Humanplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modelReturn(); break;
        case 1: _t->modelPause(); break;
        case 2: _t->modelBegin((*reinterpret_cast< Player(*)>(_a[1])),(*reinterpret_cast< Player(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->modelBack(); break;
        case 4: _t->modelLose((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->modelSave(); break;
        case 6: _t->modelChangeSide(); break;
        case 7: _t->modelOver(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Humanplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Humanplay::modelReturn)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Humanplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Humanplay::modelPause)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Humanplay::*_t)(Player , Player , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Humanplay::modelBegin)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Humanplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Humanplay::modelBack)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Humanplay::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Humanplay::modelLose)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Humanplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Humanplay::modelSave)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Humanplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Humanplay::modelChangeSide)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Humanplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Humanplay::modelOver)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject Humanplay::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Humanplay.data,
      qt_meta_data_Humanplay,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Humanplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Humanplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Humanplay.stringdata0))
        return static_cast<void*>(const_cast< Humanplay*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Humanplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Humanplay::modelReturn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Humanplay::modelPause()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Humanplay::modelBegin(Player _t1, Player _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Humanplay::modelBack()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Humanplay::modelLose(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Humanplay::modelSave()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Humanplay::modelChangeSide()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Humanplay::modelOver()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
