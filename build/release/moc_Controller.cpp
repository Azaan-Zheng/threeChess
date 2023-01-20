/****************************************************************************
** Meta object code from reading C++ file 'Controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../threeChess/Controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[55];
    char stringdata0[642];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 11), // "setDatabase"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "openDatabase"
QT_MOC_LITERAL(4, 37, 13), // "closeDatabase"
QT_MOC_LITERAL(5, 51, 8), // "getModel"
QT_MOC_LITERAL(6, 60, 8), // "theModel"
QT_MOC_LITERAL(7, 69, 15), // "setModelInitial"
QT_MOC_LITERAL(8, 85, 11), // "setModelEnd"
QT_MOC_LITERAL(9, 97, 9), // "playPiece"
QT_MOC_LITERAL(10, 107, 14), // "playPieceHuman"
QT_MOC_LITERAL(11, 122, 9), // "theCircle"
QT_MOC_LITERAL(12, 132, 7), // "theSeat"
QT_MOC_LITERAL(13, 140, 6), // "PPoint"
QT_MOC_LITERAL(14, 147, 5), // "piece"
QT_MOC_LITERAL(15, 153, 16), // "playPieceOutcome"
QT_MOC_LITERAL(16, 170, 7), // "outcome"
QT_MOC_LITERAL(17, 178, 17), // "setIntroStagePose"
QT_MOC_LITERAL(18, 196, 17), // "setIntroStageMove"
QT_MOC_LITERAL(19, 214, 12), // "setBeginGame"
QT_MOC_LITERAL(20, 227, 6), // "Player"
QT_MOC_LITERAL(21, 234, 2), // "p1"
QT_MOC_LITERAL(22, 237, 2), // "p2"
QT_MOC_LITERAL(23, 240, 9), // "theSecond"
QT_MOC_LITERAL(24, 250, 11), // "setGameOver"
QT_MOC_LITERAL(25, 262, 11), // "isWhiteFlag"
QT_MOC_LITERAL(26, 274, 11), // "isTimeLimit"
QT_MOC_LITERAL(27, 286, 16), // "setGameOverNoEnd"
QT_MOC_LITERAL(28, 303, 11), // "setBackGame"
QT_MOC_LITERAL(29, 315, 12), // "setGamePause"
QT_MOC_LITERAL(30, 328, 8), // "setTimer"
QT_MOC_LITERAL(31, 337, 11), // "setNextPrac"
QT_MOC_LITERAL(32, 349, 11), // "setBackPrac"
QT_MOC_LITERAL(33, 361, 16), // "setOpenChessbook"
QT_MOC_LITERAL(34, 378, 5), // "index"
QT_MOC_LITERAL(35, 384, 18), // "setDeleteChessbook"
QT_MOC_LITERAL(36, 403, 13), // "setChangeSide"
QT_MOC_LITERAL(37, 417, 16), // "setSaveChessbook"
QT_MOC_LITERAL(38, 434, 18), // "setAppendChessbook"
QT_MOC_LITERAL(39, 453, 4), // "Step"
QT_MOC_LITERAL(40, 458, 4), // "step"
QT_MOC_LITERAL(41, 463, 13), // "sendColorFail"
QT_MOC_LITERAL(42, 477, 17), // "sendColorContinue"
QT_MOC_LITERAL(43, 495, 17), // "sendColorExchange"
QT_MOC_LITERAL(44, 513, 18), // "sendFromPoseToMove"
QT_MOC_LITERAL(45, 532, 11), // "sendInfoStr"
QT_MOC_LITERAL(46, 544, 3), // "str"
QT_MOC_LITERAL(47, 548, 22), // "printCurrentDayAndTime"
QT_MOC_LITERAL(48, 571, 10), // "printColor"
QT_MOC_LITERAL(49, 582, 5), // "color"
QT_MOC_LITERAL(50, 588, 15), // "changeBackMusic"
QT_MOC_LITERAL(51, 604, 13), // "msgPracStatic"
QT_MOC_LITERAL(52, 618, 9), // "msgRemind"
QT_MOC_LITERAL(53, 628, 5), // "title"
QT_MOC_LITERAL(54, 634, 7) // "content"

    },
    "Controller\0setDatabase\0\0openDatabase\0"
    "closeDatabase\0getModel\0theModel\0"
    "setModelInitial\0setModelEnd\0playPiece\0"
    "playPieceHuman\0theCircle\0theSeat\0"
    "PPoint\0piece\0playPieceOutcome\0outcome\0"
    "setIntroStagePose\0setIntroStageMove\0"
    "setBeginGame\0Player\0p1\0p2\0theSecond\0"
    "setGameOver\0isWhiteFlag\0isTimeLimit\0"
    "setGameOverNoEnd\0setBackGame\0setGamePause\0"
    "setTimer\0setNextPrac\0setBackPrac\0"
    "setOpenChessbook\0index\0setDeleteChessbook\0"
    "setChangeSide\0setSaveChessbook\0"
    "setAppendChessbook\0Step\0step\0sendColorFail\0"
    "sendColorContinue\0sendColorExchange\0"
    "sendFromPoseToMove\0sendInfoStr\0str\0"
    "printCurrentDayAndTime\0printColor\0"
    "color\0changeBackMusic\0msgPracStatic\0"
    "msgRemind\0title\0content"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  184,    2, 0x0a /* Public */,
       3,    0,  185,    2, 0x0a /* Public */,
       4,    0,  186,    2, 0x0a /* Public */,
       5,    1,  187,    2, 0x0a /* Public */,
       7,    0,  190,    2, 0x0a /* Public */,
       8,    0,  191,    2, 0x0a /* Public */,
       9,    0,  192,    2, 0x0a /* Public */,
      10,    3,  193,    2, 0x0a /* Public */,
      15,    1,  200,    2, 0x0a /* Public */,
      17,    0,  203,    2, 0x0a /* Public */,
      18,    0,  204,    2, 0x0a /* Public */,
      19,    3,  205,    2, 0x0a /* Public */,
      24,    2,  212,    2, 0x0a /* Public */,
      27,    0,  217,    2, 0x0a /* Public */,
      28,    0,  218,    2, 0x0a /* Public */,
      29,    0,  219,    2, 0x0a /* Public */,
      30,    0,  220,    2, 0x0a /* Public */,
      31,    0,  221,    2, 0x0a /* Public */,
      32,    0,  222,    2, 0x0a /* Public */,
      33,    1,  223,    2, 0x0a /* Public */,
      35,    1,  226,    2, 0x0a /* Public */,
      36,    0,  229,    2, 0x0a /* Public */,
      37,    0,  230,    2, 0x0a /* Public */,
      38,    1,  231,    2, 0x0a /* Public */,
      41,    0,  234,    2, 0x0a /* Public */,
      42,    0,  235,    2, 0x0a /* Public */,
      43,    0,  236,    2, 0x0a /* Public */,
      44,    0,  237,    2, 0x0a /* Public */,
      45,    1,  238,    2, 0x0a /* Public */,
      47,    0,  241,    2, 0x0a /* Public */,
      48,    1,  242,    2, 0x0a /* Public */,
      50,    0,  245,    2, 0x0a /* Public */,
      51,    0,  246,    2, 0x0a /* Public */,
      52,    2,  247,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 13,   11,   12,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 20, QMetaType::Int,   21,   22,   23,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   25,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   34,
    QMetaType::Void, QMetaType::QModelIndex,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 39,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::QString,
    QMetaType::QString, QMetaType::Int,   49,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   53,   54,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setDatabase(); break;
        case 1: _t->openDatabase(); break;
        case 2: _t->closeDatabase(); break;
        case 3: _t->getModel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setModelInitial(); break;
        case 5: _t->setModelEnd(); break;
        case 6: _t->playPiece(); break;
        case 7: _t->playPieceHuman((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< PPoint(*)>(_a[3]))); break;
        case 8: _t->playPieceOutcome((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setIntroStagePose(); break;
        case 10: _t->setIntroStageMove(); break;
        case 11: _t->setBeginGame((*reinterpret_cast< Player(*)>(_a[1])),(*reinterpret_cast< Player(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->setGameOver((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->setGameOverNoEnd(); break;
        case 14: _t->setBackGame(); break;
        case 15: _t->setGamePause(); break;
        case 16: _t->setTimer(); break;
        case 17: _t->setNextPrac(); break;
        case 18: _t->setBackPrac(); break;
        case 19: _t->setOpenChessbook((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 20: _t->setDeleteChessbook((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 21: _t->setChangeSide(); break;
        case 22: _t->setSaveChessbook(); break;
        case 23: _t->setAppendChessbook((*reinterpret_cast< Step(*)>(_a[1]))); break;
        case 24: _t->sendColorFail(); break;
        case 25: _t->sendColorContinue(); break;
        case 26: _t->sendColorExchange(); break;
        case 27: _t->sendFromPoseToMove(); break;
        case 28: _t->sendInfoStr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: { QString _r = _t->printCurrentDayAndTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 30: { QString _r = _t->printColor((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 31: _t->changeBackMusic(); break;
        case 32: { int _r = _t->msgPracStatic();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->msgRemind((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 34;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
