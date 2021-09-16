#include "TimeStringValue.h"
#include "UuidValue.h"
#include "CompactUuidValue.h"
#include "TimeQStringValue.h"

#include <util/Factory.h>

#include <iostream>

#include <QCoreApplication>
#include <QDebug>
#include <QString>

using namespace uniq;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "uniq";

    REGISTER_CLASS_FOR_UTIL_FACTORY(Value<QString>, UuidValue);
    REGISTER_CLASS_FOR_UTIL_FACTORY(Value<QString>, CompactUuidValue);
    REGISTER_CLASS_FOR_UTIL_FACTORY(Value<QString>, TimeQStringValue);

    const QVector<string> ValueClassNames{"UuidValue", "CompactUuidValue", "TimeQStringValue"};



    for (int i = 0; i < 10; i++) {
        auto n = TimeValue();
        qDebug() << "Unique value:" << n;
    }

    for (int i = 0; i < 10; i++) {
        string s = TimeStringValue();
        cout << "Unique string value:" << s << "\n";
    }

    qDebug() << "..........................................";

    for (auto &className : ValueClassNames) {

        auto value = util::Factory<Value<QString>>::create(className);
        for (int i = 0; i < 10; i++) {
            QString s = *value;
            qDebug() << "Unique qstring value:" << s;
        }

    }

    return a.exec();
}
