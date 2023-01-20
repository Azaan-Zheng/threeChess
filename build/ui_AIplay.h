/********************************************************************************
** Form generated from reading UI file 'AIplay.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIPLAY_H
#define UI_AIPLAY_H

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

class Ui_AIplay
{
public:
    QWidget *centralwidget;
    BoardView *boardView;
    QWidget *titleView;
    QLabel *title;
    QWidget *controlView;
    QWidget *controlWidget;
    QWidget *infoView;

    void setupUi(QMainWindow *AIplay)
    {
        if (AIplay->objectName().isEmpty())
            AIplay->setObjectName(QStringLiteral("AIplay"));
        AIplay->resize(1000, 600);
        centralwidget = new QWidget(AIplay);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        boardView = new BoardView(centralwidget);
        boardView->setObjectName(QStringLiteral("boardView"));
        boardView->setGeometry(QRect(220, 130, 360, 360));
        titleView = new QWidget(centralwidget);
        titleView->setObjectName(QStringLiteral("titleView"));
        titleView->setGeometry(QRect(60, 50, 531, 91));
        title = new QLabel(titleView);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(30, 0, 230, 80));
        controlView = new QWidget(centralwidget);
        controlView->setObjectName(QStringLiteral("controlView"));
        controlView->setGeometry(QRect(580, 130, 311, 451));
        controlWidget = new QWidget(controlView);
        controlWidget->setObjectName(QStringLiteral("controlWidget"));
        controlWidget->setGeometry(QRect(10, 210, 291, 231));
        infoView = new QWidget(centralwidget);
        infoView->setObjectName(QStringLiteral("infoView"));
        infoView->setGeometry(QRect(30, 130, 191, 421));
        AIplay->setCentralWidget(centralwidget);

        retranslateUi(AIplay);

        QMetaObject::connectSlotsByName(AIplay);
    } // setupUi

    void retranslateUi(QMainWindow *AIplay)
    {
        AIplay->setWindowTitle(QApplication::translate("AIplay", "MainWindow", Q_NULLPTR));
        title->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AIplay: public Ui_AIplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIPLAY_H
