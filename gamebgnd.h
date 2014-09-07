#ifndef GAMEBGND_H
#define GAMEBGND_H

#include <QObject>
#include "level.h"
#include "player.h"
#include <QDir>

class GameBgnd : public QObject
{
    Q_OBJECT
    QDir levelFolder_;
    QStringList levels_;
    int levelNum_;
    Level *curentLevel_;
    Player *player_;
public:
    explicit GameBgnd(QObject *parent = 0);

    void openLevel(int level);

    Q_INVOKABLE int DuskCount(){
        return curentLevel_->duskCount();
    }
    Q_INVOKABLE int size(){
        int retVal = curentLevel_->dimension();
        return retVal;
    }
    Q_INVOKABLE int getCell(int i){
        int retVal = curentLevel_->cells_[player_->curDusk_][i/size()][i%size()];
        return retVal;
    }
    Q_INVOKABLE int getXCell(int i, int width){
        int x = i%size();
        return width/size()*x;
    }
    Q_INVOKABLE int getYCell(int i, int width){
        int y = i/size();
        return width/size()*y;
    }

    Q_INVOKABLE int levelCount(){
        return levels_.size();
    }

    Q_INVOKABLE bool duskUp(){
        if((player_->curDusk_ < curentLevel_->duskCount()-1)&&
                (!curentLevel_->cells_[player_->curDusk_+1][player_->y_][player_->x_])){
            player_->curDusk_++;
            return true;
        }
        return false;
    }
    Q_INVOKABLE bool duskDown(){
        if((player_->curDusk_ > 0)&&
                (!curentLevel_->cells_[player_->curDusk_-1][player_->y_][player_->x_])){
            player_->curDusk_--;
            return true;
        }
        return false;
    }

    Q_INVOKABLE bool stepUp(){
        if((player_->y_ > 0)&&
                (!curentLevel_->cells_[player_->curDusk_][player_->y_-1][player_->x_])) {
            player_->y_--;
            return true;
        }
        return false;
    }
    Q_INVOKABLE bool stepDown(){
        if((player_->y_ < curentLevel_->dimension()-1)&&
                (!curentLevel_->cells_[player_->curDusk_][player_->y_+1][player_->x_])) {
            player_->y_++;
            return true;
        }
        return false;
    }
    Q_INVOKABLE bool stepRight(){
        if((player_->x_ < curentLevel_->dimension()-1)&&
                (!curentLevel_->cells_[player_->curDusk_][player_->y_][player_->x_+1])){
            player_->x_++;
            return true;
        }
        return false;
    }
    Q_INVOKABLE bool stepLeft(){
        if((player_->x_ > 0)&&
                (!curentLevel_->cells_[player_->curDusk_][player_->y_][player_->x_-1])){
            player_->x_--;
            return true;
        }
        return false;
    }
    Q_INVOKABLE int playerX(){
        return player_->x_;
    }
    Q_INVOKABLE int playerY(){
        return player_->y_;
    }
    Q_INVOKABLE int playerCurDusk(){
        return player_->curDusk_;
    }

signals:

public slots:


};

#endif // GAMEBGND_H
