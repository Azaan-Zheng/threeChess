#ifndef PIECE_H
#define PIECE_H

/*这是棋子类，在BoardView中含有的棋子即定义于此*/

#include "define.h"
#include <QLabel>

class Piece
{
public:
    Piece(int theColor,int theCircle,int theSeat);
    ~Piece();

public:
    //棋子本身信息 空为默认状态
    int color = EMPTY;
    //棋子坐标
    int circle = -1;
    int seat = -1;
    bool isVisible = false;
    QLabel *mLabel;

};

#endif // PIECE_H
