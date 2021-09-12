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


    for (int i = 0; i < 10; i++) {
        auto n = TimeValue();
        qDebug() << "Unique value:" << n;
    }

    for (int i = 0; i < 10; i++) {
        string s = TimeStringValue();
        cout << "Unique string value:" << s << "\n";
    }

    for (int i = 0; i < 10; i++) {
        QString s = UuidValue();
        qDebug() << "Unique qstring value:" << s;
    }

    for (int i = 0; i < 10; i++) {
        QString s = CompactUuidValue();
        qDebug() << "Unique compact qstring value:" << s;
    }

    for (int i = 0; i < 10; i++) {
        QString s = TimeQStringValue();
        qDebug() << "Unique qstring value:" << s;
    }

    return a.exec();
}
