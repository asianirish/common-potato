#include "ChildTest.h"

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

    _nd->addChild(ndA, "right");
    _nd->addChild(ndB, "left");
    _nd->addChild(ndC);
    _nd->addChild(ndD);

    ndA->setProperty("name", "Alina");
    ndB->setProperty("name", "Boris");
    ndC->setProperty("name", "Charlie");
    ndD->setProperty("name", "Daisy");

    connect(_nd->launcher().get(), &menu::Launcher::ready, this, &ChildTest::onReady);
}

QVariant ChildTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    qDebug() << "conversion:";
    QList<nav::ItemRef> childRefs = _nd->childRefs();
    QVariant childRefsVar = QVariant::fromValue(childRefs);
    QList<nav::ItemRef> outChildRefs = childRefsVar.value<QList<nav::ItemRef>>();

    for (auto &refStr : outChildRefs) {
        qDebug() << "REF_STR:" << refStr;
    }

    qDebug() << "\n======================================================\n";
    qDebug() << "to json:";
    qDebug().noquote() << "NODE:" << _nd->toJson();

    _nd->execute("sys::GetChildren");

    return true;
}

void ChildTest::onReady(const QVariant value, const menu::TaskId &taskId)
{
    qDebug() << "\n======================================================\n";
    qDebug() << "on GetChildren:";
    qDebug() << "TEST IS READY:" << taskId;
//    QStringList lst = value.value<hierhin::IdList>();
    QList<nav::ItemRef> lst = value.value<QList<nav::ItemRef>>();

    for (auto &ref : lst) {
        qDebug() << "CHILD REF:" << ref;
        auto child = ref.ptr(_nd);
        qDebug().noquote() << "CHILD:" << child->toJson();
    }
}
