#include "ChildTest.h"

#include <hierhin/Method.h>
#include <hierhin/sys/GetChildren.h>

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

//    connect(_nd->launcher().get(), &menu::Launcher::ready, this, &ChildTest::onReady);
    _listener = new menu::RedirectActionListener(this);
    connect(_listener, &menu::RedirectActionListener::ready, this, &ChildTest::onReadyResult);
}

void ChildTest::actSpecific(const QVariantList &args, const menu::TaskId &taskId)
{
    Q_UNUSED(args);
    Q_UNUSED(taskId);

//    qDebug() << "conversion:";
    QList<nav::ItemRef> childRefs = _nd->childRefs();
    QVariant childRefsVar = QVariant::fromValue(childRefs);
    QList<nav::ItemRef> outChildRefs = childRefsVar.value<QList<nav::ItemRef>>();

    for (auto &refStr : outChildRefs) {
        qDebug() << "REF_STR:" << refStr;
    }

    qDebug() << "\n(1) ======================================================\n";
    qDebug() << "to json:";
    qDebug().noquote() << "NODE:" << _nd->toJson();

    menu::TaskInfo taskInfo(&_taskId, {_listener});

    _nd->execute(METHOD_CLASS(sys::GetChildren), QVariantList(), taskInfo);
}

void ChildTest::onReady(const QVariant value, const menu::TaskId &taskId)
{
    if (_taskId != taskId) {
        return;
    }

    qDebug() << "\n(2) ======================================================\n";
    qDebug() << "on GetChildren:";
    qDebug() << "TEST IS READY:" << taskId;

    qDebug() << "to json:";
    qDebug().noquote() << "NODE:" << _nd->toJson();


    qDebug() << "\n(3) ======================================================\n\n";

//    QStringList lst = value.value<hierhin::IdList>();
    QList<nav::ItemRef> lst = value.value<QList<nav::ItemRef>>();

    for (auto &ref : lst) {
        qDebug() << "CHILD REF:" << ref;
        auto child = ref.ptr(_nd);
        qDebug().noquote() << "CHILD:" << child->toJson();
    }

    emit done(menu::Result(true));
}

void ChildTest::onReadyResult(const menu::Result &result)
{
    if (_taskId != _taskId) {
        return;
    }

    qDebug() << "\n!(2) ======================================================\n";
    qDebug() << "on GetChildren:";
    qDebug() << "TEST IS READY:" << result.taskId();

    qDebug() << "to json:";
    qDebug().noquote() << "NODE:" << _nd->toJson();


    qDebug() << "\n!(3) ======================================================\n\n";

//    QStringList lst = value.value<hierhin::IdList>();
    QList<nav::ItemRef> lst = result.value().value<QList<nav::ItemRef>>();

    for (auto &ref : lst) {
        qDebug() << "!CHILD REF:" << ref;
        auto child = ref.ptr(_nd);
        qDebug().noquote() << "CHILD:" << child->toJson();
    }

    emit done(menu::Result(true));
}
