#ifndef GRID_H
#define GRID_H

#include <QVector>
#include <stdarg.h>

class Grid
{
private:
    QVector<QVector<int>> data;

public:
    Grid();
    Grid(int n...);
    Grid(int n, QVector<int> arg);
    void flip_vert();
    void flip_horz();
    int get_size();
    int get_element(int, int);
};

#endif // GRID_H
