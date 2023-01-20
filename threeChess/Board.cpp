#include "Board.h"

Board::Board()
{
    getEmpty();

}

Board::~Board()
{
    
}

void Board::getEmpty() //变为原始空棋盘
{
    int i,j;
    for(i = 0;i < CIRCLE;i++){
        for(j = 0;j < SEAT;j++){
            position[i][j] = EMPTY;
        }
    }
    player1.color = BLACK;
    player2.color = WHITE;
    player1.mind = HUMAN;
    player2.mind = HUMAN;
    currentColor = BLACK;
    currentStage = READY;
    pieceNum[0] = 0;
    pieceNum[1] = 0;
    pieceNum[2] = 0;
    isMoving = false;
    isKilling = 0;
}

void Board::cleanDead() //清除盘面所有的死子，用于从落子阶段转入运子阶段
{
    int i,j;
    for(i = 0;i < CIRCLE;i++){
        for(j = 0;j < SEAT;j++){
            if(position[i][j] == DEAD){
                position[i][j] = EMPTY;
            }
        }
    }
}

void Board::fillDead() //将盘面上所有的死子恢复，用于悔棋
{
    int i,j;
    for(i = 0;i < CIRCLE;i++){
        for(j = 0;j < SEAT;j++){
            if(position[i][j] == EMPTY){
                position[i][j] = DEAD;
            }
        }
    }
}

void Board::changeSide() //设置黑白换边
{
    int i,j;
    Player pTmp = player1;
    player1 = player2;
    player2 = pTmp;
    pieceNum[BLACK] = 0;
    pieceNum[WHITE] = 0;
    for(i = 0;i < CIRCLE;i++){
        for(j = 0;j < SEAT;j++){
            if(position[i][j] == BLACK){
                pieceNum[WHITE]++;
                position[i][j] = WHITE;
            }
            else if(position[i][j] == WHITE){
                pieceNum[BLACK]++;
                position[i][j] = BLACK;
            }
        }
    }
    currentColor = CHANGE_COLOR(currentColor);
}


PPoint Board::getPoint(int circle,int seat) //将棋盘坐标转换成PPoint坐标
{
    PPoint pTmp;
    pTmp.circle = circle;
    pTmp.seat = seat;
    int length = circle + 1;
    if(seat <= 4){
        if(seat > 2){
            pTmp.rx = 3 - circle + 2 * length;
            pTmp.ry = (3 - circle) + (seat - 2) * length;
        }
        else{
            pTmp.rx = (3 - circle) + seat * length;
            pTmp.ry = 3 - circle;
        }
    }
    else{
        if(seat > 6){
            pTmp.rx = 3 - circle;
            pTmp.ry =  3 - circle + (8 - seat) * length;
        }
        else{
            pTmp.rx = (3 - circle) + (6 - seat) * length;
            pTmp.ry = (3 - circle) + 2 * length;
        }
    }
    return pTmp;
}





