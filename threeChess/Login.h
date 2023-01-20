#ifndef LOGIN_H
#define LOGIN_H

/*这是模式选择窗口类*/

#include <QMainWindow>
#include <QPainter>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

public:
    //外观设置
    void paintEvent(QPaintEvent *event); //绘制背景设置

    //控制设置
    void setInitialConnect();

public slots:

    //外观改变
    void changeMusicButton(bool isMusic); //音乐图标改变
    
    
signals:
    void sendModel(int theModel);
    void changeMusic();

private:
    Ui::Login *ui;
    
};

#endif // LOGIN_H
