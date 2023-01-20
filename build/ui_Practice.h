/********************************************************************************
** Form generated from reading UI file 'Practice.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICE_H
#define UI_PRACTICE_H

#include <BoardView.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Practice
{
public:
    QWidget *centralwidget;
    BoardView *boardView;
    QWidget *controlView;
    QWidget *controlWidget;
    QToolButton *btnLast;
    QToolButton *btnNext;
    QToolButton *btnExchange;
    QToolButton *btnSave;
    QWidget *chessbookWidget;
    QLabel *chessbookLabel;
    QListWidget *chessbookEdit;
    QWidget *infoView;
    QWidget *boardInfoWidget;
    QLabel *boardInfoLabel;
    QTextEdit *boardInfoEdit;
    QToolButton *btnOpen;
    QToolButton *btnDelete;
    QWidget *historyWidget;
    QLabel *historyLabel;
    QListView *historyEdit;
    QToolButton *btnReturn;

    void setupUi(QMainWindow *Practice)
    {
        if (Practice->objectName().isEmpty())
            Practice->setObjectName(QStringLiteral("Practice"));
        Practice->resize(1000, 600);
        Practice->setStyleSheet(QString::fromUtf8("/* \346\216\247\345\210\266\346\273\232\345\212\250\346\235\241*/\n"
"QScrollBar:vertical{\n"
"	background-color:transparent;\n"
"	width:10px;\n"
"	height:200px;\n"
"	padding-top:10px;\n"
"	padding-bottom:10px;\n"
"}  \n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{\n"
"	background-color:rgb(194,137,104);\n"
"}        \n"
"QScrollBar::handle:vertical{\n"
"	background:rgba(124,64,44,0.8);\n"
"}   \n"
"QScrollBar::handle:vertical:hover,QScrollBar::handle:vertical:pressed{\n"
"	background:rgba(104,54,34,0.8);\n"
"    border:0px solid rgb(100,100,100);\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical{\n"
"	height:20px;\n"
"	width:20px;\n"
"	border:0px solid rgb(128,217,197);\n"
"	background:rgba(159,100,74,1) url(:/image/icon/toolIcon/icon_up.png);\n"
"}\n"
"QScrollBar::add-line:vertical{\n"
"	height:20px;\n"
"	width:20px;\n"
"	border:0px solid rgb(128,217,197);\n"
"	background:rgba(159,100,74,1) url(:/image/icon/toolIcon/icon_down.png);\n"
"}\n"
"\n"
"\n"
"QScrollBar:horizontal{\n"
"	background-color"
                        ":transparent;\n"
"	width:140px;\n"
"	height:0px;\n"
"	padding-left:12px;\n"
"	padding-right:12px;\n"
"}  \n"
"QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{\n"
"	background-color:transparent;\n"
"}        \n"
"QScrollBar::handle:horizontal{\n"
"	background:rgba(41,43,45,0.8);\n"
"	border:0px solid rgba(21,23,25,1);\n"
"}    \n"
"QScrollBar::handle:horizontal:hover,QScrollBar::handle:horizontal:pressed{					  		      \n"
"    background:rgba(31,33,35,1);\n"
"	border:0px solid rgb(255,255,255);\n"
"}\n"
"\n"
"/* \346\216\247\345\210\266\346\214\211\351\222\256\345\233\276\347\211\207*/\n"
"\n"
"\n"
"QToolButton#btnReturn{\n"
"	border-image:url(:/resources/image/btnReturn.png);\n"
"}\n"
"QToolButton#btnReturn:hover{\n"
"	border-image:url(:/resources/image/btnReturn1.png);\n"
"}\n"
"\n"
"\n"
"\n"
"QToolButton#btnExchange{\n"
"	border-image:url(:/resources/image/btnExchange.png);\n"
"}\n"
"QToolButton#btnExchange:hover{\n"
"	border-image:url(:/resources/image/btnExchange1.png);\n"
"}\n"
"\n"
"QToo"
                        "lButton#btnSave{\n"
"	border-image:url(:/resources/image/btnSave.png);\n"
"}\n"
"QToolButton#btnSave:hover{\n"
"	border-image:url(:/resources/image/btnSave1.png);\n"
"}\n"
"\n"
"QToolButton#btnLast{\n"
"	border-image:url(:/resources/image/btnLast.png);\n"
"}\n"
"QToolButton#btnLast:hover{\n"
"	border-image:url(:/resources/image/btnLast1.png);\n"
"}\n"
"\n"
"QToolButton#btnNext{\n"
"	border-image:url(:/resources/image/btnNext.png);\n"
"}\n"
"QToolButton#btnNext:hover{\n"
"	border-image:url(:/resources/image/btnNext1.png);\n"
"}\n"
"\n"
"QLabel#chessbookLabel{\n"
"	image:url(:/resources/image/chessbookLabel.png);\n"
"}\n"
"\n"
"QWidget#chessbookWidget{\n"
"	border-radius:4px;\n"
"	border:4px solid rgb(219,149,96);\n"
"}\n"
"\n"
"#chessbookEdit{\n"
"	border:0px;\n"
"	background-color:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(144, 80, 45, 255), stop:1 rgba(173, 104, 62, 255));\n"
"	selection-background-color:rgb(189,131,88);\n"
"}\n"
"\n"
"QLabel#boardInfoLabel{\n"
"	image:url(:/resources/ima"
                        "ge/boardInfo.png);\n"
