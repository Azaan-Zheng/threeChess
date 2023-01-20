#ifndef HUMANPLAY_H
#define HUMANPLAY_H

/*这是对战模式窗口类*/

#include "define.h"
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QListWidget>
#include "BoardView.h"

namespace Ui {
class Humanplay;
}

class Humanplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit Humanplay(QWidget *parent = 0);
    ~Humanplay();

    //外观控制
    void paintEvent(QPaintEvent *event); //绘制背景设置
    void setAppearance();//外观设置
    void setPause(bool isPause); //暂停/继续 按钮
    void setBegin(bool isBegin); //开始/结束 按钮

    //信息控制
    void setInitialConnect();
    void setInitialBoard();
    void setInitialChessbook();
    void setInitialPlayers();   //以上 初始化数据
    void setOverBoard(); //设置棋局结束
    void setBeginGame();//设置开始游戏
    void setLoseGame();//设置认输
    void setPauseGame();//设置暂停
    void setChangeSide();//设置换边
    void setSaveGame();//设置保存
    void setBackGame();//设置悔棋
    void setPlayerTime(int color,int theSecond); //设置对局定时器

    void setBoardInfo(QString info);  //设置盘面提示信息
    void setChessbookInfo(QString step); //设置棋谱框添加信息
    void removeOneChessbookInfo(); //从棋谱框删除信息
    void clearChessbook(); //清空棋谱框
    void setChessbookHighLight(int index); //设置棋谱框高亮选中

    //综合控制
    void setNormalClose(); //本模式退出时收尾

    //消息框提示
    void msgGameNotOpen();
    void msgIsPause();
    void msgIsPlaying();
    int msgSetOver();
    int msgSetWhiteFlag();

signals:
    void modelReturn();//返回关闭窗口信号
    void modelPause();//返回暂停信号
    void modelBegin(Player p1,Player p2,int theMinite);//返回开始信号
    void modelBack();//返回悔棋信号
    void modelLose(bool isWhiteFlag,bool isTimeLimit);//返回认输信号
    void modelSave();//返回保存信号
    void modelChangeSide();//返回换边信号
    void modelOver();//返回结束信号


protected:
    virtual void resizeEvent(QResizeEvent *event) override;

public:

    //boardView各项数据
    BoardView *board = nullptr;

    //外观
    int xBoard = 100;
    int yBoard = 100;
    int lBoard = 480;

    //controlView各项数据
    int xControl = 580;
    int yControl = 100;
    int wControl = 400;
    int hControl = 500;
    int hControlWidget = 200;
    int hControlBtn = 30;

    //infoView各项数据
    int xInfo = 20;
    int yInfo = 50;
    int wInfo = 80;
    int hInfo = 500;
    int hInfoWidget = 100;


    //对局信息
    bool isPlaying = false; //是否处于对局中
    bool isThereChessbook = false; //是否有棋谱
    Player player1; //玩家一
    Player player2; //玩家二
    int second = 300; //局时
    
    
private:
    Ui::Humanplay *ui;
};

#endif // HUMANPLAY_H
