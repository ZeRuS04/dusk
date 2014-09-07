#include "player.h"

Player::Player(QObject *parent) :
    QObject(parent)
{
    x_ = 0;
    y_ = 0;
    curDusk_ = 0;
}


int Player::curDusk() const
{
    return curDusk_;
}

void Player::setCurDusk(int curDusk)
{
    curDusk_ = curDusk;
}

