#include "Controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    setInitialLogin();
    setDatabase();
}

Controller::~Controller()
{
    
}


//数据库控制

void Controller::closeDatabase() //打开数据库
{
    bool isDBopen = db.isOpen();
    if(isDBopen == true)
    {
        db.close();
    }
}

void Controller::openDatabase() //关闭数据库
{
    if(db.isOpen() == false)
    {
        db.open();
    }
}

void Controller::setDatabase() //数据库初始化
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ChessBook.db");
    db.open();

    connect(this,&Controller::destroyed,this,[this](){
        db.close();
    });

    //设置model
    historyModel = new QStandardItemModel(this);
    QSqlQuery query;
    QString strcmd = QString("select * from history");
    query.exec(strcmd);
    while(query.next()){
        QString str = QString(query.value("文件名").toString());
        QStandardItem *item = new QStandardItem(str);
        historyModel->appendRow(item);
    }
    pPrac->setHistoryModel(historyModel);
}

//基本初始化控制

void Controller::setInitialLogin() //初始化
{
    //登录界面初始化
    pLogin = new Login;
    pLogin->setWindowTitle("三三棋");
    pLogin->show();
    model = MODEL_LOGIN;
    //模式选择连接 音效连接
    connect(pLogin,&Login::sendModel,this,&Controller::getModel);
    connect(pLogin,&Login::changeMusic,this,&Controller::changeBackMusic);
    //音效
    soundBackground = new QSound(":/resources/sound/background.wav",this);
    soundBackground->setLoops(-1);
    soundBackground->play();
    soundBegin = new QSound(":/resources/sound/begin.wav",this);
    soundChoose = new QSound(":/resources/sound/choose.wav",this);
    soundDead = new QSound(":/resources/sound/dead.wav",this);
    soundForbidden = new QSound(":/resources/sound/forbidden.wav",this);
    soundGameover = new QSound(":/resources/sound/gameover.wav",this);
    soundPose = new QSound(":/resources/sound/pose.wav",this);
    soundThree = new QSound(":/resources/sound/three.wav",this);

    //走棋
    pGenerator = new Generator;
    //其他内容准备
    pIntro = new Introduction;
    pIntro->setWindowTitle("三三棋——规则介绍");
    pPrac = new Practice;
    pPrac->setWindowTitle("三三棋——练习模式");
    pHuman = new Humanplay;
    pHuman->setWindowTitle("三三棋——双人对战");
    time = new QTimer(this);

    //连接信号槽
    connect(pIntro,&Introduction::modelReturn,this,&Controller::setModelEnd);
    connect(pIntro->board,&BoardView::sendPiece,this,&Controller::playPiece);
    connect(pIntro,&Introduction::modelIntroPose,this,&Controller::setIntroStagePose);
    connect(pIntro,&Introduction::modelIntroMove,this,&Controller::setIntroStageMove);

    connect(pPrac,&Practice::modelReturn,this,&Controller::setModelEnd);
    connect(pPrac->board,&BoardView::sendPiece,this,&Controller::playPiece);
    connect(pPrac,&Practice::modelChangeSide,this,&Controller::setChangeSide);
    connect(pPrac,&Practice::modelLastStep,this,&Controller::setBackPrac);
    connect(pPrac,&Practice::modelNextStep,this,&Controller::setNextPrac);
    connect(pPrac,&Practice::modelSaveChessbook,this,&Controller::setSaveChessbook);
    connect(pPrac,&Practice::modelDeleteChessbook,this,&Controller::setDeleteChessbook);
    connect(pPrac,&Practice::modelOpenChessbook,this,&Controller::setOpenChessbook);

    connect(pHuman->board,&BoardView::sendPiece,this,&Controller::playPiece);
    connect(pHuman,&Humanplay::modelReturn,this,&Controller::setModelEnd);
    connect(pHuman,&Humanplay::modelPause,this,&Controller::setGamePause);
    connect(pHuman,&Humanplay::modelBegin,this,&Controller::setBeginGame);
    connect(pHuman,&Humanplay::modelSave,this,&Controller::setSaveChessbook);
    connect(pHuman,&Humanplay::modelBack,this,&Controller::setBackGame);
    connect(pHuman,&Humanplay::modelLose,this,&Controller::setGameOver);
    connect(pHuman,&Humanplay::modelChangeSide,this,&Controller::setChangeSide);
    connect(pHuman,&Humanplay::modelOver,this,&Controller::setGameOverNoEnd);
    
    connect(time,&QTimer::timeout,this,&Controller::setTimer);

}


