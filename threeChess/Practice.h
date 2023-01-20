#ifndef PRACTICE_H
#define PRACTICE_H

/*这是练习模式窗口类*/

#include "define.h"
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QStandardItemModel>
#include <QListWidget>
#include "Login.h"
#include "BoardView.h"

namespace Ui {
class Practice;
}

class Practice : public QMainWindow
{
    Q_OBJECT

public:
    explicit Practice(QWidget *parent = 0);
    ~Practice();

    //外观控制
    void paintEvent(QPaintEvent *event); //绘制背景设置
    void setAppearance();//外观设置

    //信息控制
    void setInitialConnect();   //初始化连接
    void setInitialChessbook(); //初始化棋谱框
    void setHistoryModel(QStandardItemModel *model);  //导入历史棋谱信息
    void setBoardInfo(QString info);   //设置盘面提示信息
    void setChessbookInfo(QString step);  //设置棋谱框增加一步棋
    void setChessbookHighLight(int index);  //设置棋谱框高亮
    void clearChessbook();   //清空棋谱框

           //由于按钮按下后需要做出判断再选择发送信号，因此每个信号有对应的设置函数，设置函数判断成功再发送
    void setModelChangeSide();  //设置换边信号
    void setModelLastStep();    //设置上一步信号
    void setModelNextStep();    //设置下一步信号
    void setModelSaveChessbook();   //设置保存信号
    void setModelOpenChessbook();   //设置打开棋谱信号
    void setModelDeleteChessbook(); //设置删除棋谱信号

    //综合控制
    void setNormalClose();  //模式关闭
    void setStaticClose(int index); //关闭静态——即可以在棋谱基础上试下


signals:
    void modelReturn();//返回关闭窗口信号
    void modelChangeSide();//返回换边信号
    void modelLastStep();//返回上一步信号
    void modelNextStep();//返回下一步信号
    void modelSaveChessbook();//返回保存棋谱信号
    void modelOpenChessbook(QModelIndex index);//返回打开棋谱信号
    void modelDeleteChessbook(QModelIndex index);//返回删除棋谱信号

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

public:


    //boardView各项数据
    BoardView *board = nullptr;
        //外观
    int xBoard = 100;
    int yBoard = 100;
    int lBoard = 480;

    //controlView各项数据
    int xControl = 580;
    int yControl = 100;
    int wControl = 400;
    int hControl = 500;
    int hControlWidget = 200;
    int hControlBtn = 30;

    //infoView各项数据
    int xInfo = 20;
    int yInfo = 50;
    int wInfo = 80;
    int hInfo = 500;
    int hInfoWidget = 100;


    //练习模式控制
    bool isStatic = false;   //是否静态，如果是静态则可以查看棋谱，但不能下棋
    bool isThereChessbook = false;  //是否有棋谱

private:
    Ui::Practice *ui;
};

#endif // PRACTICE_H
