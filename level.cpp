#include "level.h"




Level::Level(const QString &fileLlv, QObject *parent)
{
    duskCount_ = 0, dimension_ = 0;
    QVector<QVector<int> > column;
    QFile file(fileLlv);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        char buf[1024];
        qint64 lineLength;
        while(!file.atEnd()){
            lineLength = file.readLine(buf, sizeof(buf));
            QString bufStr = QString::fromUtf8(buf);
            if (lineLength != -1) {

                if(bufStr.at(0) == '#'){
                    if(duskCount_){
                        cells_.push_back(column);
                        column.clear();
                    }
                    duskCount_++;

                    continue;
                }
                if(bufStr.at(0) == '!'){
                    cells_.push_back(column);
                    column.clear();
                    return;
                }
                QVector<int> row;
                for(int i = 0; i < bufStr.size()-1; i++){
                    QString s = bufStr.at(i) ;
                    if((s != "0")&&(s != "1")){
                        qDebug() << "Bad level";
                        return;
                    }
                    row.push_back(QString(bufStr.at(i)).toInt());
                }
                dimension_ = row.size();
                column.push_back(row);


            }
            else
                break;

        }
        qDebug() << "Bad level";
        return;
    }
    qDebug() << "Could not open file";
    return;
}

int Level::duskCount() const
{
    return duskCount_;
}

void Level::setDuskCount(int duskCount)
{
    duskCount_ = duskCount;
}

int Level::dimension() const
{
    return dimension_;
}

void Level::setDimension(int dimension)
{
    dimension_ = dimension;
}
