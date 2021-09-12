#include "TimeStringValue.h"
#include "UuidValue.h"
#include "CompactUuidValue.h"
#include "TimeQStringValue.h"

#include <iostream>

#include <QCoreApplication>
#include <QDebug>
#include <QString>

using namespace uniq;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "uniq";

    TimeValue tv;
    auto n = tv;

    for (int i = 0; i < 10; i++) {
        qDebug() << "Unique value:" << n;
    }

    TimeStringValue tsv;
    for (int i = 0; i < 10; i++) {
        string s = tsv;
        cout << "Unique string value:" << s << "\n";
    }

    UuidValue uuv;
    for (int i = 0; i < 10; i++) {
        QString s = uuv;
        qDebug() << "Unique qstring value:" << s;
    }

    CompactUuidValue cuuv;
    for (int i = 0; i < 10; i++) {
        QString s = cuuv;
        qDebug() << "Unique compact qstring value:" << s;
    }

    TimeQStringValue tqsv;
    for (int i = 0; i < 10; i++) {
        QString s = tqsv;
        qDebug() << "Unique qstring value:" << s;
    }

    return a.exec();
}
