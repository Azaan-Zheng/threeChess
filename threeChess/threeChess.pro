#-------------------------------------------------
#
# Project created by QtCreator 2021-08-23T12:01:09
#
#-------------------------------------------------

QT       += core gui multimedia sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = threeChess
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    Piece.cpp \
    Board.cpp \
    ChessBook.cpp \
    BoardView.cpp \
    Login.cpp \
    Controller.cpp \
    Introduction.cpp \
    Practice.cpp \
    Humanplay.cpp \
    Generator.cpp

HEADERS += \
    Piece.h \
    Board.h \
    ChessBook.h \
    define.h \
    BoardView.h \
    Login.h \
    Controller.h \
    Introduction.h \
    Practice.h \
    Humanplay.h \
    Generator.h

FORMS += \
    Login.ui \
    Introduction.ui \
    Practice.ui \
    Humanplay.ui

RESOURCES += \
    src.qrc

RC_FILE += logo.rc

CONFIG += resources_big
