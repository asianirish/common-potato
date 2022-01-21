#include "LinkTest.h"

#include <hierhin/nav/ItemRef.h>
#include <hierhin/direct/NodeImpl.h>
#include <menu/Launcher.h>
#include <hierhin/ex/Exception.h>

#include <QDebug>

using namespace hierhin;
using namespace hierhin::nav;
using namespace hierhin::direct;

LinkTest::LinkTest()
{
    _nd = NodePtr(new NodeHashImpl());
    auto ndLeft = NodePtr(new NodeHashImpl());
    auto ndRight = NodePtr(new NodeHashImpl());
    auto link = NodePtr(new NodeHashImpl());

    _nd->setEssenceClassName("TestEssenceA");
    ndLeft->setEssenceClassName("TestEssenceB");
    ndRight->setEssenceClassName("TestEssenceA");

    ndLeft->setProperty("name", "Alice");
    ndRight->setProperty("name", "Bob");

    _nd->addChild(ndLeft, "left");
    _nd->addChild(ndRight, "right");

    ItemRef targetRef(ndRight->absPath());
    ndLeft->setLink(targetRef);
}

QVariant LinkTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    try {
        auto left = _nd->childByRole("left");
        qDebug().noquote() << "LEFT:" << left->toJson();

        auto leftNd = left.dynamicCast<Node>();


        auto refs = leftNd->targets();

        for (auto &ref : refs) {
            auto target = ref.ptr(left);
            qDebug().noquote() << "TARGET:" << target->toJson();
        }
    } catch (ex::Exception &e) {
        qDebug() << "ex::Exception ERROR MSG:" << e.cause();
    } catch (const QString &msg) {
        qDebug() << "QString ERROR MSG:" << msg;
    } catch (const char *msg) {
        qDebug() << "const char * ERROR MSG:" << msg;
    }

    return true;
}
