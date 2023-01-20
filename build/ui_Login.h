/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QLabel *loginImage;
    QLabel *loginTitle;
    QToolButton *loginIntroduction;
    QToolButton *loginPractice;
    QToolButton *loginHuman;
    QToolButton *loginMusic;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        Login->setMinimumSize(QSize(800, 600));
        Login->setMaximumSize(QSize(800, 600));
        Login->setStyleSheet(QLatin1String("QLabel#loginImage{\n"
"	image:url(:/resources/image/logo.jpg);\n"
"	height:440px;\n"
"	width:440px;\n"
"}\n"
"\n"
"QLabel#loginTitle{\n"
"	image:url(:/resources/image/loginTitle.png);\n"
"	height:90px;\n"
"}\n"
"\n"
"QToolButton#loginMusic{\n"
"	border-image:url(:/resources/image/musicYes.png);\n"
"}\n"
"\n"
"QToolButton#loginIntroduction{\n"
"	border-image:url(:/resources/image/loginIntroduction.png);\n"
"}\n"
"QToolButton#loginIntroduction:hover{\n"
"	border-image:url(:/resources/image/loginIntroduction1.png);\n"
"}\n"
"\n"
"QToolButton#loginPractice{\n"
"	border-image:url(:/resources/image/loginPractice.png);\n"
"}\n"
"QToolButton#loginPractice:hover{\n"
"	border-image:url(:/resources/image/loginPractice1.png);\n"
"}\n"
"\n"
"QToolButton#loginHuman{\n"
"	border-image:url(:/resources/image/loginHuman.png);\n"
"}\n"
"QToolButton#loginHuman:hover{\n"
"	border-image:url(:/resources/image/loginHuman1.png);\n"
"}\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        loginImage = new QLabel(centralwidget);
        loginImage->setObjectName(QStringLiteral("loginImage"));
        loginImage->setGeometry(QRect(40, 140, 420, 420));
        loginImage->setFrameShadow(QFrame::Plain);
        loginImage->setLineWidth(1);
        loginTitle = new QLabel(centralwidget);
        loginTitle->setObjectName(QStringLiteral("loginTitle"));
        loginTitle->setGeometry(QRect(16, 19, 600, 88));
        loginIntroduction = new QToolButton(centralwidget);
        loginIntroduction->setObjectName(QStringLiteral("loginIntroduction"));
        loginIntroduction->setGeometry(QRect(530, 260, 200, 50));
        loginIntroduction->setToolButtonStyle(Qt::ToolButtonIconOnly);
        loginPractice = new QToolButton(centralwidget);
        loginPractice->setObjectName(QStringLiteral("loginPractice"));
        loginPractice->setGeometry(QRect(530, 370, 200, 50));
        loginHuman = new QToolButton(centralwidget);
        loginHuman->setObjectName(QStringLiteral("loginHuman"));
        loginHuman->setGeometry(QRect(530, 480, 200, 50));
        loginMusic = new QToolButton(centralwidget);
        loginMusic->setObjectName(QStringLiteral("loginMusic"));
        loginMusic->setGeometry(QRect(710, 50, 40, 40));
        Login->setCentralWidget(centralwidget);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "MainWindow", Q_NULLPTR));
        loginImage->setText(QString());
        loginTitle->setText(QString());
        loginIntroduction->setText(QString());
        loginPractice->setText(QString());
        loginHuman->setText(QString());
        loginMusic->setText(QApplication::translate("Login", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
