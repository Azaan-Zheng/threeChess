#ifndef DEFINE_H
#define DEFINE_H

/*以下为一些常用的常数，所有的头文件中都首先包含了本文件*/

#include <QDebug>
#define EMPTY 0//空位置
#define BLACK 1//黑子
#define WHITE 2//白子
#define DEAD 3 //死子
#define BLACK_CHOSEN 4 //已选中的黑子 
#define WHITE_CHOSEN 5 //已选中的白子
#define CHOSEN 6//移动过的空位置
#define VALID 1101

#define CIRCLE 3//圈数
#define SEAT 8//位数
#define POINT 24//落点数
#define HUMAN 21//人类玩家
#define AI 42//AI玩家
#define AI_ALPHA 43
#define AI_MASTER 44
#define READY 1//准备阶段
#define POSE 2//摆棋阶段
#define MOVE 3//走棋阶段
#define OVER 4//棋局结束

#define ACT_POSE 31      //落子
#define ACT_POSE_KILL 32 //扣子
#define ACT_MOVE 33      //移动
#define ACT_MOVE_KILL 34 //提子
#define ACT_CHANGE 35    //换边

#define GAME_MOVE 51 //走棋阶段
#define GAME_CON 52 //本家继续
#define GAME_EXCH 53 //轮到对手
#define GAME_OVER 54 //游戏结束
#define GAME_BEGIN 55//游戏开始

#define LABEL_BEGIN 0 //开局标签
#define LABEL_BLACK 1 //黑胜标签
#define LABEL_WHITE 2 //白胜标签

#define INTRO_BOARD 61 //介绍棋盘
#define INTRO_POSE 62  //介绍落子
#define INTRO_FILL 63  //介绍中盘
#define INTRO_MOVE 64  //介绍走子
#define INTRO_LOSE 65  //介绍输赢

#define CHANGE_COLOR(x) ((x==BLACK)?WHITE:BLACK) //黑白颜色转换


//三种游戏模式和主窗口
#define MODEL_INTRO 11 //规则介绍
#define MODEL_PRAC 22  //练习模式
#define MODEL_HUMAN 33 //对战模式
#define MODEL_LOGIN 44 //主窗口


typedef struct{
    int color;
    int mind;
}Player;

typedef struct{
    int circle;
    int seat;
    int rx;
    int ry;
}PPoint;

typedef struct{
    int colorBefore;
    int colorAfter;
    int circleBefore;
    int seatBefore;
    int circleAfter;
    int seatAfter;
}Move;

typedef struct{
    int subject;
    int action;
    int circleBefore;
    int seatBefore;
    int circleAfter;
    int seatAfter;
}Step;


#endif // DEFINE_H
