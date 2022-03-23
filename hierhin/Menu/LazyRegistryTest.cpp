#include "LazyRegistryTest.h"
#include <util/LazyRegistry.h>

#include <QDebug>

using namespace potato_util;

LazyRegistryTest::LazyRegistryTest()
{

}

QVariant LazyRegistryTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    LazyRegistry<int, QString> lr;

    {
        auto strPtr = lr.ptr(0);
        *strPtr = "HELLO";
    }

    {
        qDebug() << "str:" << lr.obj(0);
        lr.obj(0) = "BYE";
        qDebug() << "str:" << lr.obj(0);
        lr.obj(1) = "HI";
        qDebug() << "str:" << lr.obj(1);
        lr.ptr(1)->append(" THERE");
        qDebug() << "str:" << lr.obj(1);
    }

    return true;
}
