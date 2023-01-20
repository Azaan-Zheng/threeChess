#ifndef CONTROLLER_H
#define CONTROLLER_H

/*这是软件的核心部分，它接收四个窗口传递的信息，并根据信息进行逻辑、数据的处理，然后将生成的信息返回到各个窗口中*/

#include <QObject>
#include <QSound>
#include <QMessageBox>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTimer>
#include "define.h"
#include "Login.h"
#include "Introduction.h"
#include "Practice.h"
#include "Humanplay.h"
#include "BoardView.h"
#include "Board.h"
#include "ChessBook.h"
#include "Generator.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
    
public:
    void setInitialLogin();//登录设置 

public:
    //实体对象
    Login *pLogin = nullptr; //登录窗口
    Introduction *pIntro = nullptr;//规则介绍窗口
    Practice *pPrac = nullptr;//练习模式窗口
    Humanplay *pHuman = nullptr; //对战模式窗口
    BoardView *pBoardView = nullptr;//棋盘盘面

    //音乐控制对象
    QSound *soundBackground = nullptr; //背景音乐
    QSound *soundBegin = nullptr;      //开始游戏
    QSound *soundGameover = nullptr;   //结束游戏
    QSound *soundForbidden = nullptr;  //落子违法
    QSound *soundDead = nullptr;       //死子
    QSound *soundPose = nullptr;       //落子
    QSound *soundChoose = nullptr;     //选子
    QSound *soundThree = nullptr;      //成“三”
    

    //数据对象
    Board *pBoard = nullptr;    //棋盘数据
    ChessBook *pChessBook = nullptr;   //棋谱数据
    Generator *pGenerator = nullptr;   //棋谱生成器
    QStandardItemModel *historyModel = nullptr;  //历史棋谱model
    QSqlDatabase db;   //棋谱数据库
    QTimer *time = nullptr;  //定时器
    
    //逻辑模式信息
    int model = EMPTY; //三个模式
        //规则介绍

        //练习

        //对战
    int second1 = 300;
    int second2 = 300;
    
    //情景控制信息
    bool isProcessing = false; //是否正在处理一步棋
    bool isBackMusic = true;   //是否正在播放背景音乐
    bool isPlayMusic = true;   //是否播放棋子声音
    bool isPause = false;      //是否处于对局暂停
    
signals:

public slots:
    //设置数据库
    void setDatabase(); //设置初始数据库
    void openDatabase(); //打开
    void closeDatabase(); //关闭

    //模式控制函数
    void getModel(int theModel);//选择模式
    void setModelInitial();//设置模式初始数据
    void setModelEnd();    //模式结束收尾


    //逻辑控制函数
    void playPiece();   //判断落子入口
    void playPieceHuman(int theCircle,int theSeat,PPoint piece); //处理一步棋
    void playPieceOutcome(int outcome);   //将处理结果对应效果展示 音效、动画等
    
        //介绍逻辑
    void setIntroStagePose(); //介绍落子阶段
    void setIntroStageMove(); //介绍运子阶段

        //对战逻辑
    void setBeginGame(Player p1,Player p2,int theSecond);//开始
    void setGameOver(bool isWhiteFlag,bool isTimeLimit);//设置棋局结束
    void setGameOverNoEnd();
    void setBackGame();//悔棋
    void setGamePause();//暂停
    void setTimer();  //设置定时器

        //练习逻辑
    void setNextPrac();  //棋谱下一步
    void setBackPrac();  //棋谱上一步
    void setOpenChessbook(QModelIndex index); //控制打开棋谱
    void setDeleteChessbook(QModelIndex index); //控制删除棋谱

        //公共逻辑
    void setChangeSide();//换边
    void setSaveChessbook();//保存棋谱
    void setAppendChessbook(Step step); //向棋谱中加入一步棋

    void sendColorFail();//发送摆棋失败信息
    void sendColorContinue();//发送己方继续行棋信息
    void sendColorExchange();//发送对方行棋信息
    void sendFromPoseToMove();//发送进入走棋阶段信息
    void sendInfoStr(QString str);//发送盘面提示信息

    //其他
    QString printCurrentDayAndTime(); //打印当前的日期时间
    QString printColor(int color); //打印颜色
    void changeBackMusic(); //改变背景音乐
    int msgPracStatic();  //练习模式 ： 是否试下消息框
    void msgRemind(QString title,QString content); //自定义消息提示
    
};

#endif // CONTROLLER_H
