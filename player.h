#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
//#include "gamebgnd.h"

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);

    int curDusk() const;
    void setCurDusk(int curDusk);

    int x_;
    int y_;
    int curDusk_;
signals:

public slots:

};

#endif // PLAYER_H
