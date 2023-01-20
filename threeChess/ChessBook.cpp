#include "ChessBook.h"

ChessBook::ChessBook()
{
    dateTime = printCurrentDayAndTime();
}

ChessBook::~ChessBook()
{

}


bool ChessBook::getOneStep(Board *theBoard,Step theStep)//走棋
{
    steps.append(theStep);
    stepNum++;
    currentNum = stepNum;
    player1 = theBoard->player1;
    player2 = theBoard->player2;
    return true;
}

bool ChessBook::removeOneStep()//悔棋
{
    currentNum--;
    steps.remove(currentNum);
    stepNum = currentNum;
}

void ChessBook::setCurrentNew(QString theDateTime)
{
    winColor = EMPTY;
    whiteFlag = false;
    timeLimit = false;

    dateTime = theDateTime;
    if(stepNum > currentNum && currentNum > 0){
        steps.remove(currentNum,stepNum - currentNum);
        currentStep = steps.at(currentNum - 1);
    }
    stepNum = currentNum;
}

void ChessBook::clearAllSteps() //清除空本棋谱steps
{
    steps.clear();
}


bool ChessBook::chessbookSave(ChessBook *chessbook)//保存棋谱
{
    QString path = printChessbookPath(chessbook);
    QFile file(path);

    bool isOpened = file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(isOpened){

        //写入第一行基本数据
        int whiteflag = (chessbook->whiteFlag == true ? 1 : 0);
        int timelimit = (chessbook->timeLimit == true ? 1 : 0);
        int p1color = chessbook->player1.color;
        int p1mind = chessbook->player1.mind;
        int p2color = chessbook->player2.color;
        int p2mind = chessbook->player2.mind;
        QString line = QString("%1####%2####%3####%4####%5####%6####%7####%8").arg(chessbook->dateTime).arg(QString::number(chessbook->winColor))
                .arg(QString::number(whiteflag)).arg(QString::number(timelimit)).arg(QString::number(p1color)).arg(QString::number(p1mind)).arg(QString::number(p2color)).arg(QString::number(p2mind));
        QByteArray str = line.toUtf8();
        file.write(str);

        //写入第二行棋盘数据
        int empty = board->pieceNum[EMPTY];
        int black = board->pieceNum[BLACK];
        int white = board->pieceNum[WHITE];
        int color = board->currentColor;
        int stage = board->currentStage;
        int moving = (board->isMoving == true) ? 1 : 0;
        int killing = board->isKilling;
        line = QString("\n%1####%2####%3####%4####%5####%6####%7").arg(QString::number(empty)).arg(QString::number(black))
                .arg(QString::number(white)).arg(QString::number(color)).arg(QString::number(stage)).arg(QString::number(moving)).arg(QString::number(killing));
        str = line.toUtf8();
        file.write(str);

        //写入第三行落子数据
        line = QString("\n%1####%2####%3####%4####%5").arg(QString::number(board->pChosen.circle)).arg(QString::number(board->pChosen.seat)).arg(QString::number(board->pChosenBefore.rx))
                .arg(QString::number(board->pChosenBefore.circle)).arg(QString::number(board->pChosenBefore.seat));
        str = line.toUtf8();
        file.write(str);

        //写入终盘落子位置
        line = QString("");
        for(int i = 0;i < CIRCLE;i++){
            line.append("\n");
            for(int j = 0;j < SEAT;j++){
                line.append(QString::number(chessbook->board->position[i][j]));
                line.append(QString(" "));
            }
        }
        str = line.toUtf8();
        file.write(str);

        //写入所有棋谱
        Step s;
        for(int i = 0;i < stepNum;i++){
            s = chessbook->steps.at(i);
            line = QString("\n%1 %2 %3 %4 %5 %6").arg(QString::number(s.subject)).arg(QString::number(s.action))
                    .arg(QString::number(s.circleBefore)).arg(QString::number(s.seatBefore)).arg(QString::number(s.circleAfter)).arg(QString::number(s.seatAfter));
            str = line.toUtf8();
            file.write(str);
        }
        file.close();
        return true;
    }
    else{
        return false;
    }
}

