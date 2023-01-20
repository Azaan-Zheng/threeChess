#ifndef GENERATOR_H
#define GENERATOR_H

/*这是行棋处理生成器类，通过对盘面Board和棋谱ChessBook的信息的处理，可以做出符合三三棋规则的判断，或返回相关信息*/

#include "Board.h"
#include "ChessBook.h"


class Generator
{
public:
    Generator();
    ~Generator();
    

    bool isValidPoint(Board *pBoard,int theCircle,int theSeat);//判断当前盘面下 落点是否合法
    bool isValidKill(Board *pBoard,int theCircle,int theSeat);//判断 提子/扣子 是否合法
    bool isValidPose(Board *pBoard,int theCircle,int theSeat);//判断 摆棋 是否合法
    bool isValidChose(Board *pBoard,int theCircle,int theSeat);//判断选子是否合法
    bool isValidChose(Board *pBoard,int theCircle,int theSeat,int theColor);
    bool isValidMove(Board *pBoard,Step theStep);
    bool isValidMove(Board *pBoard,Move theMove);//判断当前盘面下 走棋 是否合法
    bool isUnableMove(Board *pBoard,int color); //判断是否被堵死

    int isGetThree(Board *pBoard,int theCircle,int theSeat); //判断有几个三

    int setStepNext(Step s,Board *theBoard);//棋盘数据 下一步
    int setStepLast(ChessBook *c,Board *theBoard);//棋盘数据 上一步
    int setAfterPose(Board *theBoard);//棋盘数据处理 摆棋
    int setAfterMove(Board *theBoard);//棋盘数据处理 走棋
};

#endif // GENERATOR_H
