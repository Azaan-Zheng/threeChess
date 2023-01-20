#include "BoardView.h"

BoardView::BoardView(QWidget *parent) :
    QWidget(parent)
{
    Q_UNUSED(parent)
    setBoardViewInitial();
    updateBoardSize();


}

BoardView::~BoardView()
{

}

void BoardView::setOpenWork() //设置棋盘开始接受落点信息
{
    this->isWorking = true;
}

void BoardView::setStopWork() //设置棋盘不接受落点
{
    this->isWorking = false;
}

void BoardView::setBoardViewInitial() //初始化棋盘界面和棋子对象
{
    //创建所有的棋子对象
    int i,j,k;
    for(i = 0;i < CIRCLE;i++){
        for(j = 0;j < SEAT;j++){
            for(k = 0;k < 7;k++){
                pieces[i][j][k] = new Piece(k,i,j);
                pieces[i][j][k]->mLabel = new QLabel(this);
                pieces[i][j][k]->mLabel->setVisible(false);

                if(k > 0){
                    if(k == BLACK)
                        pieces[i][j][k]->mLabel->setStyleSheet("image:url(:/resources/image/black.png)");
                    else if(k == WHITE)
                        pieces[i][j][k]->mLabel->setStyleSheet("image:url(:/resources/image/white.png)");
                    else if(k == DEAD)
                        pieces[i][j][k]->mLabel->setStyleSheet("image:url(:/resources/image/remove.png)");
                    else if(k == BLACK_CHOSEN)
                        pieces[i][j][k]->mLabel->setStyleSheet("image:url(:/resources/image/blackChosen.png)");
                    else if(k == WHITE_CHOSEN)
                        pieces[i][j][k]->mLabel->setStyleSheet("image:url(:/resources/image/whiteChosen.png)");
                    else if(k == CHOSEN)
                        pieces[i][j][k]->mLabel->setStyleSheet("image:url(:/resources/image/current.png)");
                }

            }
        }
    }
    //创建动画标签对象
    labels[LABEL_BEGIN] = new QLabel(this);
    labels[LABEL_BEGIN]->setStyleSheet("image:url(:/resources/image/gameBegin.png)");
    labels[LABEL_BLACK] = new QLabel(this);
    labels[LABEL_BLACK]->setStyleSheet("image:url(:/resources/image/blackWin.png)");
    labels[LABEL_WHITE] = new QLabel(this);
    labels[LABEL_WHITE]->setStyleSheet("image:url(:/resources/image/whiteWin.png)");

    //给动画标签对象加上动画
    for(int i = 0;i < 3;i++){
        opacities[i] = new QGraphicsOpacityEffect(this);
        opacities[i]->setOpacity(0);
        labels[i]->setGraphicsEffect(opacities[i]);
        animations[i] = new QPropertyAnimation(opacities[i],"opacity");
        animations[i]->setDuration(1500);
        animations[i]->setStartValue(1);
        animations[i]->setEndValue(0);
    }


}

//绘制控制

void BoardView::updateBoardSize() //更新棋盘尺寸 棋子位置
{
    radius = (int)(this->width() / 24);
    length = radius * 18;
    edge = radius * 3;
    int i,j,k;
    for(i = 0;i < CIRCLE;i++){
        for(j = 0;j < SEAT;j++){
            for(k = 0;k < 7;k++){
                QPoint pCenter = getCenter(i,j);
                pieces[i][j][k]->mLabel->setGeometry(QRect(pCenter.rx() - radius,pCenter.ry() - radius,2 * radius,2 * radius));
            }
        }
    }
    for(int i = 0;i < 3;i++){
        labels[i]->setGeometry(QRect(4*edge - 6*radius ,4*edge - 2*radius, 12*radius, 4*radius));
    }
}


void BoardView::paintEvent(QPaintEvent *event) //绘制棋盘
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(QPen(Qt::black,radius / 8 + 2));
    //三圈正方形
    for(int i = 0;i < CIRCLE;i++)
    {
        painter.drawLine(QPoint((i + 1) * edge, (i + 1) * edge),QPoint((i + 1) * edge, (7 - i) * edge));
        painter.drawLine(QPoint((i + 1) * edge, (7 - i) * edge),QPoint((7 - i) * edge, (7 - i) * edge));
        painter.drawLine(QPoint((7 - i) * edge, (7 - i) * edge),QPoint((7 - i) * edge, (i + 1) * edge));
        painter.drawLine(QPoint((7 - i) * edge, (i + 1) * edge),QPoint((i + 1) * edge, (i + 1) * edge));
    }
    //八条直线
    painter.drawLine(QPoint(edge,edge),QPoint(3 * edge ,3 * edge));
    painter.drawLine(QPoint(7 * edge,edge),QPoint(5 * edge ,3 * edge));
    painter.drawLine(QPoint(3 * edge,5 * edge),QPoint(edge ,7 * edge));
    painter.drawLine(QPoint(5 * edge,5 * edge),QPoint(7 * edge ,7 * edge));
    painter.drawLine(QPoint(edge,4 * edge),QPoint(3 * edge ,4 * edge));
    painter.drawLine(QPoint(5 * edge,4 * edge),QPoint(7 * edge ,4 * edge));
    painter.drawLine(QPoint(4 * edge,edge),QPoint(4 * edge ,3 * edge));
    painter.drawLine(QPoint(4 * edge,5 * edge),QPoint(4 * edge ,7 * edge));
}