bool ChessBook::chessbookOpen(QString thePath) //打开棋谱
{
    QFile file(thePath);
    bool isOpened = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if(isOpened){
        stepNum = 0;
        currentNum = 0;
        clearAllSteps();
        //获取第一行基本数据
        QByteArray title = file.readLine();
        QString strtitle = QString(title);
        dateTime = strtitle.section("####",0,0);
        winColor = strtitle.section("####",1,1).toInt();
        int whiteflag = strtitle.section("####",2,2).toInt();
        whiteFlag = (whiteflag == 1) ? true : false;
        int timelimit = strtitle.section("####",3,3).toInt();
        timeLimit = (timelimit == 1) ? true : false;
        player1.color = strtitle.section("####",4,4).toInt();
        player1.mind = strtitle.section("####",5,5).toInt();
        player2.color = strtitle.section("####",6,6).toInt();
        player2.mind = strtitle.section("####",7,7).toInt();
        board->player1 = player1;
        board->player2 = player2;

        //获取第二行棋盘数据
        QByteArray info = file.readLine();
        QString strinfo = QString(info);
        board->pieceNum[EMPTY] = strinfo.section("####",0,0).toInt();
        board->pieceNum[BLACK] = strinfo.section("####",1,1).toInt();
        board->pieceNum[WHITE] = strinfo.section("####",2,2).toInt();
        board->currentColor = strinfo.section("####",3,3).toInt();
        board->currentStage = strinfo.section("####",4,4).toInt();
        board->isMoving = (strinfo.section("####",5,5).toInt() == 1) ? true : false;
        board->isKilling = strinfo.section("####",6,6).toInt();

        //获取第三行落子点数据
        QByteArray point = file.readLine();
        QString strpoint = QString(point);
        board->pChosen.circle = strpoint.section("####",0,0).toInt();
        board->pChosen.seat = strpoint.section("####",1,1).toInt();
        board->pChosenBefore.rx = strpoint.section("####",2,2).toInt();
        board->pChosenBefore.circle = strpoint.section("####",3,3).toInt();
        board->pChosenBefore.seat = strpoint.section("####",4,4).toInt();

        //获取终盘位置
        for(int i = 0;i < CIRCLE;i++){
            QByteArray line = file.readLine();
            QString str = QString(line);
            for(int j = 0;j < SEAT;j++){
                board->position[i][j] = str.section(" ",j,j).toInt();
            }
        }

        //获取所有棋谱
        while(file.atEnd() == false){
            Step step;
            QByteArray line = file.readLine();
            QString str = QString(line);
            step.subject = str.section(" ",0,0).toInt();
            step.action = str.section(" ",1,1).toInt();
            step.circleBefore = str.section(" ",2,2).toInt();
            step.seatBefore = str.section(" ",3,3).toInt();
            step.circleAfter = str.section(" ",4,4).toInt();
            step.seatAfter = str.section(" ",5,5).toInt();
            steps.append(step);
            stepNum++;
            currentNum++;
        }
        file.close();
        return true;
    }
    else{
        return false;
    }
}

bool ChessBook::chessbookDelete(QString thePath) //删除棋谱
{
    bool isRemoved = QFile::remove(thePath);
    return isRemoved;
}

//打印文本操作

QString ChessBook::printOneStep(Step s) //打印一步棋对应文字描述
{
    QString str;
    if(s.action  == ACT_CHANGE){
        str = QString("双方换边");
    }
    else if(s.action == ACT_POSE){
        str = QString("%1方 落子 %2%3").arg(printColor(s.subject)).arg(printCircle(s.circleBefore)).arg(printSeat(s.seatBefore));
    }
    else if(s.action == ACT_POSE_KILL){
        str = QString("%1方 扣子 %2%3").arg(printColor(s.subject)).arg(printCircle(s.circleBefore)).arg(printSeat(s.seatBefore));
    }
    else if(s.action == ACT_MOVE_KILL){
        str = QString("%1方 提子 %2%3").arg(printColor(s.subject)).arg(printCircle(s.circleBefore)).arg(printSeat(s.seatBefore));
    }
    else if(s.action == ACT_MOVE){
        str = QString("%1方 运子 %2%3 至 %4%5").arg(printColor(s.subject)).arg(printCircle(s.circleBefore)).arg(printSeat(s.seatBefore)).arg(printCircle(s.circleAfter)).arg(printSeat(s.seatAfter));
    }
    else{
        str = QString("");
    }
    return str;
}


QString ChessBook::printColor(int color) //打印黑白两色
{
    QString str = QString("");
    if(color == BLACK){
        str = QString("黑");
    }
    else{
        str = QString("白");
    }
    return str;
}

QString ChessBook::printSeat(int seat) //打印东西南北八方
{
    QString str = QString("");
    switch (seat) {
        case 0:
            str = QString("西北");
            break;
        case 1:
            str = QString("正北");
            break;
        case 2:
            str = QString("东北");
            break;
        case 3:
            str = QString("正东");
            break;
        case 4:
            str = QString("东南");
            break;
        case 5:
            str = QString("正南");
            break;
        case 6:
            str = QString("西南");
            break;
        case 7:
            str = QString("正西");
            break;
        default:
            break;
    }
    return str;
}

QString ChessBook::printCircle(int circle) //打印内中外三层
{
    QString str = QString("");
    switch (circle) {
        case 0:
            str = QString("内");
            break;
        case 1:
            str = QString("中");
            break;
        case 2:
            str = QString("外");
            break;
        default:
            break;
    }
    return str;
}


QString ChessBook::printChessbookName(ChessBook *chessbook) //打印棋谱对应文件名
{
    QString winner;
    if(chessbook->winColor == EMPTY){
        winner = QString("无结果");
    }
    else{
        winner = QString("%1胜").arg(printColor(chessbook->winColor));
    }
    chessbook->dateTime = printCurrentDayAndTime();
    QString strname = QString("%1 %2").arg(chessbook->dateTime).arg(winner);
    return strname;
}

QString ChessBook::printChessbookPath(ChessBook *chessbook) //打印棋谱路径
{
    QString strname = printChessbookName(chessbook);
    QString path = QCoreApplication::applicationDirPath();
    path.append(QString("/data/%1.txt").arg(strname));
    return path;
}

QString ChessBook::printChessbookPath(QString strname) //打印棋谱路径
{
    QString path = QCoreApplication::applicationDirPath();
    path.append(QString("/data/%1.txt").arg(strname));
    return path;
}

QString ChessBook::printCurrentDayAndTime() //打印当前的日期时间
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString str = dateTime.toString("yyyy-MM-dd hh-mm-ss");
    return str;
}
