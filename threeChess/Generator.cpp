#include "Generator.h"

Generator::Generator()
{

}

Generator::~Generator()
{

}


bool Generator::isValidPoint(Board *pBoard,int theCircle,int theSeat) //判断当前盘面下 落点是否合法
{
    if(pBoard->currentStage == POSE){
        if(pBoard->isKilling){
            return isValidKill(pBoard,theCircle,theSeat);
        }
        else{
            if(pBoard->position[theCircle][theSeat] == EMPTY)
                return true;
        }
    }
    else if(pBoard->currentStage == MOVE){
        if(pBoard->isMoving){
            if(pBoard->position[theCircle][theSeat] == EMPTY){
                int rx = theCircle - pBoard->pChosen.circle;
                int ry = theSeat - pBoard->pChosen.seat;
                if(rx == 0 && ry * ry == 49){
                    return true;
                }
                else if(rx * rx + ry * ry == 1){
                    return true;
                }
            }
        }
        else if(pBoard->isKilling){
            return isValidKill(pBoard,theCircle,theSeat);
        }
        else{
            return isValidChose(pBoard,theCircle,theSeat);
        }
    }
    return false;
}


bool Generator::isValidKill(Board *pBoard,int theCircle,int theSeat) //判断 提子/扣子 是否合法
{
    if(pBoard->isKilling){
        if(CHANGE_COLOR(pBoard->currentColor) == pBoard->position[theCircle][theSeat])
            return true;
    }
    return false;
}


bool Generator::isValidPose(Board *pBoard,int theCircle,int theSeat) //判断 摆棋 是否合法
{
    if(pBoard->currentStage == POSE){
        if(pBoard->position[theCircle][theSeat] == EMPTY)
            return true;
    }
    return false;
}


