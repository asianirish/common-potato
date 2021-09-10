#include <QCoreApplication>
#include <iostream>
#include <QDebug>

#include "gfunc.h"

using namespace std;
using namespace util;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str = int64_t2string(12919710613, 36);
    cout << "util test string: " << str << "\n";

    QString qstr = int64_t2qstring(12919710613, 36);
    qDebug() << "util test qstring:" << qstr;

    return a.exec();
}
