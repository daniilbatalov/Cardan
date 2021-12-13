#include "data.h"

Data::Data()
{
    msg = QVector<QString>();
}

Data::Data(QStringList strs)
{
    msg.append(strs);
}

QString Data::apply_grid(Grid* grid)
{
    QString res;
    int size = grid->get_size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(grid->get_element(i, j))
            {
                res.append(msg.at(i).at(j));
            }
        }
    }
    return res;
}