"}\n"
"\n"
"QWidget#boardInfoWidget{\n"
"	border-radius:4px;\n"
"	border:4px solid rgb(219,149,96);\n"
"}\n"
"\n"
"QTextEdit#boardInfoEdit{\n"
"	border:0px;\n"
"	background-color:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(144, 80, 45, 255), stop:1 rgba(173, 104, 62, 255));\n"
"}\n"
"\n"
"\n"
"QToolButton#btnOpen{\n"
"	border-image:url(:/resources/image/open.png);\n"
"}\n"
"QToolButton#btnOpen:hover{\n"
"	border-image:url(:/resources/image/open1.png);\n"
"}\n"
"\n"
"QToolButton#btnDelete{\n"
"	border-image:url(:/resources/image/delete.png);\n"
"}\n"
"QToolButton#btnDelete:hover{\n"
"	border-image:url(:/resources/image/delete1.png);\n"
"}\n"
"\n"
"QLabel#historyLabel{\n"
"	image:url(:/resources/image/history.png);\n"
"}\n"
"\n"
"QWidget#historyWidget{\n"
"	border-radius:4px;\n"
"	border:4px solid rgb(219,149,96);\n"
"}\n"
"\n"
"#historyEdit{\n"
"	border:0px;\n"
"	background-color:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(144, 80, 45, 255), stop:1 r"
                        "gba(173, 104, 62, 255));\n"
"}\n"
""));
        centralwidget = new QWidget(Practice);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        boardView = new BoardView(centralwidget);
        boardView->setObjectName(QStringLiteral("boardView"));
        boardView->setGeometry(QRect(220, 120, 420, 420));
        controlView = new QWidget(centralwidget);
        controlView->setObjectName(QStringLiteral("controlView"));
        controlView->setGeometry(QRect(640, 100, 311, 451));
        controlWidget = new QWidget(controlView);
        controlWidget->setObjectName(QStringLiteral("controlWidget"));
        controlWidget->setGeometry(QRect(10, 290, 291, 151));
        btnLast = new QToolButton(controlWidget);
        btnLast->setObjectName(QStringLiteral("btnLast"));
        btnLast->setGeometry(QRect(30, 30, 90, 30));
        btnNext = new QToolButton(controlWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setGeometry(QRect(160, 30, 90, 30));
        btnExchange = new QToolButton(controlWidget);
        btnExchange->setObjectName(QStringLiteral("btnExchange"));
        btnExchange->setGeometry(QRect(30, 90, 90, 30));
        btnSave = new QToolButton(controlWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(160, 90, 90, 30));
        chessbookWidget = new QWidget(controlView);
        chessbookWidget->setObjectName(QStringLiteral("chessbookWidget"));
        chessbookWidget->setGeometry(QRect(10, 10, 281, 241));
        chessbookLabel = new QLabel(chessbookWidget);
        chessbookLabel->setObjectName(QStringLiteral("chessbookLabel"));
        chessbookLabel->setGeometry(QRect(10, 0, 261, 31));
        chessbookEdit = new QListWidget(chessbookWidget);
        chessbookEdit->setObjectName(QStringLiteral("chessbookEdit"));
        chessbookEdit->setGeometry(QRect(10, 40, 256, 192));
        infoView = new QWidget(centralwidget);
        infoView->setObjectName(QStringLiteral("infoView"));
        infoView->setGeometry(QRect(30, 120, 191, 421));
        boardInfoWidget = new QWidget(infoView);
        boardInfoWidget->setObjectName(QStringLiteral("boardInfoWidget"));
        boardInfoWidget->setGeometry(QRect(10, 220, 171, 181));
        boardInfoLabel = new QLabel(boardInfoWidget);
        boardInfoLabel->setObjectName(QStringLiteral("boardInfoLabel"));
        boardInfoLabel->setGeometry(QRect(10, 0, 151, 31));
        boardInfoEdit = new QTextEdit(boardInfoWidget);
        boardInfoEdit->setObjectName(QStringLiteral("boardInfoEdit"));
        boardInfoEdit->setGeometry(QRect(10, 40, 151, 131));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(16);
        boardInfoEdit->setFont(font);
        boardInfoEdit->setReadOnly(true);
        btnOpen = new QToolButton(infoView);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));
        btnOpen->setGeometry(QRect(10, 180, 71, 31));
        btnDelete = new QToolButton(infoView);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setGeometry(QRect(100, 180, 71, 31));
        historyWidget = new QWidget(infoView);
        historyWidget->setObjectName(QStringLiteral("historyWidget"));
        historyWidget->setGeometry(QRect(10, 10, 171, 141));
        historyLabel = new QLabel(historyWidget);
        historyLabel->setObjectName(QStringLiteral("historyLabel"));
        historyLabel->setGeometry(QRect(10, 0, 151, 31));
        historyEdit = new QListView(historyWidget);
        historyEdit->setObjectName(QStringLiteral("historyEdit"));
        historyEdit->setGeometry(QRect(10, 30, 141, 101));
        btnReturn = new QToolButton(centralwidget);
        btnReturn->setObjectName(QStringLiteral("btnReturn"));
        btnReturn->setGeometry(QRect(20, 20, 160, 60));
        Practice->setCentralWidget(centralwidget);

        retranslateUi(Practice);

        QMetaObject::connectSlotsByName(Practice);
    } // setupUi

    void retranslateUi(QMainWindow *Practice)
    {
        Practice->setWindowTitle(QApplication::translate("Practice", "MainWindow", Q_NULLPTR));
        btnLast->setText(QString());
        btnNext->setText(QString());
        btnExchange->setText(QString());
        btnSave->setText(QString());
        chessbookLabel->setText(QString());
        boardInfoLabel->setText(QString());
        boardInfoEdit->setHtml(QApplication::translate("Practice", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Adobe \345\256\213\344\275\223 Std L'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        btnOpen->setText(QString());
        btnDelete->setText(QString());
        historyLabel->setText(QString());
        btnReturn->setText(QApplication::translate("Practice", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Practice: public Ui_Practice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICE_H
