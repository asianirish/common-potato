#include "CommandTest.h"

#include <hierhin/direct/NodeImpl.h>

#include <QDebug>

using namespace hierhin;

CommandTest::CommandTest()
{

}

QVariant CommandTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    auto nd = NodePtr(new direct::NodeHashImpl());
    nd->setEssenceClassName("TestEssenceA");
    nd->setProperty("value", 13);

    nd->execute();

    qDebug().noquote() << nd->toJson();

    return true;
}
