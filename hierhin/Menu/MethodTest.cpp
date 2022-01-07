#include "MethodTest.h"
#include "Test/TestEssenceA.h"

#include <hierhin/direct/NodeImpl.h>

#include <QDebug>

using namespace hierhin;

MethodTest::MethodTest()
{

}

QVariant MethodTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)
    auto nd = NodePtr(new direct::NodeHashImpl());
    nd->setEssenceClassName("TestEssenceA");
    nd->setProperty("value", 13);

    qDebug().noquote() << "BEFORE:" << nd->toJson();

    nd->execute("PlusValue", {12});

    qDebug().noquote() << "AFTER:" << nd->toJson();
    return true;
}
