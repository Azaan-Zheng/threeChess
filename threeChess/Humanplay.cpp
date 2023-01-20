#include "Humanplay.h"
#include "ui_Humanplay.h"

Humanplay::Humanplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Humanplay)
{
    ui->setupUi(this);
    setAppearance();
    setInitialConnect();
    setInitialBoard();
    setInitialChessbook();
    setInitialPlayers();
}

Humanplay::~Humanplay()
{
    delete ui;
}


void Humanplay::paintEvent(QPaintEvent *event) //背景绘制
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/resources/image/background.jpg"),QRect());
}

void Humanplay::resizeEvent(QResizeEvent *event) //界面空间大小设置：根据窗口的大小按比例调整
{
    Q_UNUSED(event);
    //获取当前窗口大小
    int x = this->frameGeometry().width();
    int y = this->frameGeometry().height();
    //设置Board窗口
    xBoard = (int)(0.23 * x);
    yBoard = (int)(0.05 * y);
    lBoard = (int)((y - 20) * 0.9);
    if(lBoard > 0.54 * x){
        lBoard = 0.54 * x;
        yBoard = (int)((y - lBoard) / 2);
    }
    ui->boardView->setGeometry(QRect(xBoard,yBoard,lBoard,lBoard));
    ui->boardView->updateBoardSize();
    //设置Control窗口
    wControl = (int)((x - 0.88 * lBoard - xBoard) * 0.7);
    xControl = x - (int)((x - 0.88 * lBoard - xBoard) * 0.85);
    yControl = yBoard;
    hControl = lBoard;
    hControlWidget = (int)(0.32 * lBoard);
    ui->controlView->setGeometry(QRect(xControl,yControl,wControl,hControl));

        //控制按钮和控件
    ui->controlWidget->setGeometry(QRect(0,hControl - hControlWidget,wControl,hControlWidget));
    hControlBtn = (int)(hControlWidget / 3.4 * 0.6);
    int yBlock = (int)(hControlWidget / 3.4 * 0.4);
    int xBlock = (int)((wControl - 6 * hControlBtn) / 4.0);
    ui->btnBegin->setGeometry(QRect(xBlock,yBlock,hControlBtn * 3,hControlBtn));
    ui->btnPause->setGeometry(QRect(3 * xBlock + 3 * hControlBtn,yBlock,hControlBtn * 3,hControlBtn));
    ui->btnExchange->setGeometry(QRect(xBlock,2 * yBlock + hControlBtn,hControlBtn * 3,hControlBtn));
    ui->btnBack->setGeometry(QRect(3 * xBlock + 3 * hControlBtn,2 * yBlock + hControlBtn,hControlBtn * 3,hControlBtn));
    ui->btnLose->setGeometry(QRect(xBlock,3 * yBlock + 2 * hControlBtn,hControlBtn * 3,hControlBtn));
    ui->btnSave->setGeometry(QRect(3 * xBlock + 3 * hControlBtn,3 * yBlock + 2 * hControlBtn,hControlBtn * 3,hControlBtn));

        //控制棋谱
    int yBar = (int)((wControl - 2 * xBlock) / 6.0);
    ui->chessbookWidget->setGeometry(QRect(xBlock,0,wControl - 2 * xBlock,hControl - hControlWidget));
    ui->chessbookLabel->setGeometry(QRect(4,4,wControl - 2 * xBlock - 8,yBar));
    ui->chessbookEdit->setGeometry(QRect(4,4 + yBar,wControl - 2 * xBlock - 8,hControl - hControlWidget - yBar - 8));

    //设置左部大小
    wInfo = (int)((xBoard + 0.1 * lBoard) * 0.7);
    xInfo = (int)((xBoard + 0.1 * lBoard) * 0.15);
    yInfo = yBoard + (int)(lBoard * 0.12);
    hInfo = (int)(lBoard * 0.88);
    ui->infoView->setGeometry(QRect(xInfo,yInfo,wInfo,hInfo));
    yBar = (int)(wInfo / 6.0);

    hInfoWidget = (int)(0.2 * lBoard);
    ui->boardInfoWidget->setGeometry(QRect(0,hInfo - yBlock - hInfoWidget,wInfo,hInfoWidget));
    ui->boardInfoLabel->setGeometry(QRect(4,4,wInfo - 8,yBar));
    ui->boardInfoEdit->setGeometry(QRect(4,4 + yBar,wInfo - 8, hInfoWidget - yBar - 8));

    int hPlayerWidget = (int)((hInfo - yBlock - hInfoWidget - yBlock - yBar - 4 * yBlock) / 2) - yBlock;
    ui->widgetPlayer1->setGeometry(QRect(0,0,wInfo,hPlayerWidget));
    ui->widgetPlayer2->setGeometry(QRect(0,hPlayerWidget + yBlock ,wInfo,hPlayerWidget));
    ui->playerLabel1->setGeometry(QRect(0,0,3 * yBar,yBar));
    ui->blackLabel->setGeometry(QRect(wInfo - yBar,0,yBar,yBar));
    ui->playerLabel2->setGeometry(QRect(0,0,3 * yBar,yBar));
    ui->whiteLabel->setGeometry(QRect(wInfo - yBar,0,yBar,yBar));

    int hTime = hPlayerWidget - yBar - yBlock;
    int wTime = 3 * hTime - 15;
    ui->timeLabel1->setGeometry(QRect(0,yBar + yBlock,wTime,hTime));
    ui->playerTimer1->setGeometry(QRect(wTime,yBar + yBlock,wInfo - wTime,hTime));
    ui->timeLabel2->setGeometry(QRect(0,yBar + yBlock,wTime,hTime));
    ui->playerTimer2->setGeometry(QRect(wTime,yBar + yBlock,wInfo - wTime,hTime));

    int labelTimeWidth = (int)(2.2 * yBar);
    ui->timeLimitLabel->setGeometry(QRect(0,2 * hPlayerWidget + 2 * yBlock,labelTimeWidth,yBar));
    ui->timeBox->setGeometry(QRect(3 * yBar,2 * hPlayerWidget + 2 * yBlock + 3,wInfo - 3 * yBar,yBar - 6));
}

