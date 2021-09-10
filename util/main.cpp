#include <QCoreApplication>
#include <iostream>

#include "gfunc.h"

using namespace std;
using namespace util;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str = int64_t2string(129, 36);
    cout << "util test: " << str << "\n";

    return a.exec();
}
