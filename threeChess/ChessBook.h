#ifndef CHESSBOOK_H
#define CHESSBOOK_H

/*这是棋谱类，存储了一局棋的所有信息，并包含了当前（最终）的棋盘数据信息，通过棋谱类可以生成任何一个阶段的棋盘信息*/

#include "define.h"
#include "Board.h"
#include <QString>
#include <QVector>
#include <QFile>
#include <QCoreApplication>
#include <QFileDialog>
#include <QDateTime>

class ChessBook
{
public:
    ChessBook();
    ~ChessBook();
public:
    int stepNum = 0;//总步数
    int currentNum = 0;//现在所处的步数

    int winColor = EMPTY;//获胜方颜色 空表示未分胜负
    Player player1,player2; //两个玩家
    bool whiteFlag = false; //是否有一方认输
    bool timeLimit = false; //是否有一方超时
    QString dateTime; //棋盘存储时间

    Step currentStep; //当前的一步棋
    QVector<Step> steps; // 历史棋谱
    Board *board; //当前棋盘信息

public:
    bool getOneStep(Board *theBoard,Step theStep); //走棋
    bool removeOneStep(); //悔棋
    bool chessbookSave(ChessBook *chessbook); //保存棋谱
    bool chessbookOpen(QString thePath); //打开棋谱
    bool chessbookDelete(QString thePath); //删除棋谱
    void clearAllSteps(); //清除空本棋谱steps
    void setCurrentNew(QString theDateTime);//把当前局面设为开始局面，用于在历史局面上下棋

    //文字处理函数
    QString printOneStep(Step s);  //打印一步棋对应的文字描述
    QString printColor(int color); //打印黑白颜色
    QString printCircle(int circle); //打印内、中、外层数
    QString printSeat(int seat); //打印东西南北八方
    QString printChessbookName(ChessBook *chessbook); //打印棋谱文件名
    QString printChessbookPath(QString strname); //打印给定文件名的路径
    QString printChessbookPath(ChessBook *chessbook); //打印棋谱中的路径
    QString printCurrentDayAndTime(); //打印当前日期时间
};

#endif // CHESSBOOK_H
