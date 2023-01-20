#include "Introduction.h"
#include "ui_Introduction.h"

Introduction::Introduction(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Introduction)
{
    ui->setupUi(this);
    setAppearance();
    setInitialConnect();
    setStageFunc(introStage);
}

Introduction::~Introduction()
{
    delete ui;
}

void Introduction::paintEvent(QPaintEvent *event) //设置背景
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/resources/image/background.jpg"),QRect());
}

void Introduction::resizeEvent(QResizeEvent *event) //设置控件大小随窗口大小变化
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
    hControlWidget = (int)(0.15 * lBoard);
    ui->controlView->setGeometry(QRect(xControl,yControl,wControl,hControl));

    //控制按钮和控件
    ui->controlWidget->setGeometry(QRect(0,hControl - hControlWidget,wControl,hControlWidget));
    hControlBtn = (int)(hControlWidget / 3.0);
    int yBlock = (int)(hControlWidget / 3.0);
    int xBlock = (int)((wControl - 6 * hControlBtn) / 4.0);
    ui->btnLast->setGeometry(QRect(xBlock,yBlock,hControlBtn * 3,hControlBtn));
    ui->btnNext->setGeometry(QRect(3 * xBlock + 3 * hControlBtn,yBlock,hControlBtn * 3,hControlBtn));

    //控制棋谱
    int yBar = (int)((wControl - 2 * xBlock) / 6.0);
    ui->chessbookWidget->setGeometry(QRect(xBlock,0,wControl - 2 * xBlock,hControl - hControlWidget));
    ui->chessbookLabel->setGeometry(QRect(4,4,wControl - 2 * xBlock - 8,yBar));
    ui->chessbookEdit->setGeometry(QRect(4,4 + yBar,wControl - 2 * xBlock - 8,hControl - hControlWidget - yBar - 8));

    //设置左部大小
    wInfo = (int)((xBoard + 0.1 * lBoard) * 0.7);
    xInfo = (int)((xBoard + 0.1 * lBoard) * 0.15);
    yInfo = yBoard + (int)(lBoard * 0.12);
    hInfo = (int)(lBoard * 0.88) - yBlock;
    yBar = (int)(wInfo / 6.0);
    ui->boardInfoWidget->setGeometry(QRect(xInfo,yInfo,wInfo,hInfo));
    ui->boardInfoLabel->setGeometry(QRect(4,4,wInfo - 8,yBar));
    ui->boardInfoEdit->setGeometry(QRect(4,4 + yBar,wInfo - 8,hInfo - yBar - 8));
}

void Introduction::setAppearance() //设置外观
{
    this->setMinimumWidth(1000);
    this->setMinimumHeight(600);
    ui->boardInfoEdit->setFontWeight(QFont::Bold);
    ui->boardInfoEdit->setFontFamily("楷体");
    ui->boardInfoEdit->setFontPointSize(14);
}

void Introduction::setInitialConnect() //设置初始化连接
{
    board = ui->boardView;//便于连接棋盘
    connect(ui->btnReturn,&QToolButton::clicked,this,&Introduction::setNormalClose);
    connect(ui->btnLast,&QToolButton::clicked,this,&Introduction::setBtnLast);
    connect(ui->btnNext,&QToolButton::clicked,this,&Introduction::setBtnNext);
}

void Introduction::setNormalClose() //模式退出
{
    modelReturn();
    this->hide();
}

void Introduction::setBtnNext() //下一步
{
    if(introStage < INTRO_LOSE){
        introStage++;
        setStageFunc(introStage);
    }
}


void Introduction::setBtnLast() //上一步
{
    if(introStage > INTRO_BOARD){
        introStage--;
        setStageFunc(introStage);
    }
}



void Introduction::setStageFunc(int stage)//设置阶段对应的函数
{
    if(stage == INTRO_BOARD){
        setIntroBoard();
    }
    else if(stage == INTRO_POSE){
        setIntroPose();
        modelIntroPose();
    }
    else if(stage == INTRO_FILL){
        setIntroFill();
    }
    else if(stage == INTRO_MOVE){
        setIntroMove();
        modelIntroMove();
    }
    else if(stage == INTRO_LOSE){
        setIntroLose();
    }
}

void Introduction::setIntroBoard()//介绍棋盘
{
    int position[CIRCLE][SEAT];
    for(int j = 0;j < SEAT;j++){
        for(int i = 0;i < CIRCLE;i++){
            if(j == 3 || j == 4 || j == 5){
                position[i][j] = WHITE;
            }
            else if(j == 0){
                position[i][j] = BLACK;
            }
            else{
                position[i][j] = EMPTY;
            }
        }
    }
    position[2][1] = position[2][2] = position[2][6] = position[2][7] = BLACK;
    board->freshPiece(position,-1,-1,-1);
    board->setStopWork();
    clearChessbook();
    QString intro = QString("一、棋盘介绍");
    intro.append(QString("\n"));
    intro.append(QString("    三三棋的棋盘由内、中、外三层中心重合的正方形套在一起，东、西、南、北、东北、东南、西北、西南八方各有一条直线将三层连接起来。"
                         "棋盘上形成24个格点，即落子点。如一方落子以后，盘面一直线上三点均被该方占领，则称这步棋构成了一个“三”。如右图所示，横、竖、斜方向均可视为成“三”。"));
    intro.append(QString("\n"));
    intro.append(QString("    下棋时，一般先手执黑，后手执白，交替行棋。行棋分落子阶段和运子阶段。请点击下一步继续了解。"));
    ui->boardInfoEdit->setText(intro);

}

