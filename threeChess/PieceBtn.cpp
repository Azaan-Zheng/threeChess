#include "PieceBtn.h"

PieceBtn::PieceBtn(QObject *parent) : QObject(parent)
{

}

PieceBtn::~PieceBtn()
{

}


void PieceBtn::getConnection()
{
    connect(this->mPiece,&QToolButton::clicked,this,&PieceBtn::getClicked);
}

void PieceBtn::getClicked()
{
    this->sendPieceInfo(this->circle,this->seat);
}