void Controller::getModel(int theModel) //获取当前模式
{
    model = theModel;
    if(model == MODEL_INTRO)
    {
        pIntro->show();
        pBoardView = pIntro->board;
        setModelInitial();
        pBoard->currentStage = POSE;
        pLogin->hide();
    }
    else if(model == MODEL_PRAC)
    {
        pPrac->show();
        pBoardView = pPrac->board;
        pBoardView->setOpenWork();
        setModelInitial();
        pBoard->currentStage = POSE;
        pLogin->hide();
    }
    else if(model == MODEL_HUMAN)
    {
        pHuman->show();
        pBoardView = pHuman->board;
        setModelInitial();
        pBoard->currentStage = READY;
        pLogin->hide();
    }
    else
    {
        return;
    }
}

void Controller::setModelInitial() //设置模式初始化
{
    if(pBoard != nullptr){
        delete pBoard;
    }
    pBoard = new Board;
    if(pChessBook != nullptr){
        delete pChessBook;
    }
    pChessBook = new ChessBook;
}

void Controller::setModelEnd() //设置模式结束
{
    this->pLogin->show();
    time->stop();
    model = MODEL_LOGIN;
    delete pBoard;
    pBoard = nullptr;
    delete pChessBook;
    pChessBook = nullptr;

}

//逻辑控制函数

void Controller::playPiece()  //落子信息获取判断入口
{
    PPoint piece = pBoardView->pBoardPoint;
    if(pBoard->currentStage == READY || pBoard->currentStage == OVER){
        sendColorFail();
        return;
    }
    
    if(pBoard->player1.mind != HUMAN && pBoard->currentColor == pBoard->player1.color)
        return;
    if(pBoard->player2.mind != HUMAN && pBoard->currentColor == pBoard->player2.color)
        return;

    if(model == MODEL_INTRO){
        if(pIntro->introStage == INTRO_POSE || pIntro->introStage == INTRO_MOVE){
            playPieceHuman(piece.circle,piece.seat,piece);
            return;
        }
        else
            return;
    }

    if(model == MODEL_PRAC){
        if(pPrac->isStatic == true){
            int changeStatic = msgPracStatic();
            if(changeStatic == QMessageBox::Yes){
                pChessBook->setCurrentNew(printCurrentDayAndTime());
                pPrac->setStaticClose(pChessBook->currentNum - 1);
            }
            return;
        }
        else{
            playPieceHuman(piece.circle,piece.seat,piece);
            pPrac->isThereChessbook = true;
            return;
        }
    }

    if(model == MODEL_HUMAN){
        if(pHuman->isPlaying == false){
            msgRemind(QString("三三棋——对战模式"),QString("温馨提示：请先设置游戏开始"));
            return;
        }
        else if(isPause == true){
            msgRemind(QString("三三棋——对战模式"),QString("温馨提示：游戏处于暂停中，请先结束暂停"));
            return;
        }
        else{
            playPieceHuman(piece.circle,piece.seat,piece);
            return;
        }

    }
}


