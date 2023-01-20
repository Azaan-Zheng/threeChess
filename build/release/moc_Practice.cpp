/****************************************************************************
** Meta object code from reading C++ file 'Practice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../threeChess/Practice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Practice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Practice_t {
    QByteArrayData data[10];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Practice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Practice_t qt_meta_stringdata_Practice = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Practice"
QT_MOC_LITERAL(1, 9, 11), // "modelReturn"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 15), // "modelChangeSide"
QT_MOC_LITERAL(4, 38, 13), // "modelLastStep"
QT_MOC_LITERAL(5, 52, 13), // "modelNextStep"
QT_MOC_LITERAL(6, 66, 18), // "modelSaveChessbook"
QT_MOC_LITERAL(7, 85, 18), // "modelOpenChessbook"
QT_MOC_LITERAL(8, 104, 5), // "index"
QT_MOC_LITERAL(9, 110, 20) // "modelDeleteChessbook"

    },
    "Practice\0modelReturn\0\0modelChangeSide\0"
    "modelLastStep\0modelNextStep\0"
    "modelSaveChessbook\0modelOpenChessbook\0"
    "index\0modelDeleteChessbook"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Practice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    1,   54,    2, 0x06 /* Public */,
       9,    1,   57,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QModelIndex,    8,

       0        // eod
};

void Practice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Practice *_t = static_cast<Practice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modelReturn(); break;
        case 1: _t->modelChangeSide(); break;
        case 2: _t->modelLastStep(); break;
        case 3: _t->modelNextStep(); break;
        case 4: _t->modelSaveChessbook(); break;
        case 5: _t->modelOpenChessbook((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->modelDeleteChessbook((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Practice::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Practice::modelReturn)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Practice::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Practice::modelChangeSide)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Practice::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Practice::modelLastStep)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Practice::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Practice::modelNextStep)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Practice::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Practice::modelSaveChessbook)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Practice::*_t)(QModelIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Practice::modelOpenChessbook)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Practice::*_t)(QModelIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Practice::modelDeleteChessbook)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject Practice::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Practice.data,
      qt_meta_data_Practice,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Practice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Practice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Practice.stringdata0))
        return static_cast<void*>(const_cast< Practice*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Practice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Practice::modelReturn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Practice::modelChangeSide()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Practice::modelLastStep()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Practice::modelNextStep()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Practice::modelSaveChessbook()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Practice::modelOpenChessbook(QModelIndex _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Practice::modelDeleteChessbook(QModelIndex _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
