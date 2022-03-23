#include "CommandTest.h"

#include <hierhin/direct/NodeImpl.h>
#include <ex/Exception.h>

#include <QDebug>

using namespace hierhin;

CommandTest::CommandTest()
{

}

QVariant CommandTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)
/*
    try {
    auto nd = NodePtr(new direct::NodeHashImpl());
    nd->setEssenceClassName("TestEssenceA");
    nd->setProperty("value", 13);

    nd->execute();

    qDebug().noquote() << nd->toJson();

    nd->execute("doubleValue");

    qDebug().noquote() << nd->toJson();

    nd->execute("multValue");

    qDebug().noquote() << nd->toJson();

    nd->execute("sumValue", {12, 13});

    qDebug().noquote() << nd->toJson();

    nd->execute("invoke");

    qDebug().noquote() << nd->toJson();

    } catch (ex::Exception &e) {
        qDebug() << "AN ERROR HAS OCCURRED:" << e.cause();
    }
*/
    return true;
}