void Controller::playPieceHuman(int theCircle,int theSeat,PPoint piece) //处理落子
{
     Step step;
     step.subject = pBoard->currentColor;
     step.circleBefore = theCircle;
     step.seatBefore = theSeat;
     step.seatAfter = -1;
     step.circleAfter = -1;
     int outcome = 0;
     if(pBoard->currentStage == POSE){
        if(pBoard->isKilling){
            step.action = ACT_POSE_KILL;
            outcome = pGenerator->setStepNext(step,pBoard);
            if(outcome > 0){
                //棋盘
                pBoardView->freshPiece(pBoard->position,pBoard->pChosen.circle,pBoard->pChosen.seat,step.subject + 3);
                //棋谱
                pChessBook->getOneStep(pBoard,step);
                //音效设置
                soundDead->play();
                playPieceOutcome(outcome);
                setAppendChessbook(step);
            }
            else{
                sendColorFail();
            }
        }
        else{
            step.action = ACT_POSE;
            outcome = pGenerator->setStepNext(step,pBoard);
            if(outcome > 0){
                pBoardView->freshPiece(pBoard->position,theCircle,theSeat,step.subject + 3);
                //棋谱
                pChessBook->getOneStep(pBoard,step);
                //音效设置
                soundPose->play();
                if(pBoard->isKilling)
                    soundThree->play();
                playPieceOutcome(outcome);
                setAppendChessbook(step);
            }
            else{
                sendColorFail();
            }
        }
    }
    else if(pBoard->currentStage == MOVE){
        if(pBoard->isKilling){
            step.action = ACT_MOVE_KILL;
            outcome = pGenerator->setStepNext(step,pBoard);
            if(outcome > 0){
                //棋盘
                pBoardView->freshPiece(pBoard->position,pBoard->pChosen.circle,pBoard->pChosen.seat,step.subject + 3);
                pBoardView->drawPiece(pBoard->pChosenBefore.circle,pBoard->pChosenBefore.seat,CHOSEN);
                //棋谱
                pChessBook->getOneStep(pBoard,step);
                //音效设置
                soundDead->play();

                playPieceOutcome(outcome);
                setAppendChessbook(step);
            }
            else{
                sendColorFail();
            }
        }
        else if(pBoard->isMoving){
            if(theCircle == pBoard->pChosen.circle && theSeat == pBoard->pChosen.seat){
                pBoard->isMoving = false;
                pBoardView->freshPiece(pBoard->position,-1,-1,-1);
                //音效设置
                soundChoose->play();
            }
            else if(pBoard->position[theCircle][theSeat] == pBoard->currentColor){
                pBoard->isMoving = false;
                if(pGenerator->isValidChose(pBoard,theCircle,theSeat)){
                    pBoardView->freshPiece(pBoard->position,theCircle,theSeat,pBoard->currentColor + 3);
                    pBoard->pChosen = piece;
                    pBoard->pChosenBefore.rx = -1;
                    pBoard->isMoving = true;
                    //音效设置
                    soundChoose->play();
                }
                else{
                    pBoard->isMoving = true;
                    sendColorFail();
                }
            }
            else{
                step.action = ACT_MOVE;
                step.circleBefore = pBoard->pChosen.circle;
                step.seatBefore = pBoard->pChosen.seat;
                step.circleAfter = theCircle;
                step.seatAfter = theSeat;
                outcome = pGenerator->setStepNext(step,pBoard);
                if(outcome > 0){
                    //棋盘
                    pBoardView->freshPiece(pBoard->position,theCircle,theSeat,step.subject + 3);
                    pBoardView->drawPiece(step.circleBefore,step.seatBefore,CHOSEN);
                    //棋谱
                    pChessBook->getOneStep(pBoard,step);
                    //音效设置
                    soundPose->play();
                    if(pBoard->isKilling)
                        soundThree->play();
                    playPieceOutcome(outcome);
                    setAppendChessbook(step);
                }
                else{
                    sendColorFail();
                }
            }
        }
        else{
            if(pGenerator->isValidChose(pBoard,theCircle,theSeat)){
                pBoardView->freshPiece(pBoard->position,theCircle,theSeat,pBoard->currentColor + 3);
                pBoard->pChosen = piece;
                pBoard->isMoving = true;
                //音效设置
                soundChoose->play();
            }
            else{
                sendColorFail();
            }
        }
    }
    else
        return;
}

