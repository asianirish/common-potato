#include "CuteContainerTest.h"
#include <util/CuteContainer.h>
#include <ItemContainer.h>
#include <hierhin/direct/NodeImpl.h>

using namespace potato_util;
using namespace hierhin;
using namespace hierhin::direct;

CuteContainerTest::CuteContainerTest()
{

}

QVariant CuteContainerTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    {
        CuteContainer<QString, int> cc;
        cc.append(12);
        cc.insert("zzz", 23);
        cc.insert("bbb", 32);
        cc.insert("aaa", 44);
        cc.append(55);

        for (auto num : cc) {
            qDebug() << "NUMBER:" << num;
        }

        for (auto &key : cc.keys()) {
            qDebug() << "KEY:" << key << "NUMBER:" << cc.value(key);
        }
    }

    {
        auto ndA = NodePtr(new NodeHashImpl());
        auto ndB = NodePtr(new NodeHashImpl());
        auto ndC = NodePtr(new NodeHashImpl());
        auto ndD = NodePtr(new NodeHashImpl());

        ndA->setProperty("name", "Alina");
        ndB->setProperty("name", "Boris");
        ndC->setProperty("name", "Charlie");
        ndD->setProperty("name", "Daisy");

        ItemContainer container;

        container.append(ndA);
        container.append(ndB);
        container.append(ndC);
        container.append(ndD);

        for (const auto &item : container) {
            qDebug().noquote() << "ITEM:" << item->toJson();
        }

    }

    return true;
}
