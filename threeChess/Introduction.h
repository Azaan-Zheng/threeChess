#ifndef INTRODUCTION_H
#define INTRODUCTION_H

/*这是规则介绍窗口类*/

#include "define.h"
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include "BoardView.h"
#include "ChessBook.h"

namespace Ui {
class Introduction;
}

class Introduction : public QMainWindow
{
    Q_OBJECT

public:
    explicit Introduction(QWidget *parent = 0);
    ~Introduction();

    //外观控制
    void paintEvent(QPaintEvent *event); //绘制背景设置
    void setAppearance();//外观设置

    //信息控制
    void setInitialConnect(); //设置初始连接
    void setBtnNext();//下一步按钮
    void setBtnLast();//上一步按钮
    void setStageFunc(int stage);//设置阶段对应的函数
    void setIntroBoard();//介绍棋盘
    void setIntroPose();//介绍落子
    void setIntroFill();//介绍中盘
    void setIntroMove();//介绍走子
    void setIntroLose();//介绍输赢

    //综合控制
    void setNormalClose(); //设置模式退出
    void clearChessbook(); //设置清空棋谱框
    void takeInChessbook(ChessBook *chessbook); //导入棋谱

signals:
    void modelReturn();//返回关闭窗口信号
    void modelIntroPose(); //返回落子介绍信号——便于交互
    void modelIntroMove(); //返回运子介绍信号——便于交互


protected:
    virtual void resizeEvent(QResizeEvent *event) override;

public:

    int introStage = INTRO_BOARD;

    //boardView各项数据
    BoardView *board;

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

private:
    Ui::Introduction *ui;
};

#endif // INTRODUCTION_H
