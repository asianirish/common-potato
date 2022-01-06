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
        qDebug() << "str:" << *lr.ptr(0);
    }


    return true;
}
