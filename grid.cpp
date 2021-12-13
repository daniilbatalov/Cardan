#include "grid.h"

Grid::Grid()
{
    data = QVector<QVector<int>>();
}
Grid::Grid(int n, ...)
{
    va_list var;
    int temp;
    va_start(var, n);
    data = QVector<QVector<int>>(n);
    for (int i = 0; i < n; i++)
    {
        data[i] = QVector<int>(n, 0);
    }
    QVector<int> args;

    while (-1 != (temp = va_arg(var, int)))
    {
        args.append(temp);
    }
    va_end(var);

    for(int i = 0; i < args.size(); i += 2)
    {
        data[args.at(i)][args.at(i + 1)] = 1;
    }
}
Grid::Grid(int n, QVector<int> arg)
{

    data = QVector<QVector<int>>(n);
    for (int i = 0; i < n; i++)
    {
        data[i] = QVector<int>(n, 0);
    }

    for(int i = 0; i < arg.size(); i += 2)
    {
        data[arg.at(i)][arg.at(i + 1)] = 1;
    }
}
void Grid::flip_vert()
{
    int size = data.size();
    QVector<QVector<int>> temp = QVector<QVector<int>>(size);
    for (int i = 0; i < size; i++)
    {
        temp[i] = QVector<int>(size);
    }
    for(int i = 0; i < size; i++)
    {
        temp[size - 1 - i] = data[i];
    }
    data = temp;
}
void Grid::flip_horz()
{
    int size = data.size();
    QVector<QVector<int>> temp = QVector<QVector<int>>(size);
    for (int i = 0; i < size; i++)
    {
        temp[i] = QVector<int>(size);
    }
    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            temp[i][size - j - 1] = data[i][j];
        }
    }
    data = temp;
}
int Grid::get_size()
{
    return data.size();
}
int Grid::get_element(int i, int j)
{
    return data.at(i).at(j);
}
