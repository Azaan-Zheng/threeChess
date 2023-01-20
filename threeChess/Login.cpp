#include "Login.h"
#include "ui_Login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setInitialConnect();
}

Login::~Login()
{
    delete ui;
}


void Login::paintEvent(QPaintEvent *event) //绘制背景
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/resources/image/background.jpg"),QRect());
}

void Login::changeMusicButton(bool isMusic) //设置音效
{
    if(isMusic == true)
    {
        ui->loginMusic->setStyleSheet("QToolButton#loginMusic{"
                                      "border-image:url(:/resources/image/musicYes.png);}");
    }
    else
    {
        ui->loginMusic->setStyleSheet("QToolButton#loginMusic{"
                                      "border-image:url(:/resources/image/musicNo.png);}");
    }
}

void Login::setInitialConnect() //设置初始化连接
{
    connect(ui->loginIntroduction,&QToolButton::clicked,this,[this](){
        sendModel(11);
    });
    connect(ui->loginPractice,&QToolButton::clicked,this,[this](){
        sendModel(22);
    });
    connect(ui->loginHuman,&QToolButton::clicked,this,[this](){
        sendModel(33);
    });
    
    connect(ui->loginMusic,&QToolButton::clicked,this,&Login::changeMusic);
}








