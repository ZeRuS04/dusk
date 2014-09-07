#ifndef LEVEL_H
#define LEVEL_H
#include <QtDebug>
#include <QObject>
#include <QVector>
#include <QFile>
#include <QFileInfo>

class Level : public QObject
{
    Q_OBJECT
    int duskCount_;
    int dimension_;


public:
    explicit Level(const QString &fileLlv, QObject *parent = 0);

    QVector<QVector<QVector<int> > > cells_;

    int duskCount() const;
    void setDuskCount(int duskCount);
    int dimension() const;
    void setDimension(int dimension);

signals:

public slots:

};

#endif // LEVEL_H
