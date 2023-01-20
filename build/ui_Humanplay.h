/********************************************************************************
** Form generated from reading UI file 'Humanplay.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUMANPLAY_H
#define UI_HUMANPLAY_H

#include <BoardView.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Humanplay
{
public:
    QWidget *centralwidget;
    QWidget *controlView;
    QWidget *controlWidget;
    QToolButton *btnBegin;
    QToolButton *btnPause;
    QToolButton *btnExchange;
    QToolButton *btnBack;
    QToolButton *btnLose;
    QToolButton *btnSave;
    QWidget *chessbookWidget;
    QLabel *chessbookLabel;
    QListWidget *chessbookEdit;
    QWidget *infoView;
    QWidget *boardInfoWidget;
    QLabel *boardInfoLabel;
    QTextEdit *boardInfoEdit;
    QWidget *widgetPlayer1;
    QLabel *playerLabel1;
    QLabel *blackLabel;
    QLCDNumber *playerTimer1;
    QLabel *timeLabel1;
    QWidget *widgetPlayer2;
    QLabel *playerLabel2;
    QLabel *whiteLabel;
    QLCDNumber *playerTimer2;
    QLabel *timeLabel2;
    QComboBox *timeBox;
    QLabel *timeLimitLabel;
    QToolButton *btnReturn;
    BoardView *boardView;

    void setupUi(QMainWindow *Humanplay)
    {
        if (Humanplay->objectName().isEmpty())
            Humanplay->setObjectName(QStringLiteral("Humanplay"));
        Humanplay->resize(1000, 600);
        Humanplay->setStyleSheet(QString::fromUtf8("/* \346\216\247\345\210\266\346\273\232\345\212\250\346\235\241*/\n"
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
"QToolButton#btnReturn{\n"
"	border-image:url(:/resources/image/btnReturn.png);\n"
"}\n"
"QToolButton#btnReturn:hover{\n"
"	border-image:url(:/resources/image/btnReturn1.png);\n"
"}\n"
"\n"
"\n"
"QToolButton#btnBegin{\n"
"	border-image:url(:/resources/image/btnBegin.png);\n"
"}\n"
"QToolButton#btnBegin:hover{\n"
"	border-image:url(:/resources/image/btnBegin1.png);\n"
"}\n"
"\n"
"QToolButton#btnPause{\n"
""
                        "	border-image:url(:/resources/image/btnPause.png);\n"
"}\n"
"QToolButton#btnPause:hover{\n"
"	border-image:url(:/resources/image/btnPause1.png);\n"
"}\n"
"\n"
"QToolButton#btnExchange{\n"
"	border-image:url(:/resources/image/btnExchange.png);\n"
"}\n"
"QToolButton#btnExchange:hover{\n"
"	border-image:url(:/resources/image/btnExchange1.png);\n"
"}\n"
"\n"
"QToolButton#btnBack{\n"
"	border-image:url(:/resources/image/btnBack.png);\n"
"}\n"
"QToolButton#btnBack:hover{\n"
"	border-image:url(:/resources/image/btnBack1.png);\n"
"}\n"
"\n"
"QToolButton#btnLose{\n"
"	border-image:url(:/resources/image/btnLose.png);\n"
"}\n"
"QToolButton#btnLose:hover{\n"
"	border-image:url(:/resources/image/btnLose1.png);\n"
"}\n"
"\n"
"QToolButton#btnSave{\n"
"	border-image:url(:/resources/image/btnSave.png);\n"
"}\n"
"QToolButton#btnSave:hover{\n"
"	border-image:url(:/resources/image/btnSave1.png);\n"
"}\n"
"\n"
"QToolButton#btnAgain{\n"
"	border-image:url(:/resources/image/btnAgain.png);\n"
"}\n"
"QToolButton#btnAgain:hover{\n"
"	b"
                        "order-image:url(:/resources/image/btnAgain1.png);\n"
"}\n"
"\n"
"/* \346\216\247\345\210\266\346\243\213\350\260\261*/\n"
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
"\n"
"\n"
"QLabel#boardInfoLabel{\n"
"	image:url(:/resources/image/boardInfo.png);\n"
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
"/*\350\256\276\347\275\256\345\257\271\345\261\200*/\n"
"QLabel#pla"
                        "yerLabel1{\n"
