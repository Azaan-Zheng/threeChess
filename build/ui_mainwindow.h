/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <BoardView.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    BoardView *boardView;
    QWidget *infoView;
    QWidget *controlView;
    QWidget *controlWidget;
    QWidget *titleView;
    QLabel *title;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 600);
        MainWindow->setStyleSheet(QLatin1String("QLabel#title{\n"
"	image:url(:/resources/image/title.png);\n"
"	height:80px;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        boardView = new BoardView(centralWidget);
        boardView->setObjectName(QStringLiteral("boardView"));
        boardView->setGeometry(QRect(210, 100, 420, 420));
        infoView = new QWidget(centralWidget);
        infoView->setObjectName(QStringLiteral("infoView"));
        infoView->setGeometry(QRect(20, 100, 191, 421));
        controlView = new QWidget(centralWidget);
        controlView->setObjectName(QStringLiteral("controlView"));
        controlView->setGeometry(QRect(630, 80, 311, 451));
        controlWidget = new QWidget(controlView);
        controlWidget->setObjectName(QStringLiteral("controlWidget"));
        controlWidget->setGeometry(QRect(10, 210, 291, 231));
        titleView = new QWidget(centralWidget);
        titleView->setObjectName(QStringLiteral("titleView"));
        titleView->setGeometry(QRect(20, 10, 531, 91));
        title = new QLabel(titleView);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(30, 0, 230, 80));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        title->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
