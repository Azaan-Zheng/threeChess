#ifndef PIECEBTN_H
#define PIECEBTN_H

#include <QObject>
#include <QToolButton>
#include "define.h"

class PieceBtn : public QObject
{
    Q_OBJECT
public:
    explicit PieceBtn(QObject *parent = nullptr);
    ~PieceBtn();

signals:
    void sendPieceInfo(int i,int j);

public:
    //棋子本身信息 空为默认状态
    int color = EMPTY;
    //棋子坐标
    int circle = -1;
    int seat = -1;
    QToolButton *mPiece;

public:
    void getConnection();
    void getClicked();

public slots:
};

#endif // PIECEBTN_H