"	image:url(:/resources/image/player1.png);\n"
"}\n"
"QLabel#blackLabel{\n"
"	image:url(:/resources/image/black.png);\n"
"}\n"
"QLabel#playerLabel2{\n"
"	image:url(:/resources/image/player2.png);\n"
"}\n"
"QLabel#whiteLabel{\n"
"	image:url(:/resources/image/white.png);\n"
"}\n"
"QLabel#timeLimitLabel{\n"
"	image:url(:/resources/image/timeLimit.png);\n"
"}\n"
"#timeBox{\n"
"	border-radius:4px;\n"
"	border:1px solid rgb(0,0,0);\n"
"	font-size:14px;\n"
"	background-color:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(164, 95, 52, 255), stop:1 rgba(203, 134, 92, 255));\n"
"}\n"
"QComboBox::drop-down {\n"
"     width :  23px ;\n"
"}\n"
"#playerTimer1,#playerTimer2{\n"
"	border-radius:4px;\n"
"	border:2px solid rgb(0,0,0);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"#timeLabel2,#timeLabel1{\n"
"	font-family:\346\245\267\344\275\223;\n"
"	font-size:18px;\n"
"	font-weight:black;\n"
"}"));
        centralwidget = new QWidget(Humanplay);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        controlView = new QWidget(centralwidget);
        controlView->setObjectName(QStringLiteral("controlView"));
        controlView->setGeometry(QRect(660, 90, 311, 501));
        controlWidget = new QWidget(controlView);
        controlWidget->setObjectName(QStringLiteral("controlWidget"));
        controlWidget->setGeometry(QRect(10, 270, 291, 221));
        btnBegin = new QToolButton(controlWidget);
        btnBegin->setObjectName(QStringLiteral("btnBegin"));
        btnBegin->setGeometry(QRect(20, 20, 90, 30));
        btnPause = new QToolButton(controlWidget);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        btnPause->setGeometry(QRect(150, 20, 90, 30));
        btnExchange = new QToolButton(controlWidget);
        btnExchange->setObjectName(QStringLiteral("btnExchange"));
        btnExchange->setGeometry(QRect(20, 70, 90, 30));
        btnBack = new QToolButton(controlWidget);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setGeometry(QRect(150, 70, 90, 30));
        btnLose = new QToolButton(controlWidget);
        btnLose->setObjectName(QStringLiteral("btnLose"));
        btnLose->setGeometry(QRect(20, 120, 90, 30));
        btnSave = new QToolButton(controlWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(150, 120, 90, 30));
        chessbookWidget = new QWidget(controlView);
        chessbookWidget->setObjectName(QStringLiteral("chessbookWidget"));
        chessbookWidget->setGeometry(QRect(20, 20, 281, 241));
        chessbookLabel = new QLabel(chessbookWidget);
        chessbookLabel->setObjectName(QStringLiteral("chessbookLabel"));
        chessbookLabel->setGeometry(QRect(10, 0, 261, 31));
        chessbookEdit = new QListWidget(chessbookWidget);
        chessbookEdit->setObjectName(QStringLiteral("chessbookEdit"));
        chessbookEdit->setGeometry(QRect(10, 40, 256, 192));
        infoView = new QWidget(centralwidget);
        infoView->setObjectName(QStringLiteral("infoView"));
        infoView->setGeometry(QRect(40, 120, 191, 421));
        boardInfoWidget = new QWidget(infoView);
        boardInfoWidget->setObjectName(QStringLiteral("boardInfoWidget"));
        boardInfoWidget->setGeometry(QRect(10, 270, 171, 141));
        boardInfoLabel = new QLabel(boardInfoWidget);
        boardInfoLabel->setObjectName(QStringLiteral("boardInfoLabel"));
        boardInfoLabel->setGeometry(QRect(10, 10, 151, 31));
        boardInfoEdit = new QTextEdit(boardInfoWidget);
        boardInfoEdit->setObjectName(QStringLiteral("boardInfoEdit"));
        boardInfoEdit->setGeometry(QRect(10, 40, 151, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(16);
        boardInfoEdit->setFont(font);
        boardInfoEdit->setReadOnly(true);
        widgetPlayer1 = new QWidget(infoView);
        widgetPlayer1->setObjectName(QStringLiteral("widgetPlayer1"));
        widgetPlayer1->setGeometry(QRect(10, 10, 171, 101));
        playerLabel1 = new QLabel(widgetPlayer1);
        playerLabel1->setObjectName(QStringLiteral("playerLabel1"));
        playerLabel1->setGeometry(QRect(10, 10, 81, 21));
        blackLabel = new QLabel(widgetPlayer1);
        blackLabel->setObjectName(QStringLiteral("blackLabel"));
        blackLabel->setGeometry(QRect(100, 10, 51, 31));
        playerTimer1 = new QLCDNumber(widgetPlayer1);
        playerTimer1->setObjectName(QStringLiteral("playerTimer1"));
        playerTimer1->setGeometry(QRect(70, 50, 91, 31));
        timeLabel1 = new QLabel(widgetPlayer1);
        timeLabel1->setObjectName(QStringLiteral("timeLabel1"));
        timeLabel1->setGeometry(QRect(10, 50, 54, 31));
        timeLabel1->setAlignment(Qt::AlignCenter);
        widgetPlayer2 = new QWidget(infoView);
        widgetPlayer2->setObjectName(QStringLiteral("widgetPlayer2"));
        widgetPlayer2->setGeometry(QRect(10, 120, 171, 81));
        playerLabel2 = new QLabel(widgetPlayer2);
        playerLabel2->setObjectName(QStringLiteral("playerLabel2"));
        playerLabel2->setGeometry(QRect(10, 10, 81, 21));
        whiteLabel = new QLabel(widgetPlayer2);
        whiteLabel->setObjectName(QStringLiteral("whiteLabel"));
        whiteLabel->setGeometry(QRect(110, 10, 51, 31));
        playerTimer2 = new QLCDNumber(widgetPlayer2);
        playerTimer2->setObjectName(QStringLiteral("playerTimer2"));
        playerTimer2->setGeometry(QRect(70, 40, 91, 31));
        timeLabel2 = new QLabel(widgetPlayer2);
        timeLabel2->setObjectName(QStringLiteral("timeLabel2"));
        timeLabel2->setGeometry(QRect(10, 40, 54, 31));
        timeLabel2->setAlignment(Qt::AlignCenter);
        timeBox = new QComboBox(infoView);
        timeBox->setObjectName(QStringLiteral("timeBox"));
        timeBox->setGeometry(QRect(88, 210, 81, 21));
        timeLimitLabel = new QLabel(infoView);
        timeLimitLabel->setObjectName(QStringLiteral("timeLimitLabel"));
        timeLimitLabel->setGeometry(QRect(10, 210, 61, 21));
        btnReturn = new QToolButton(centralwidget);
        btnReturn->setObjectName(QStringLiteral("btnReturn"));
        btnReturn->setGeometry(QRect(20, 20, 160, 60));
        boardView = new BoardView(centralwidget);
        boardView->setObjectName(QStringLiteral("boardView"));
        boardView->setGeometry(QRect(250, 120, 420, 420));
        Humanplay->setCentralWidget(centralwidget);

        retranslateUi(Humanplay);

        QMetaObject::connectSlotsByName(Humanplay);
    } // setupUi

    void retranslateUi(QMainWindow *Humanplay)
    {
        Humanplay->setWindowTitle(QApplication::translate("Humanplay", "MainWindow", Q_NULLPTR));
        btnBegin->setText(QString());
        btnPause->setText(QString());
        btnExchange->setText(QString());
        btnBack->setText(QString());
        btnLose->setText(QString());
        btnSave->setText(QString());
        chessbookLabel->setText(QString());
        boardInfoLabel->setText(QString());
        boardInfoEdit->setHtml(QApplication::translate("Humanplay", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Adobe \345\256\213\344\275\223 Std L'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        playerLabel1->setText(QString());
        blackLabel->setText(QString());
        timeLabel1->setText(QApplication::translate("Humanplay", "\345\211\251\344\275\231\346\227\266\351\227\264", Q_NULLPTR));
        playerLabel2->setText(QString());
        whiteLabel->setText(QString());
        timeLabel2->setText(QApplication::translate("Humanplay", "\345\211\251\344\275\231\346\227\266\351\227\264", Q_NULLPTR));
        timeLimitLabel->setText(QString());
        btnReturn->setText(QApplication::translate("Humanplay", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Humanplay: public Ui_Humanplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUMANPLAY_H
