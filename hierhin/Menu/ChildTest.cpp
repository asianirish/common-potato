#include "ChildTest.h"

#include <hierhin/Method.h>
#include <hierhin/sys/GetChildren.h>
#include <hierhin/sys/CallChildren.h>
#include <hierhin/sys/SetProperty.h>
#include <hierhin/sys/GetProperty.h>

#include <hierhin/ex/Exception.h>

#include <menu/math/Sum.h>

#include <type.h>

//#include <hierhin/direct/NodeImpl.h>
#include <hierhin/cute/NodeImpl.h>

#include <menu/Launcher.h>


#include <QDebug>

using namespace hierhin;
using namespace hierhin::nav;

//using namespace hierhin::direct;
using namespace hierhin::cute;

ChildTest::ChildTest()
{
    _nd = NodePtr(new NodeHashImpl());
    auto ndA = NodePtr(new NodeHashImpl());
    auto ndB = NodePtr(new NodeHashImpl());
    auto ndC = NodePtr(new NodeHashImpl());
    auto ndD = NodePtr(new NodeHashImpl());

    _nd->setEssenceClassName("TestEssenceAExt");
    ndA->setEssenceClassName("TestEssenceAExt");
    ndB->setEssenceClassName("TestEssenceB");
    ndC->setEssenceClassName("TestEssenceAExt");
    ndD->setEssenceClassName("TestEssenceB");

    try {
        ndA->setProperty("value", 121);
        ndB->setProperty("value", 234);
        ndC->setProperty("value", 345);
        ndD->setProperty("value", 456);
    } catch (hierhin::ex::Exception &ex) {
        qDebug() << "ERROR: " << ex.cause();
    }

    _nd->addChild(ndA, "right");
    _nd->addChild(ndB, "left");
    _nd->addChild(ndC);
    _nd->addChild(ndD);

    ndA->setProperty("name", "Alina");
    ndB->setProperty("name", "Boris");
    ndC->setProperty("name", "Charlie");
    ndD->setProperty("name", "Daisy");

}

menu::Result ChildTest::actSpecific(const QVariantList &args, const menu::TaskId &taskId)
{
    Q_UNUSED(args);
    Q_UNUSED(taskId);

    menu::Result result;

//    qDebug() << "conversion:";
    QList<nav::ItemRef> childRefs = _nd->childRefs();
    QVariant childRefsVar = QVariant::fromValue(childRefs);
    QList<nav::ItemRef> outChildRefs = childRefsVar.value<QList<nav::ItemRef>>();

    for (auto &refStr : outChildRefs) {
        qDebug() << "REF_STR:" << refStr;
    }

    qDebug() << "\n======================================================\n";
    qDebug() << "to json:";
    qDebug().noquote() << "NODE:" << _nd->toJson();

    try {
        result = _nd->execute(METHOD_CLASS(sys::CallChildren),
                     {
                         METHOD_CLASS(sys::GetProperty), ACTION_CLASS(menu::math::Sum), "value"
                     });

        qDebug() << "RESULT:" << result.value().toInt();
    } catch (const QString &err) {
        qDebug() << "ERROR:" << err;
            return menu::Result(); //TODO: return error result here
    }

    return result;
}