void Humanplay::setAppearance() //设置初始化外观
{
    this->setMinimumWidth(1000);
    this->setMinimumHeight(600);
    ui->boardInfoEdit->setFontWeight(QFont::Bold);
    ui->boardInfoEdit->setFontFamily("楷体");
    ui->boardInfoEdit->setAlignment(Qt::AlignHCenter);
    QFont font ("楷体",18,90);
    ui->timeLabel1->setFont(font);
    ui->timeLabel2->setFont(font);
    ui->playerTimer1->display(QString("00:00"));
    ui->playerTimer2->display(QString("00:00"));
}

void Humanplay::setPause(bool isPause) //暂停/继续切换
{
    if(isPause == false)
    {
        ui->btnPause->setStyleSheet("QToolButton#btnPause"
                                    "{border-image:url(:/resources/image/btnPause.png);}"
                                    "QToolButton#btnPause:hover"
                                    "{border-image:url(:/resources/image/btnPause1.png); }");
    }
    else
    {
        ui->btnPause->setStyleSheet("QToolButton#btnPause"
                                    "{border-image:url(:/resources/image/btnPause2.png);}"
                                    "QToolButton#btnPause:hover"
                                    "{border-image:url(:/resources/image/btnPause3.png); }");
    }
}

void Humanplay::setBegin(bool isBegin)//开始/结束切换
{
    if(isBegin == false)
    {
        ui->btnBegin->setStyleSheet("QToolButton#btnBegin"
                                    "{border-image:url(:/resources/image/btnBegin.png);}"
                                    "QToolButton#btnBegin:hover"
                                    "{border-image:url(:/resources/image/btnBegin1.png); }");
    }
    else
    {
        ui->btnBegin->setStyleSheet("QToolButton#btnBegin"
                                    "{border-image:url(:/resources/image/btnBegin2.png);}"
                                    "QToolButton#btnBegin:hover"
                                    "{border-image:url(:/resources/image/btnBegin3.png); }");
    }
}

//初始化控制

void Humanplay::setInitialConnect()
{   
    board = ui->boardView;//便于连接棋盘
    connect(ui->btnReturn,&QToolButton::clicked,this,&Humanplay::setNormalClose);
    connect(ui->btnPause,&QToolButton::clicked,this,&Humanplay::setPauseGame);
    connect(ui->btnBack,&QToolButton::clicked,this,&Humanplay::setBackGame);
    connect(ui->btnExchange,&QToolButton::clicked,this,&Humanplay::setChangeSide);
    connect(ui->btnSave,&QToolButton::clicked,this,&Humanplay::setSaveGame);
    connect(ui->btnBegin,&QToolButton::clicked,this,&Humanplay::setBeginGame);
    connect(ui->btnLose,&QToolButton::clicked,this,&Humanplay::setLoseGame);
}

