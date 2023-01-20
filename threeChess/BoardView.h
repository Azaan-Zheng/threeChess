#ifndef BOARDVIEW_H
#define BOARDVIEW_H

/*这是棋盘视图类，负责棋盘的显示，Introduction Practice Humanplay中各含有一个棋盘视图对象*/

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "define.h"
#include "Piece.h"

class BoardView : public QWidget
{
    Q_OBJECT
public:
    explicit BoardView(QWidget *parent);
    ~BoardView();

public:
    int length = 360;//棋盘边长
    int radius = 20;//棋子半径
    int edge = 60;//格子边长

    PPoint pBoardPoint;//落点

    QGraphicsOpacityEffect *opacities[3];
    QPropertyAnimation *animations[3]; //三个动画设置开始、黑胜、白胜
    QLabel *labels[3]; //开始、黑胜、白胜标签

    Piece *pieces[CIRCLE][SEAT][7]; //棋盘中的棋子


public:
    //初始化控制
    void setBoardViewInitial(); //初始化棋盘界面
    void setOpenWork(); //设置棋盘接受落点
    void setStopWork(); //设置棋盘不接受落点

    //绘制控制
    void paintEvent(QPaintEvent *event);//绘制棋盘
    void mousePressEvent(QMouseEvent *event);//获取棋盘上点击的落点
    void updateBoardSize();//更新棋盘尺寸 棋子位置
    void drawPiece(int circle,int seat,int color);//更新一个落点的棋子
    void freshPiece(int position[CIRCLE][SEAT],int rx,int ry,int color);//更新所有落点的棋子
    void cleanBoard(); //使得棋盘均恢复空位置
    void showLabels(int label); //控制动画标签打开
    

    QPoint getCenter(int circle,int seat);//返回棋盘行列交点对应的像素坐标
    QPoint getCenter(PPoint pPoint);//返回棋盘行列交点对应的像素坐标
    PPoint getPoint(QPoint pRelate);//返回相对坐标对应的行列PPoint坐标
    PPoint getPoint(int circle,int seat); //返回棋盘行列交点对应的PPoint坐标

private:
    bool isWorking = false; //控制棋盘是否工作，当false时不接受鼠标的点击

signals:
    void sendPiece();

};

#endif // BOARDVIEW_H
