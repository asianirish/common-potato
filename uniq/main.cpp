#include "TimeValue.h"

#include <QCoreApplication>
#include <QDebug>

using namespace uniq;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "uniq";

    TimeValue tv;
    auto n = tv;

    for (int i = 0; i < 1000000; i++) {
        qDebug() << "Unique value:" << n;
    }

    return a.exec();
}