void BoardView::showLabels(int label){ //控制动画打开
    animations[label]->start();
}

void BoardView::mousePressEvent(QMouseEvent *event) //获取棋盘上点击的落点
{
    if(isWorking == false)
        return;
    QPoint pt = event->pos();
    pBoardPoint = getPoint(pt);
    //如果落点的位置不能够确认为合法落点，则不会发送信号
    if(pBoardPoint.circle == -1 || pBoardPoint.seat == -1)
        return;
    //发送棋盘落子点信号
    sendPiece();
}

void BoardView::drawPiece(int circle,int seat,int color){//更新一个落点的棋子
    //排除非法落点
    if(!(circle <= 2 && circle >= 0 && seat <= 7 && seat >= 0 && color <= 6 && color >= 0))
        return;
    //先将所有落点变为不可见
    for(int k = 0;k < 7;k++)
        pieces[circle][seat][k]->mLabel->setVisible(false);
    //选择选中的落点将其变为可见
    pieces[circle][seat][color]->mLabel->setVisible(true);
}

void BoardView::freshPiece(int position[CIRCLE][SEAT],int rx,int ry,int color){//更新所有落点的棋子
    int i,j;
    for(i = 0;i < CIRCLE;i++)
        for(j = 0;j < SEAT;j++)
            drawPiece(i,j,position[i][j]);
    //更新特殊点
    if(rx >= 0 && ry >= 0 && color >= 0)
        drawPiece(rx,ry,color);
}

void BoardView::cleanBoard() //将盘面清空
{
    int i,j;
    for(i = 0;i < CIRCLE;i++){
        for(j = 0;j < SEAT;j++){
            drawPiece(i,j,EMPTY);
        }
    }
}

//绘制计算

QPoint BoardView::getCenter(int circle,int seat)//返回棋盘行列交点对应的像素坐标
{
    int length = (circle + 1) * edge;
    if(seat <= 4){
        if(seat > 2)
            return QPoint((3 - circle) * edge + 2 * length, (3 - circle) * edge + (seat - 2) * length);
        else
            return QPoint((3 - circle) * edge + seat * length, (3 - circle) * edge);
    }
    else{
        if(seat > 6)
            return QPoint((3 - circle) * edge, (3 - circle) * edge + (8 - seat) * length);
        else
            return QPoint((3 - circle) * edge + (6 - seat) * length, (3 - circle) * edge + 2 * length);
    }
}

PPoint BoardView::getPoint(int circle,int seat)//返回棋盘行列交点对应的PPoint坐标
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

QPoint BoardView::getCenter(PPoint pPoint)//返回棋盘行列交点对应的像素坐标
{
    int x = (pPoint.rx + 1) * edge;
    int y = (pPoint.ry + 1) * edge;
    return QPoint(x,y);
}

PPoint BoardView::getPoint(QPoint pRelate)//返回相对坐标对应的行列PPoint坐标
{
    int px = pRelate.rx();
    int py = pRelate.ry();
    int x = (int)(px / edge);
    int y = (int)(py / edge);
    PPoint pPoint;
    pPoint.circle = -1;
    pPoint.seat = -1;
    pPoint.rx = -1;
    pPoint.ry = -1;
    if(px - edge * x < radius)
        x--;
    else if(edge * (x + 1) - px > radius)
        return pPoint;

    if(py - edge * y < radius)
        y--;
    else if(edge * (y + 1) - py > radius)
        return pPoint;

    if(x == y || x + y == 6 || x == 3 || y == 3){
        if(x == 3 && y == 3)
            return pPoint;
        else{
            int rx = x - 3,ry = y - 3;
            pPoint.rx = x;
            pPoint.ry = y;
            if(rx * rx + ry * ry < 3)
                pPoint.circle = 0;
            else if(rx * rx + ry * ry < 9)
                pPoint.circle = 1;
            else
                pPoint.circle = 2;

            if(rx == 0)
                if(ry > 0)
                    pPoint.seat = 5;
                else
                    pPoint.seat = 1;
            else if(ry == 0)
                if(rx > 0)
                    pPoint.seat = 3;
                else
                    pPoint.seat = 7;
            else if(rx == ry)
                if(rx < 0)
                    pPoint.seat = 0;
                else
                    pPoint.seat = 4;
            else
                if(rx > 0)
                    pPoint.seat = 2;
                else
                    pPoint.seat = 6;
        }
    }
    return pPoint;
}
