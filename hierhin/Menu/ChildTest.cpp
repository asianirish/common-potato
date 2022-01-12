#include "ChildTest.h"

#include <type.h>
#include <hierhin/direct/NodeImpl.h>
#include <menu/Launcher.h>

#include <QDebug>

using namespace hierhin;
using namespace hierhin::nav;
using namespace hierhin::direct;

ChildTest::ChildTest()
{
    _nd = NodePtr(new NodeHashImpl());
    auto ndA = NodePtr(new NodeHashImpl());
    auto ndB = NodePtr(new NodeHashImpl());
    auto ndC = NodePtr(new NodeHashImpl());
    auto ndD = NodePtr(new NodeHashImpl());

    _nd->setEssenceClassName("TestEssenceA");

    _nd->addChild(ndA);
    _nd->addChild(ndB);
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

    qDebug() << "\n======================================================\n";

    qDebug().noquote() << "NODE:" << _nd->toJson();

    _nd->execute("sys::GetChildren");

    return true;
}

void ChildTest::onReady(const QVariant value)
{

    QStringList lst = value.value<hierhin::IdList>();

    for (auto &id : lst) {
//        qDebug() << "CHILD ID:" << id;
        auto child = _nd->child(id);
        qDebug().noquote() << "CHILD:" << child->toJson();
    }
}
