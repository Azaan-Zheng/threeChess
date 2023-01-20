#include "Practice.h"
#include "ui_Practice.h"

Practice::Practice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Practice)
{
    ui->setupUi(this);
    setAppearance();
    setInitialConnect();
    setInitialChessbook();
}

Practice::~Practice()
{
    delete ui;
}

void Practice::paintEvent(QPaintEvent *event) //绘制背景
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/resources/image/background.jpg"),QRect());
}

void Practice::resizeEvent(QResizeEvent *event) //设置控件大小随窗口大小变化
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
    hControlWidget = (int)(0.25 * lBoard);
    ui->controlView->setGeometry(QRect(xControl,yControl,wControl,hControl));

    //控制按钮和控件
    ui->controlWidget->setGeometry(QRect(0,hControl - hControlWidget,wControl,hControlWidget));
    hControlBtn = (int)(hControlWidget / 5.0);
    int yBlock = (int)(hControlWidget / 5.0);
    int xBlock = (int)((wControl - 6 * hControlBtn) / 4.0);
    ui->btnLast->setGeometry(QRect(xBlock,yBlock,hControlBtn * 3,hControlBtn));
    ui->btnNext->setGeometry(QRect(3 * xBlock + 3 * hControlBtn,yBlock,hControlBtn * 3,hControlBtn));
    ui->btnExchange->setGeometry(QRect(xBlock,2 * yBlock + hControlBtn,hControlBtn * 3,hControlBtn));
    ui->btnSave->setGeometry(QRect(3 * xBlock + 3 * hControlBtn,2 * yBlock + hControlBtn,hControlBtn * 3,hControlBtn));

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

    int btnWidth2 = (int)(wInfo / 6);
    int btnHeight2 = (int)(btnWidth2 / 2.5);
    int historyHeight = hInfo - hInfoWidget - 4 * btnHeight2 - yBlock;
    ui->historyWidget->setGeometry(QRect(0,0,wInfo,historyHeight));
    ui->historyLabel->setGeometry(QRect(4,4,wInfo - 8,yBar));
    ui->historyEdit->setGeometry(QRect(4,4 + yBar,wInfo - 8,historyHeight - yBar - 8));

    ui->btnOpen->setGeometry(QRect(10,historyHeight + btnHeight2,2 * btnWidth2,2 * btnHeight2));
    ui->btnDelete->setGeometry(QRect(wInfo - 2 * btnWidth2 - 10, historyHeight + btnHeight2,2 * btnWidth2,2 * btnHeight2));
}

void Practice::setAppearance() //设置初始化外观
{
    this->setMinimumWidth(1000);
    this->setMinimumHeight(600);
    ui->boardInfoEdit->setFontWeight(QFont::Bold);
    ui->boardInfoEdit->setFontFamily("楷体");
    ui->boardInfoEdit->setAlignment(Qt::AlignHCenter);
}

void Practice::setInitialConnect() //设置初始化连接
{
    board = ui->boardView;//便于连接棋盘
    connect(ui->btnReturn,&QToolButton::clicked,this,&Practice::setNormalClose);
    connect(ui->btnExchange,&QToolButton::clicked,this,&Practice::setModelChangeSide);
    connect(ui->btnLast,&QToolButton::clicked,this,&Practice::setModelLastStep);
    connect(ui->btnNext,&QToolButton::clicked,this,&Practice::setModelNextStep);
    connect(ui->btnSave,&QToolButton::clicked,this,&Practice::setModelSaveChessbook);
    connect(ui->btnDelete,&QToolButton::clicked,this,&Practice::setModelDeleteChessbook);
    connect(ui->btnOpen,&QToolButton::clicked,this,&Practice::setModelOpenChessbook);

}


void Practice::setInitialChessbook() //设置初始化棋谱框
{
    ui->chessbookEdit->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->chessbookEdit->setSelectionMode (QAbstractItemView::SingleSelection);
    ui->historyEdit->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->historyEdit->setSelectionMode (QAbstractItemView::SingleSelection);
}

//信号控制

void Practice::setModelChangeSide() //设置换边信号
{
    if(isThereChessbook == true){
        modelChangeSide();
    }
}

void Practice::setModelLastStep() //设置上一步信号
{
    if(isThereChessbook == true){
        modelLastStep();
        isStatic = true;
    }
}

void Practice::setModelNextStep()//设置下一步信号
{
    if(isThereChessbook == true){
        modelNextStep();
    }
}

void Practice::setModelSaveChessbook()//设置保存信号
{
    if(isThereChessbook == true){
        modelSaveChessbook();
    }
}

void Practice::setModelOpenChessbook() //设置打开棋谱信号
{

    QItemSelectionModel *select = ui->historyEdit->selectionModel();
    if(select->hasSelection()){
        QModelIndex index = ui->historyEdit->selectionModel()->selectedIndexes().at(0);
        modelOpenChessbook(index);
    }
}

void Practice::setModelDeleteChessbook() //设置删除棋谱信号
{
    QItemSelectionModel *select = ui->historyEdit->selectionModel();
    if(select->hasSelection()){
        QModelIndex index = ui->historyEdit->selectionModel()->selectedIndexes().at(0);
        modelDeleteChessbook(index);
    }
}

//综合控制

void Practice::setNormalClose()
{
    modelReturn();
    this->board->cleanBoard();
    clearChessbook();
    this->ui->boardInfoEdit->setText(QString(""));
    this->hide();
}

void Practice::setStaticClose(int index)
{
    isStatic = false;
    QListWidgetItem *item;
    int count = ui->chessbookEdit->count();
    for(int i = count - 1;i > index;i--){
        item = ui->chessbookEdit->takeItem(i);
        delete item;
    }
}


//信息传输

void Practice::setHistoryModel(QStandardItemModel *model) //导入历史棋谱信息
{
    ui->historyEdit->setModel(model);
}


void Practice::setBoardInfo(QString info) //设置盘面提示信息
{
    ui->boardInfoEdit->setText(info);
}


void Practice::setChessbookInfo(QString step) //设置棋谱增加下一步
{   
    QListWidgetItem *theItem = new QListWidgetItem(ui->chessbookEdit);
    theItem->setText(step);
    ui->chessbookEdit->addItem(theItem);
    int count = ui->chessbookEdit->count();
    setChessbookHighLight(count - 1);
}

void Practice::setChessbookHighLight(int index) //设置棋谱高亮
{
    if(index >= 0){
        ui->chessbookEdit->setCurrentRow(index);
    }
}

void Practice::clearChessbook() //设置清空棋谱
{
    QListWidgetItem *item;
    int count = ui->chessbookEdit->count();
    for(int i = count - 1;i >= 0;i--){
        item = ui->chessbookEdit->takeItem(i);
        delete item;
    }
}


