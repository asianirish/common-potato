#include "NumberTest.h"

#include <util/gfunc.h>

#include <QDebug>

NumberTest::NumberTest()
{

}

QVariant NumberTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    qDebug() << "3,14 is a number: " << util::isNumber(3.14);
    qDebug() << "3,14 is an integer: " << util::isInteger(3.14);

    qDebug() << "3,0 is a number: " << util::isNumber(3.);
    qDebug() << "3,0 is an integer: " << util::isInteger(3.);

    float fpi = 3.14;
    qDebug() << "float is a number: " << util::isNumber(fpi);
    qDebug() << "float is an integer: " << util::isInteger(fpi);

    double dpi = 3.14;
    qDebug() << "double is a number: " << util::isNumber(dpi);
    qDebug() << "double is an integer: " << util::isInteger(dpi);

    int num = 100;
    qDebug() << "int is a number: " << util::isNumber(num);
    qDebug() << "int is an integer: " << util::isInteger(num);

    return QString("end of the test");
}