void Controller::playPieceOutcome(int outcome) //将处理结果对应效果展示 音效、动画等
{
    if(outcome == 0){
        sendColorFail();
    }
    else{

        if(outcome == GAME_CON){
            sendColorContinue();
        }
        else if(outcome == GAME_EXCH){
            sendColorExchange();
        }
        else if(outcome == GAME_MOVE){
            sendFromPoseToMove();
        }
        else if(outcome == GAME_OVER){
            setGameOver(false,false);
        }
    }
}



void Controller::setIntroStagePose() //规则介绍——落子阶段
{
    QString str = QString("INTRO_POSE");
    QString path = pChessBook->printChessbookPath(str);
    pChessBook->board = pBoard;
    pChessBook->chessbookOpen(path);
    int colorlight = pBoard->position[pBoard->pChosen.circle][pBoard->pChosen.seat] + 3;
    pBoardView->freshPiece(pBoard->position,pBoard->pChosen.circle,pBoard->pChosen.seat,colorlight);
    pIntro->takeInChessbook(pChessBook);
}


void Controller::setIntroStageMove() //规则介绍——运子阶段
{
    QString str = QString("INTRO_MOVE");
    QString path = pChessBook->printChessbookPath(str);
    pChessBook->board = pBoard;
    pChessBook->chessbookOpen(path);
    int colorlight = pBoard->position[pBoard->pChosen.circle][pBoard->pChosen.seat] + 3;
    pBoardView->freshPiece(pBoard->position,pBoard->pChosen.circle,pBoard->pChosen.seat,colorlight);
    if(pBoard->pChosenBefore.rx == VALID){
        pBoardView->drawPiece(pBoard->pChosenBefore.circle,pBoard->pChosenBefore.seat,CHOSEN);
    }
    pIntro->takeInChessbook(pChessBook);
}


void Controller::setBeginGame(Player p1,Player p2,int theSecond)//开始
{
    setModelInitial();
    pHuman->isPlaying = true;
    pHuman->isThereChessbook = true;
    pHuman->setBegin(pHuman->isPlaying);
    pHuman->clearChessbook();
    //设置棋盘信息
    pBoard->currentStage = POSE;
    pBoard->player1 = p1;
    pBoard->player2 = p2;
    pBoard->currentColor = p1.color;

    //设置棋谱信息
    pChessBook->dateTime = printCurrentDayAndTime();
    pChessBook->player1 = p1;
    pChessBook->player2 = p2;

    //设置棋盘界面
    pBoardView->cleanBoard();
    pBoardView->setOpenWork();

    //设置
    second1 = theSecond;
    second2 = theSecond;
    time->start(1000);

    QString str = QString("%1方开始行棋").arg(printColor(pBoard->currentColor));
    sendInfoStr(str);
    pBoardView->showLabels(LABEL_BEGIN);
    soundBegin->play();
    
}


void Controller::setChangeSide()//换边
{
    Step step;
    int circle,seat;
    if(model == MODEL_PRAC){
        if(pPrac->isStatic){
            int changeStatic = msgPracStatic();
            if(changeStatic != QMessageBox::Yes){
                return;
            }
            else{
                pChessBook->setCurrentNew(printCurrentDayAndTime());
                pPrac->setStaticClose(pChessBook->currentNum - 1);
            }
        }
    }
    else if(model == MODEL_HUMAN){
        if(isPause == true){
            msgRemind(QString("三三棋——对战模式"),QString("温馨提示：游戏处于暂停中，请先结束暂停"));
            return;
        }
    }

    step.action = ACT_CHANGE;
    pBoard->changeSide();
    pChessBook->getOneStep(pBoard,step);
    circle = pBoard->pChosen.circle;
    seat = pBoard->pChosen.seat;
    pBoardView->freshPiece(pBoard->position,circle,seat,pBoard->position[circle][seat] + 3);
    setAppendChessbook(step);
    QString str = QString("双方换边");
    sendInfoStr(str);
    return;
}