void Introduction::setIntroPose()//介绍落子
{
    board->cleanBoard();
    board->setOpenWork();
    clearChessbook();
    QString intro = QString("二、落子阶段");
    intro.append(QString("\n"));
    intro.append(QString("    黑白双方交替在空位落子，如一步棋构成了一个“三”，这时该方可选择对方任一棋子扣住，被扣棋子后续不参与成“三”，且在落子阶段结束后将被从盘面移除。"));
    intro.append(QString("\n"));
    intro.append(QString("    若一步棋可以形成多个“三”，则可以扣住对方对应数量的子。如右图，请落在 外西北，可扣住白方两子。点击下一步继续了解。"));
    ui->boardInfoEdit->setText(intro);
}

void Introduction::setIntroFill()//介绍中盘
{
    int position[CIRCLE][SEAT];
    for(int i = 0;i < CIRCLE;i++){
        for(int j = 0;j < SEAT;j++){
            if((i + j) % 2 == 1){
                position[i][j] = WHITE;
            }
            else{
                position[i][j] = BLACK;
            }
        }
    }
    board->freshPiece(position,-1,-1,-1);
    board->setStopWork();
    clearChessbook();
    QString intro = QString("三、落子结束");
    intro.append(QString("\n"));
    intro.append(QString("    当盘面被填满时（含被扣子），落子阶段结束。这时把双方被扣的子从棋盘中移除留出空位，棋局进入运子阶段。"));
    intro.append(QString("\n"));
    intro.append(QString("    若落子阶段双方均无被扣子，则棋局结束，判落子阶段后手方（即此时的白方）获胜。如右图，为一种示例。请点击下一步继续了解。"));
    ui->boardInfoEdit->setText(intro);
}

void Introduction::setIntroMove()//介绍走子
{
    board->cleanBoard();
    board->setOpenWork();
    clearChessbook();
    QString intro = QString("四、运子阶段");
    intro.append(QString("\n"));
    intro.append(QString("    由落子阶段的后手方（即此时的白方）先运子，每次只能运一个子到相邻的空位，双方交替运子。"));
    intro.append(QString("\n"));
    intro.append(QString("    若运子成“三”，可以直接移除对方任意一个子，若形成多个“三”，则可以移除对方对应数量的子。如右图，请将黑 内正北 移到 内西北，可移除白方两子。请点击下一步继续了解。"));
    ui->boardInfoEdit->setText(intro);

}

void Introduction::setIntroLose()//介绍输赢
{
    int pos[CIRCLE][SEAT];
    for(int i = 0;i < CIRCLE;i++){
        for(int j = 0;j < SEAT;j++){
            pos[i][j] = BLACK;
        }
    }
    pos[0][3] = pos[0][4] = pos[0][5] = pos[0][7] = pos[1][3] = pos[1][4] = pos[1][6] = pos[2][7] = WHITE;
    pos[1][0] = pos[1][1] = pos[2][1] = pos[2][2] = EMPTY;
    board->freshPiece(pos,-1,-1,-1);
    board->setStopWork();
    clearChessbook();
    QString intro = QString("五、棋局结束");
    intro.append(QString("\n"));
    intro.append(QString("    当盘面任意一方剩余子数少于三个，则该方告负，棋局结束。"));
    intro.append(QString("\n"));
    intro.append(QString("    若盘面一方被另一方堵住所有相邻位置，不能运子，如右图的白方，则仍判作该方告负，棋局结束。规则介绍完毕，进入其他模式开始游戏吧！"));
    ui->boardInfoEdit->setText(intro);
}


void Introduction::clearChessbook() //清空棋谱框
{
    QListWidgetItem *item;
    int count = ui->chessbookEdit->count();
    for(int i = count - 1;i >= 0;i--){
        item = ui->chessbookEdit->takeItem(i);
        delete item;
    }
}

void Introduction::takeInChessbook(ChessBook *chessbook) //导入棋谱
{
    clearChessbook();
    int count = chessbook->stepNum;
    QListWidgetItem *item;
    QString str;
    for(int i = 0;i < count;i++){
        item = new QListWidgetItem(ui->chessbookEdit);
        str = chessbook->printOneStep(chessbook->steps.at(i));
        item->setText(str);
    }
    ui->chessbookEdit->setCurrentRow(count - 1);
}


