#include <QCoreApplication>
#include <iostream>
#include <QDebug>

#include "gfunc.h"

using namespace std;
using namespace util;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str = int64_t2string(129197106131337, 36);
    cout << "util test string: " << str << "\n";

    QString qstr = int64_t2qstring(129197106131337, 36);
    qDebug() << "util test qstring:" << qstr;

    QString qstr1 = int64_t2qstring_ext(129197106131337);
    qDebug() << "util test qstring (base62):" << qstr1;

    return a.exec();
}