void Controller::setSaveChessbook()//保存棋谱
{
    pChessBook->board = pBoard;
    bool isSaved = pChessBook->chessbookSave(pChessBook);
    if(isSaved){
        openDatabase();
        QSqlQuery query;
        QString strname = pChessBook->printChessbookName(pChessBook);
        QString strtime = printCurrentDayAndTime();
        QString strpath = pChessBook->printChessbookPath(pChessBook);
        QString strcmd = QString("insert into history(时间,文件名,文件路径) values('%1','%2','%3')").arg(strtime).arg(strname).arg(strpath);
        query.exec(strcmd);
        QStandardItem *item = new QStandardItem(strname);
        historyModel->appendRow(item);
        msgRemind(QString("三三棋——保存棋谱"),QString("保存成功！"));
    }
    else{
        msgRemind(QString("三三棋——保存棋谱"),QString("保存失败！"));
    }
}

void Controller::setAppendChessbook(Step step) //向棋谱中加入一步棋
{
    QString str = pChessBook->printOneStep(step);
    if(model == MODEL_HUMAN){
        pHuman->setChessbookInfo(str);
    }
    else if(model == MODEL_PRAC){
        pPrac->setChessbookInfo(str);
    }
}


void Controller::setGameOver(bool isWhiteFlag,bool isTimeLimit)//设置棋局结束
{
    //数据设置
    int loseColor = pBoard->currentColor;
    pChessBook->winColor = CHANGE_COLOR(loseColor);
    pChessBook->whiteFlag = isWhiteFlag;
    pChessBook->timeLimit = isTimeLimit;
    time->stop();
    //效果设置
    soundGameover->play();
    pBoardView->showLabels(pChessBook->winColor);
    QString str = QString("对局结束");
    sendInfoStr(str);
    if(model == MODEL_HUMAN){
        pHuman->setOverBoard();
        pHuman->setBegin(false);
        pHuman->isPlaying = false;
    }
    else if(model == MODEL_PRAC){
        pBoard->currentStage = OVER;
    }
}

void Controller::setGameOverNoEnd() //设置在无结局状态下强行结束
{
    //数据设置
    pChessBook->winColor = EMPTY;
    pChessBook->whiteFlag = false;
    pChessBook->timeLimit = false;
    time->stop();
    //效果设置
    soundGameover->play();
    QString str = QString("对局结束");
    sendInfoStr(str);
    pHuman->isPlaying = false;
}

void Controller::setBackGame()//悔棋
{
    if(isPause == true){
        msgRemind(QString("三三棋——对战模式"),QString("温馨提示：游戏处于暂停中，请先结束暂停"));
        return;
    }

    if(pChessBook->currentNum <= 0)
        return;

    if(pBoard->player1.mind == HUMAN && pBoard->player2.mind == HUMAN){
        int outcome = pGenerator->setStepLast(pChessBook,pBoard);
        playPieceOutcome(outcome);
        pChessBook->removeOneStep();
        int circle = pBoard->pChosen.circle;
        int seat = pBoard->pChosen.seat;
        if(circle >= 0 && seat >= 0){
            pBoardView->freshPiece(pBoard->position,circle,seat,pBoard->position[circle][seat] + 3);
        }
        else{
            pBoardView->freshPiece(pBoard->position,-1,-1,-1);
        }
        pHuman->removeOneChessbookInfo();
        return;
    }
}

void Controller::setGamePause()//暂停
{
    if(isPause == false)
    {
        isPause = true;
        time->stop();

    }
    else
    {
        isPause = false;
        time->start(1000);

    }
    pHuman->setPause(isPause);
}

