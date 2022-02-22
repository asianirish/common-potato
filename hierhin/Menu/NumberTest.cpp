#include "NumberTest.h"

#include <util/gfunc.h>

#include <QDebug>

NumberTest::NumberTest()
{

}

QVariant NumberTest::simplyAct(const QVariantList &args, const menu::TaskId &taskId)
{
    Q_UNUSED(args);
    Q_UNUSED(taskId);

    qDebug() << "3,14 is a number: " << potato_util::isNumber(3.14);
    qDebug() << "3,14 is an integer: " << potato_util::isInteger(3.14);

    qDebug() << "3,0 is a number: " << potato_util::isNumber(3.);
    qDebug() << "3,0 is an integer: " << potato_util::isInteger(3.);

    float fpi = 3.14;
    qDebug() << "float is a number: " << potato_util::isNumber(fpi);
    qDebug() << "float is an integer: " << potato_util::isInteger(fpi);

    double dpi = 3.14;
    qDebug() << "double is a number: " << potato_util::isNumber(dpi);
    qDebug() << "double is an integer: " << potato_util::isInteger(dpi);

    int num = 100;
    qDebug() << "int is a number: " << potato_util::isNumber(num);
    qDebug() << "int is an integer: " << potato_util::isInteger(num);

    return QString("end of the test");
}
