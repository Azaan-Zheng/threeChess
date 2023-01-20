#ifndef BOARD_H
#define BOARD_H
#include "define.h"
#include "Piece.h"

/*这是棋盘数据类，存储了当前的一个盘面上所需的所有数据信息，即当前的局势*/

class Board
{
public:
    Board();
    ~Board();

public:
    //棋子数目
    int pieceNum[3] = {0,0,0};
    //盘面 空 黑 白 死 情况
    int position[CIRCLE][SEAT];
    //当前要行棋的颜色
    int currentColor = BLACK;
    //当前的局面阶段
    int currentStage = READY;
    //两个玩家
    Player player1,player2;

    bool isMoving = false;//是否正在处于一步走棋之中
    int isKilling = 0;//是否正在处于一步杀棋之中
    PPoint pChosen; //当前盘面选中的落子点
    PPoint pChosenBefore; //前一步盘面选中的落子点
    
public:
    void getEmpty(); //变为原始空棋盘
    void cleanDead();//清除盘面所有的死子，用于从落子阶段转入运子阶段
    void fillDead(); //将盘面上所有的死子恢复，用于悔棋
    void changeSide(); //设置黑白换边
    PPoint getPoint(int circle,int seat); //将棋盘坐标转换成PPoint坐标



};

#endif // BOARD_H