void Controller::setTimer()//倒计时
{
    if(model == MODEL_HUMAN){
        if(pBoard->currentColor == pBoard->player1.color){
            second1--;
            pHuman->setPlayerTime(pBoard->currentColor,second1);
            if(second1 == 0){
                time->stop();
                setGameOver(false,true);
            }
        }
        else if(pBoard->currentColor == pBoard->player2.color){
            second2--;
            pHuman->setPlayerTime(pBoard->currentColor,second2);
            if(second2 == 0){
                time->stop();
                setGameOver(false,true);
            }
        }
    }
}

//练习模式逻辑控制

void Controller::setNextPrac() //下一步
{
    if(pChessBook->currentNum >= pChessBook->stepNum){
        return;
    }
    else{
        Step step = pChessBook->steps[pChessBook->currentNum];
        int ret = pGenerator->setStepNext(step,pBoard);
        playPieceOutcome(ret);

        pChessBook->currentNum++;
        int circle = pBoard->pChosen.circle;
        int seat = pBoard->pChosen.seat;
        if(circle >= 0 && seat >= 0){
            pBoardView->freshPiece(pBoard->position,circle,seat,pBoard->position[circle][seat] + 3);
            if(pBoard->pChosenBefore.rx == VALID){
                pBoardView->drawPiece(pBoard->pChosenBefore.circle,pBoard->pChosenBefore.seat,CHOSEN);
            }
        }
        else{
            pBoardView->freshPiece(pBoard->position,-1,-1,-1);
        }
        pPrac->setChessbookHighLight(pChessBook->currentNum - 1);

        //细节：如果回到最后一步，则不设为静态，可以继续行棋
        if(pChessBook->currentNum == pChessBook->stepNum){
            pPrac->isStatic = false;
        }
    }
}

void Controller::setBackPrac() //上一步
{
    if(pChessBook->currentNum <= 0){
        return;
    }
    else{
        int ret = pGenerator->setStepLast(pChessBook,pBoard);
        playPieceOutcome(ret);
        pChessBook->currentNum--;
        int circle = pBoard->pChosen.circle;
        int seat = pBoard->pChosen.seat;
        if(circle >= 0 && seat >= 0){
            pBoardView->freshPiece(pBoard->position,circle,seat,pBoard->position[circle][seat] + 3);
            if(pBoard->pChosenBefore.rx == VALID){
                pBoardView->drawPiece(pBoard->pChosenBefore.circle,pBoard->pChosenBefore.seat,CHOSEN);
            }
        }
        else{
            pBoardView->freshPiece(pBoard->position,-1,-1,-1);
        }
        pPrac->setChessbookHighLight(pChessBook->currentNum - 1);
    }
}

void Controller::setOpenChessbook(QModelIndex index) //设置打开棋谱
{

    QVariant variant = historyModel->data(index);
    QString name = variant.toString();
    QString path = QString("");
    path = pChessBook->printChessbookPath(name);

    pChessBook->board = pBoard;
    bool isOpened = pChessBook->chessbookOpen(path);
    if(isOpened){
        pPrac->clearChessbook();
        for(int i = 0;i < pChessBook->stepNum;i++){
            Step step = pChessBook->steps.at(i);
            QString strstep = pChessBook->printOneStep(step);
            pPrac->setChessbookInfo(strstep);
        }
        pBoardView->freshPiece(pBoard->position,-1,-1,-1);
        msgRemind(QString("三三棋——打开棋谱"),QString("打开成功！"));
        pPrac->isThereChessbook = true;
        pPrac->isStatic = true;
    }
    else{
        msgRemind(QString("三三棋——打开棋谱"),QString("打开失败！"));
    }
}