bool Generator::isValidChose(Board *pBoard,int theCircle,int theSeat) //判断选子是否合法
{
    if(pBoard->currentStage == MOVE){
        if(pBoard->isKilling == 0 && pBoard->isMoving == 0){
            if(pBoard->currentColor == pBoard->position[theCircle][theSeat]){
                int left = (theSeat + SEAT - 1) % SEAT;
                int right = (theSeat + SEAT + 1) % SEAT;
                int cir = theCircle;
                if(cir == 0){
                    if(pBoard->position[cir][left] == EMPTY
                            || pBoard->position[cir][right] == EMPTY
                            || pBoard->position[cir + 1][theSeat] == EMPTY){
                        return true;
                    }
                }
                else if(cir == 1){
                    if(pBoard->position[cir][left] == EMPTY
                            || pBoard->position[cir][right] == EMPTY
                            || pBoard->position[cir + 1][theSeat] == EMPTY
                            || pBoard->position[cir - 1][theSeat] == EMPTY){
                        return true;
                    }
                }
                else if(cir == 2){
                    if(pBoard->position[cir][left] == EMPTY
                            || pBoard->position[cir][right] == EMPTY
                            || pBoard->position[cir - 1][theSeat] == EMPTY){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Generator::isValidChose(Board *pBoard,int theCircle,int theSeat,int theColor) //判断选子是否合法 不使用棋盘内颜色
{
    if(pBoard->currentStage == MOVE){
        if(theColor == pBoard->position[theCircle][theSeat]){
            int left = (theSeat + SEAT - 1) % SEAT;
            int right = (theSeat + SEAT + 1) % SEAT;
            int cir = theCircle;
            if(cir == 0){
                if(pBoard->position[cir][left] == EMPTY
                        || pBoard->position[cir][right] == EMPTY
                        || pBoard->position[cir + 1][theSeat] == EMPTY){
                    return true;
                }
            }
            else if(cir == 1){
                if(pBoard->position[cir][left] == EMPTY
                        || pBoard->position[cir][right] == EMPTY
                        || pBoard->position[cir + 1][theSeat] == EMPTY
                        || pBoard->position[cir - 1][theSeat] == EMPTY){
                    return true;
                }
            }
            else if(cir == 2){
                if(pBoard->position[cir][left] == EMPTY
                        || pBoard->position[cir][right] == EMPTY
                        || pBoard->position[cir - 1][theSeat] == EMPTY){
                    return true;
                }
            }
        }
    }
    return false;
}


bool Generator::isValidMove(Board *pBoard,Move theMove) //判断当前盘面下 走棋 是否合法
{
    if(pBoard->currentStage == MOVE){
        if(pBoard->position[theMove.circleBefore][theMove.seatBefore] == pBoard->currentColor
                && pBoard->position[theMove.circleAfter][theMove.seatAfter] == EMPTY){
            int rx = theMove.circleBefore - theMove.circleAfter;
            int ry = theMove.seatBefore - theMove.seatAfter;
            if(rx == 0 && ry * ry == 49){
                return true;
            }
            else if(rx * rx + ry * ry == 1){
                return true;
            }
        }
    }
    return false;
}

bool Generator::isValidMove(Board *pBoard,Step theStep) //判断当前盘面下 走棋 是否合法
{
    if(pBoard->currentStage == MOVE){
        if(pBoard->position[theStep.circleBefore][theStep.seatBefore] == pBoard->currentColor
                && pBoard->position[theStep.circleAfter][theStep.seatAfter] == EMPTY){
            int rx = theStep.circleBefore - theStep.circleAfter;
            int ry = theStep.seatBefore - theStep.seatAfter;
            if(rx == 0 && ry * ry == 49){
                return true;
            }
            else if(rx * rx + ry * ry == 1){
                return true;
            }
        }
    }
    return false;
}



bool Generator::isUnableMove(Board *pBoard,int color) //判断是否被堵死
{
    int circle,seat;
    for(circle = 0;circle < CIRCLE;circle++){
        for(seat = 0;seat < SEAT;seat++){
            if(pBoard->position[circle][seat] == color){
                if(isValidChose(pBoard,circle,seat,color)){
                    return false;
                }
            }
        }
    }
    return true;
}


int Generator::isGetThree(Board *pBoard,int theCircle,int theSeat) //判断是否成“三”
{
    int count = 0;
    int theUp = (theCircle + CIRCLE + 1) % CIRCLE;
    int theDown = (theCircle + CIRCLE - 1) % CIRCLE;
    if(pBoard->position[theUp][theSeat] == pBoard->currentColor && pBoard->position[theDown][theSeat] == pBoard->currentColor){
        count++;
    }
    int theLeft = (theSeat + SEAT - 1) % SEAT;
    int theLeft1 = (theSeat + SEAT - 2) % SEAT;
    int theRight = (theSeat + SEAT + 1) % SEAT;
    int theRight1 = (theSeat + SEAT + 2) % SEAT;
    if(theSeat % 2 == 1){
        if(pBoard->position[theCircle][theLeft] == pBoard->currentColor && pBoard->position[theCircle][theRight] == pBoard->currentColor){
            count++;
        }
    }
    else{
        if(pBoard->position[theCircle][theLeft] == pBoard->currentColor && pBoard->position[theCircle][theLeft1] == pBoard->currentColor){
            count++;
        }
        if(pBoard->position[theCircle][theRight] == pBoard->currentColor && pBoard->position[theCircle][theRight1] == pBoard->currentColor){
            count++;
        }
    }
    return count;
}



int Generator::setAfterPose(Board *theBoard) //棋盘数据 摆棋之后
{
    if(theBoard->isKilling == 0){
        if(theBoard->pieceNum[EMPTY] + theBoard->pieceNum[BLACK] + theBoard->pieceNum[WHITE] == POINT){
            if(theBoard->pieceNum[EMPTY] == 0){
                theBoard->currentStage = OVER;
                theBoard->currentColor = theBoard->player1.color;
                return GAME_OVER;
            }
            else{
                theBoard->currentStage = MOVE;
                theBoard->cleanDead();
                theBoard->isMoving = false;
                theBoard->currentColor = theBoard->player2.color;
                if(isUnableMove(theBoard,theBoard->player2.color)){
                    theBoard->currentStage = OVER;
                    return GAME_OVER;
                }
                else{
                    return GAME_MOVE;
                }
            }
        }
        else{
            theBoard->currentColor = CHANGE_COLOR(theBoard->currentColor);
            return GAME_EXCH;
        }
    }
    else{
        return GAME_CON;
    }
}

int Generator::setAfterMove(Board *theBoard) //棋盘数据 走棋之后
{
    if(theBoard->pieceNum[CHANGE_COLOR(theBoard->currentColor)] < 3){
        theBoard->currentStage = OVER;
        theBoard->currentColor = CHANGE_COLOR(theBoard->currentColor);
        return GAME_OVER;
    }

    if(theBoard->isKilling == 0){
        if(isUnableMove(theBoard,CHANGE_COLOR(theBoard->currentColor))){
            theBoard->currentStage = OVER;
            theBoard->currentColor = CHANGE_COLOR(theBoard->currentColor);
            return GAME_OVER;
        }
        theBoard->currentColor = CHANGE_COLOR(theBoard->currentColor);
        return GAME_EXCH;
    }
    else{
        return GAME_CON;
    }
}

int Generator::setStepNext(Step s,Board *theBoard) //棋盘数据 下一步
{
    if(s.action == ACT_CHANGE){
        theBoard->changeSide();
    }
    else if(s.action == ACT_POSE){
        if(isValidPose(theBoard,s.circleBefore,s.seatBefore)){
            theBoard->pChosen.circle = s.circleBefore;
            theBoard->pChosen.seat = s.seatBefore;
            theBoard->pChosenBefore.rx = -1;
            theBoard->pieceNum[s.subject]++;
            theBoard->position[s.circleBefore][s.seatBefore] = theBoard->currentColor;
            theBoard->isKilling = isGetThree(theBoard,s.circleBefore,s.seatBefore);
            return setAfterPose(theBoard);
        }
        else{
            return 0;
        }
    }
    else if(s.action == ACT_POSE_KILL){
        if(isValidKill(theBoard,s.circleBefore,s.seatBefore)){
            theBoard->position[s.circleBefore][s.seatBefore] = DEAD;
            theBoard->pChosenBefore.rx = -1;
            theBoard->pieceNum[EMPTY]++;
            theBoard->pieceNum[CHANGE_COLOR(theBoard->currentColor)]--;
            theBoard->isKilling--;
            return setAfterPose(theBoard);
        }
        else{
            return 0;
        }
    }
    else if(s.action == ACT_MOVE_KILL){
        if(isValidKill(theBoard,s.circleBefore,s.seatBefore)){

            theBoard->position[s.circleBefore][s.seatBefore] = EMPTY;
            theBoard->pieceNum[CHANGE_COLOR(theBoard->currentColor)]--;
            theBoard->isKilling--;
            return setAfterMove(theBoard);
        }
        else{
            return 0;
        }
    }
    else if(s.action == ACT_MOVE){
        if(isValidMove(theBoard,s)){

            theBoard->position[s.circleBefore][s.seatBefore] = EMPTY;
            theBoard->position[s.circleAfter][s.seatAfter] = theBoard->currentColor;
            theBoard->isMoving = false;
            theBoard->pChosen.circle = s.circleAfter;
            theBoard->pChosen.seat = s.seatAfter;
            theBoard->pChosenBefore.circle = s.circleBefore;
            theBoard->pChosenBefore.seat = s.seatBefore;
            theBoard->pChosenBefore.rx = VALID;
            theBoard->isKilling = isGetThree(theBoard,s.circleAfter,s.seatAfter);
            return setAfterMove(theBoard);
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }

}

int Generator::setStepLast(ChessBook *c,Board *theBoard) //棋盘数据 上一步
{
    Step s = c->steps[c->currentNum - 1];
    if(s.action == ACT_CHANGE){
        theBoard->changeSide();
        return 0;
    }
    else if(s.action == ACT_POSE){
        if(theBoard->pieceNum[EMPTY] + theBoard->pieceNum[BLACK] + theBoard->pieceNum[WHITE] == POINT){
            theBoard->fillDead();
        }

        //找出pChosen
        int j;
        for(j = c->currentNum - 1;j > 1;j--){
            if(c->steps[j - 1].action == ACT_CHANGE || c->steps[j - 1].action == ACT_POSE_KILL){
                continue;
            }
            else if(c->steps[j - 1].action == ACT_POSE){
                theBoard->pChosen.circle = c->steps[j - 1].circleBefore;
                theBoard->pChosen.seat = c->steps[j - 1].seatBefore;
                break;
            }
        }
        if(j == 1){
            theBoard->pChosen.circle = -1;
            theBoard->pChosen.seat = -1;
        }
        theBoard->pChosenBefore.rx = -1;
        theBoard->currentStage = POSE;
        theBoard->position[s.circleBefore][s.seatBefore] = EMPTY;
        theBoard->pieceNum[s.subject]--;
        theBoard->currentColor = s.subject;
        theBoard->isKilling = 0;
        return GAME_EXCH;

    }
    else if(s.action == ACT_POSE_KILL){
        if(theBoard->pieceNum[EMPTY] + theBoard->pieceNum[BLACK] + theBoard->pieceNum[WHITE] == POINT){
            theBoard->fillDead();
        }
        //不用找pChosen 杀棋不改变pChosen
        theBoard->pChosenBefore.rx = -1;
        theBoard->position[s.circleBefore][s.seatBefore] = CHANGE_COLOR(s.subject);
        theBoard->pieceNum[CHANGE_COLOR(s.subject)]++;
        theBoard->currentColor = s.subject;
        theBoard->currentStage = POSE;
        theBoard->pieceNum[EMPTY]--;
        theBoard->isKilling++;
        return GAME_CON;

    }
    else if(s.action == ACT_MOVE_KILL){
        //不用找pChosen 杀棋不改变pChosen
        theBoard->position[s.circleBefore][s.seatBefore] = CHANGE_COLOR(s.subject);
        theBoard->pieceNum[CHANGE_COLOR(s.subject)]++;
        theBoard->currentColor = s.subject;
        theBoard->currentStage = MOVE;
        theBoard->isKilling++;
        theBoard->isMoving = false;
        return GAME_CON;

    }
    else if(s.action == ACT_MOVE){

        theBoard->position[s.circleAfter][s.seatAfter] = EMPTY;
        theBoard->position[s.circleBefore][s.seatBefore] = s.subject;
        theBoard->currentColor = s.subject;
        theBoard->currentStage = MOVE;
        theBoard->isKilling = 0;
        theBoard->isMoving = false;

        //找出pChosen
        for(int j = c->currentNum - 1;j > 0;j--){
            if(c->steps[j - 1].action == ACT_CHANGE || c->steps[j - 1].action == ACT_MOVE_KILL){
                continue;
            }
            else if(c->steps[j - 1].action == ACT_MOVE){
                theBoard->pChosen.circle = c->steps[j - 1].circleAfter;
                theBoard->pChosen.seat = c->steps[j - 1].seatAfter;
                theBoard->pChosenBefore.circle = c->steps[j - 1].circleBefore;
                theBoard->pChosenBefore.seat = c->steps[j - 1].seatBefore;
                theBoard->pChosenBefore.rx = VALID;
                break;
            }
            else if(c->steps[j - 1].action == ACT_POSE){
                theBoard->pChosen.circle = -1;
                theBoard->pChosen.seat = -1;
                return GAME_MOVE;
            }
        }
        return GAME_EXCH;

    }
    else{
        return 0;
    }
}

