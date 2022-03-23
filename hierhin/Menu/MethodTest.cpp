#include "MethodTest.h"
#include "Test/TestEssenceA.h"

#include <hierhin/direct/NodeImpl.h>

#include <hierhin/sys/GetName.h>
#include <hierhin/sys/GetProperty.h>
#include <hierhin/sys/SetProperty.h>
#include <hierhin/sys/GetClassName.h>
#include <hierhin/sys/GetMethodNames.h>
#include <hierhin/sys/GetClassNames.h>

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
    nd->setProperty("name", "programA");

    qDebug().noquote() << "BEFORE:" << nd->toJson();

    nd->execute("PlusValue", {12});

    qDebug().noquote() << "AFTER ARG == 12:" << nd->toJson();

    nd->execute("PlusValue");

    qDebug().noquote() << "AFTER EMPTY ARG LIST:" << nd->toJson();

    nd->execute(METHOD_CLASS(sys::GetName));
    nd->execute(METHOD_CLASS(sys::GetProperty), {"value"});
    nd->execute(METHOD_CLASS(sys::SetProperty), {"value", 1337});
    nd->execute(METHOD_CLASS(sys::SetProperty), {"name", "Elite"});

    qDebug().noquote() << "AFTER sys::SetProperty:" << nd->toJson();

    nd->execute(METHOD_CLASS(sys::GetClassName));
    nd->execute(METHOD_CLASS(sys::GetMethodNames));
    nd->execute(METHOD_CLASS(sys::GetClassNames));

    return true;
}