void Controller::setDeleteChessbook(QModelIndex index) //设置删除棋谱
{
    QVariant variant = historyModel->data(index);
    QString name = variant.toString();
    QSqlQuery query;
    QString strcmd;
    QString path = pChessBook->printChessbookPath(name);
    pChessBook->board = pBoard;
    bool isDeleted = pChessBook->chessbookDelete(path);
    if(isDeleted){
        strcmd = QString("delete from history where 文件名='%1'").arg(name);
        query.exec(strcmd);
        historyModel->removeRow(index.row());
        msgRemind(QString("三三棋——删除棋谱"),QString("删除成功！"));
    }
    else{
        msgRemind(QString("三三棋——删除棋谱"),QString("删除失败！"));
    }
}

//情景控制

void Controller::changeBackMusic()
{
    if(isBackMusic == true)
    {
        isBackMusic = false;
        soundBackground->stop();
    }
    else
    {
        isBackMusic = true;
        soundBackground->play();
    }
    //将音乐信息返回登陆界面
    pLogin->changeMusicButton(isBackMusic);
}



void Controller::sendColorFail() //发送落子违法信息
{
    soundForbidden->play();
}

void Controller::sendColorContinue() //发送本方继续行棋信息
{
    QString str = QString("%1方需去掉%2方%3子").arg(printColor(pBoard->currentColor)).arg(printColor(CHANGE_COLOR(pBoard->currentColor))).arg(QString::number(pBoard->isKilling));
    sendInfoStr(str);
}

void Controller::sendColorExchange()//发送交换颜色信息
{
    QString str = QString("%1方准备行棋").arg(printColor(pBoard->currentColor));
    sendInfoStr(str);
}

void Controller::sendFromPoseToMove() //发送阶段更改信息
{
    QString str = QString("进入走棋阶段，%1方先行").arg(printColor(pBoard->currentColor));
    soundBegin->play();
    pBoardView->freshPiece(pBoard->position,-1,-1,-1);
    sendInfoStr(str);
}

void Controller::sendInfoStr(QString str) //发送盘面提示
{
    if(model == MODEL_HUMAN){
        pHuman->setBoardInfo(str);
    }
    else if(model == MODEL_PRAC){
        pPrac->setBoardInfo(str);
    }
}



//其他函数
QString Controller::printCurrentDayAndTime() //打印当前的日期时间
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString str = dateTime.toString("yyyy-MM-dd hh-mm-ss");
    return str;
}


int Controller::msgPracStatic() //练习模式消息框
{
    QMessageBox msg;
    QPixmap pix_img = QPixmap(":/resources/image/iconLogo.jpg");
    pix_img = pix_img.scaled(QSize(100,100),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    msg.setIcon(QMessageBox::NoIcon);
    msg.setIconPixmap(pix_img);
    msg.setWindowTitle(QString("三三棋——练习模式"));
    msg.setText(QString("当前正在浏览历史局面，"
                                   "是否在此局面下重新开始？"));
    msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    msg.setDefaultButton(QMessageBox::Yes);
    msg.setButtonText(QMessageBox::Yes, QString("确 定"));
    msg.setButtonText(QMessageBox::No, QString("取 消"));
    int ret = msg.exec();
    return ret;
}


void Controller::msgRemind(QString title,QString content) //自定义消息框
{
    QMessageBox msg;
    QPixmap pix_img = QPixmap(":/resources/image/iconLogo.jpg");
    pix_img = pix_img.scaled(QSize(100,100),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    msg.setIcon(QMessageBox::NoIcon);
    msg.setIconPixmap(pix_img);
    msg.setWindowTitle(title);
    msg.setText(content);
    msg.setStandardButtons(QMessageBox::Yes);
    msg.setDefaultButton(QMessageBox::Yes);
    msg.setButtonText(QMessageBox::Yes, QString("确 定"));
    msg.exec();
}

QString Controller::printColor(int color)
{
    QString str = QString(" ");
    if(color == BLACK){
        str = QString("黑");
    }
    else{
        str = QString("白");
    }
    return str;
}

