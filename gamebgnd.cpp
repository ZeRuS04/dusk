#include "gamebgnd.h"

GameBgnd::GameBgnd(QObject *parent) :
    QObject(parent)
{
    levelFolder_ = QDir("C:\\levels\\") ;
    levels_ = levelFolder_.entryList(QDir::Files, QDir::Name);
    levelNum_ = 1;
    for(int i = 0; i < levels_.size(); i++)
        if(levels_.at(i).right(4) != ".llv")
            levels_.removeAt(i);
    curentLevel_ = new Level(levelFolder_.absolutePath()+"/"+levels_.at(0), this);

    player_ = new Player(this);
}

void GameBgnd::openLevel(int level)
{
    curentLevel_ = new Level(levelFolder_.absolutePath()+"/"+levels_.at(level), this);
}
