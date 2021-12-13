#include <QCoreApplication>
#include <iostream>
#include <QTextStream>
#include <QString>
#include "data.h"
#include "grid.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int n = a.arguments().at(1).toInt();
    QVector<int> args;
    for(int i = 2; i < argc - n; i++)
        args.append(a.arguments().at(i).toInt());
    QStringList mssg;
    for(int i = argc - n ; i < argc; i++)
        mssg.append(a.arguments().at(i));
    Grid grid = Grid(n, args);
    Data message = Data(mssg);
    QStringList result;
    result.append(message.apply_grid(&grid));
    grid.flip_horz();
    result.append(message.apply_grid(&grid));
    grid.flip_vert();
    result.append(message.apply_grid(&grid));
    grid.flip_horz();
    result.append(message.apply_grid(&grid));
    result.swapItemsAt(2, 3);
    for(int i = 0; i < 4; i++)
        QTextStream(stdout) << result.at(i);
    QCoreApplication::exit(0);
    return 0;
}