void Humanplay::setInitialBoard()
{
    player1.color = BLACK;
    player1.mind = HUMAN;
    player2.color = WHITE;
    player2.mind = HUMAN;
    second = 300;
}

void Humanplay::setInitialChessbook()
{
    ui->chessbookEdit->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Humanplay::setInitialPlayers()
{
    ui->timeBox->addItem(QString("5 分钟"));
    ui->timeBox->addItem(QString("10分钟"));
    ui->timeBox->addItem(QString("20分钟"));
    ui->timeBox->addItem(QString("30分钟"));
}

//信息控制

void Humanplay::setOverBoard() //设置棋局结束
{
    isPlaying = false;
}

void Humanplay::setNormalClose() //设置模式结束
{
    this->board->cleanBoard();
    clearChessbook();
    this->ui->boardInfoEdit->setText(QString(""));
    ui->playerTimer1->display(QString("00:00"));
    ui->playerTimer2->display(QString("00:00"));
    player1.color = BLACK;
    player1.mind = HUMAN;
    player2.color = WHITE;
    player2.mind = HUMAN;
    setPause(false);
    setBegin(false);
    isPlaying = false;
    isThereChessbook = false;
    board->setStopWork();
    second = 300;
    modelReturn();
    this->hide();
}


void Humanplay::setBeginGame()//设置开始游戏
{
    if(isPlaying == false){
        if(ui->timeBox->currentIndex() == 0){
            second = 300;
        }
        else if(ui->timeBox->currentIndex() == 1){
            second = 600;
        }
        else if(ui->timeBox->currentIndex() == 2){
            second = 1200;
        }
        else if(ui->timeBox->currentIndex() == 3){
            second = 1800;
        }
        modelBegin(player1,player2,second);
        setPlayerTime(WHITE,second);
        setPlayerTime(BLACK,second);
    }
    else{
        int res = msgSetOver();
        if(res == QMessageBox::Yes){
            modelOver();
            isPlaying = false;
            setBegin(isPlaying);
        }
    }
}

void Humanplay::setLoseGame()//设置认输
{
    if(isPlaying == true){
        int res = msgSetWhiteFlag();
        if(res == QMessageBox::Yes){
            modelLose(true,false);
        }
    }
    else{
        msgGameNotOpen();
    }
    
}

void Humanplay::setPauseGame()//设置暂停
{
    if(isPlaying == true){
        modelPause();
    }
    else{
        msgGameNotOpen();
    }
}

void Humanplay::setChangeSide()//设置换边
{
    if(isPlaying == true){
        modelChangeSide();
    }
    else{
        msgGameNotOpen();
    }
}

void Humanplay::setSaveGame()//设置保存
{
    if(isThereChessbook == true){
        if(isPlaying == true){
            msgIsPlaying();
            return;
        }
        modelSave();
    }
    else{
        msgGameNotOpen();
    }
}

void Humanplay::setBackGame()//设置悔棋
{
    if(isPlaying == true){
        modelBack();
    }
    else{
        msgGameNotOpen();
    }
}

void Humanplay::setPlayerTime(int color,int theSecond) //设置对局剩余时间显示
{
    int min = theSecond / 60;
    int sec = theSecond % 60;
    QString time = QString("%1:%2").arg(min,2,10,QLatin1Char('0')).arg(sec,2,10,QLatin1Char('0'));
    if(color == player1.color){
        ui->playerTimer1->display(time);
    }
    else if(color == player2.color){
        ui->playerTimer2->display(time);
    }
}

void Humanplay::setBoardInfo(QString info) //设置盘面提示信息
{
    ui->boardInfoEdit->setText(info);
}

void Humanplay::setChessbookInfo(QString step) //设置棋谱框添加下一步
{
    QListWidgetItem *theItem = new QListWidgetItem;
    theItem->setText(step);
    ui->chessbookEdit->addItem(theItem);
    int count = ui->chessbookEdit->count();
    setChessbookHighLight(count - 1);
}

void Humanplay::removeOneChessbookInfo() //从棋谱框中删除一步
{
    QListWidgetItem *item;
    int count = ui->chessbookEdit->count();
    item = ui->chessbookEdit->takeItem(count - 1);
    delete item;
    setChessbookHighLight(count - 2);
}

void Humanplay::clearChessbook()  //清空棋谱框
{
    QListWidgetItem *item;
    int count = ui->chessbookEdit->count();
    for(int i = count - 1;i >= 0;i--){
        item = ui->chessbookEdit->takeItem(i);
        delete item;
    }
}

void Humanplay::setChessbookHighLight(int index) //设置棋谱选中高亮
{
    if(index >= 0){
        ui->chessbookEdit->setCurrentRow(index);
    }
}

//消息框提示

void Humanplay::msgGameNotOpen()
{
    QMessageBox msg;
    QPixmap pix_img = QPixmap(":/resources/image/iconLogo.jpg");
    pix_img = pix_img.scaled(QSize(100,100),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    msg.setIcon(QMessageBox::NoIcon);
    msg.setIconPixmap(pix_img);
    msg.setWindowTitle(QString("三三棋——对战模式"));
    msg.setText(QString("温馨提示：请先设置棋局开始"));
    msg.setStandardButtons(QMessageBox::Yes);
    msg.setDefaultButton(QMessageBox::Yes);
    msg.setButtonText(QMessageBox::Yes, QString("确 定"));
    msg.exec();
}

void Humanplay::msgIsPlaying()
{
    QMessageBox msg;
    QPixmap pix_img = QPixmap(":/resources/image/iconLogo.jpg");
    pix_img = pix_img.scaled(QSize(100,100),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    msg.setIcon(QMessageBox::NoIcon);
    msg.setIconPixmap(pix_img);
    msg.setWindowTitle(QString("三三棋——对战模式"));
    msg.setText(QString("温馨提示：请先结束棋局"));
    msg.setStandardButtons(QMessageBox::Yes);
    msg.setDefaultButton(QMessageBox::Yes);
    msg.setButtonText(QMessageBox::Yes, QString("确 定"));
    msg.exec();
}


void Humanplay::msgIsPause()
{
    QMessageBox msg;
    QPixmap pix_img = QPixmap(":/resources/image/iconLogo.jpg");
    pix_img = pix_img.scaled(QSize(100,100),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    msg.setIcon(QMessageBox::NoIcon);
    msg.setIconPixmap(pix_img);
    msg.setWindowTitle(QString("三三棋——对战模式"));
    msg.setText(QString("温馨提示：棋局处于暂停中，请先设置棋局继续"));
    msg.setStandardButtons(QMessageBox::Yes);
    msg.setDefaultButton(QMessageBox::Yes);
    msg.setButtonText(QMessageBox::Yes, QString("确 定"));
    msg.exec();
}

int Humanplay::msgSetOver()
{
    QMessageBox msg;
    QPixmap pix_img = QPixmap(":/resources/image/iconLogo.jpg");
    pix_img = pix_img.scaled(QSize(100,100),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    msg.setIcon(QMessageBox::NoIcon);
    msg.setIconPixmap(pix_img);
    msg.setWindowTitle(QString("三三棋——对战模式"));
    msg.setText(QString("确定要结束棋局吗？"));
    msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    msg.setDefaultButton(QMessageBox::Yes);
    msg.setButtonText(QMessageBox::Yes, QString("确 定"));
    msg.setButtonText(QMessageBox::No, QString("取 消"));
    int ret = msg.exec();
    return ret;
}

int Humanplay::msgSetWhiteFlag()
{
    QMessageBox msg;
    QPixmap pix_img = QPixmap(":/resources/image/iconLogo.jpg");
    pix_img = pix_img.scaled(QSize(100,100),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    msg.setIcon(QMessageBox::NoIcon);
    msg.setIconPixmap(pix_img);
    msg.setWindowTitle(QString("三三棋——对战模式"));
    msg.setText(QString("确定要认输吗？"));
    msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    msg.setDefaultButton(QMessageBox::Yes);
    msg.setButtonText(QMessageBox::Yes, QString("确 定"));
    msg.setButtonText(QMessageBox::No, QString("取 消"));
    int ret = msg.exec();
    return ret;
}

