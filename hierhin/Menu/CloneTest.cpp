#include "CloneTest.h"

#include <hierhin/direct/NodeImpl.h>

#include <QDebug>

using namespace hierhin;

CloneTest::CloneTest()
{

}

QVariant CloneTest::simplyAct(const QVariantList &args, const menu::TaskId &taskId)
{
    Q_UNUSED(args);
    Q_UNUSED(taskId);

    auto nd = NodePtr(new direct::NodeHashImpl());

    nd->setEssenceClassName("TestEssenceA");

    int nnn;
    nnn = 13;
    nd->setProperty("value", nnn);

    QString email = "someone@same.com";
    nd->setProperty("email", email);

    QString phone = "+49000333444";
    nd->setProperty("phone", phone);

    auto child = ItemPtr(new direct::ItemHashImpl());
    child->setEssenceClassName("TestEssenceB");
    child->setProperty("value", nnn);
    nd->addChild(child, "left");

    qDebug().noquote() << "ORIGINAL NODE:" << nd->toJson();

    auto cloneNode = nd->clone();

    qDebug().noquote() << "CLONE NODE:" << cloneNode->toJson();




    return true;
}
