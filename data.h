#ifndef DATA_H
#define DATA_H

#include <QVector>
#include <QString>

#include "grid.h"

class Data
{
private:
    QVector<QString> msg;

public:
    Data();
    Data(QStringList strs);
    QString apply_grid(Grid* grid);
};

#endif // DATA_H
