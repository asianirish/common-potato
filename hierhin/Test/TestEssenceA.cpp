#include "TestEssenceA.h"

#include <hierhin/Item.h>
#include <val/LessThanOrEqualTo.h>
#include <val/MoreThanOrEqualTo.h>
#include <val/Range.h>
#include <val/Email.h>
#include <val/Phone.h>
#include <val/Length.h>

#include <QDebug>
#include <QMetaObject>

using namespace val;

TestEssenceA::TestEssenceA()
{
//    setMethod(&TestEssenceA::testInvoke);
}

NodeDef TestEssenceA::nodeDef() const
{
    NodeDef nd;

    nd.setChildRequirement(ItemReq("TestEssenceB"), "left");
    nd.setChildRequirement(ItemReq("TestEssenceA"), "right");
    nd.setChildRequirement(ItemReq(), "middle");
    nd.setChildRequirement(ItemReq("TestEssenceB"), "top");

//    ItemReq defReq;
//    defReq.setCanBeEssenceless(false);
//    nd.setChildRequirement(defReq);

    nd.setIsLimitedPropertyList(true);

    {
        PropertyDef propDefValue;
        ValidatorPtr ltoet = ValidatorPtr(new val::Range<int>(13, 1337 * 2));
        propDefValue.addValidator(ltoet);
        propDefValue.setName("value");
        nd.insertPropertyDef(propDefValue);
    }

    {
        PropertyDef propDefValue;
        propDefValue.addValidator(ValidatorPtr(new val::Email()));
        propDefValue.addValidator(ValidatorPtr(new val::Length(12, 32)));
        propDefValue.setName("email");
        nd.insertPropertyDef(propDefValue);
    }

    {
        PropertyDef propDefValue;
        propDefValue.addValidator(ValidatorPtr(new val::Phone()));
        propDefValue.setName("phone");
        nd.insertPropertyDef(propDefValue);
    }

    return nd;
}

void TestEssenceA::testInvoke(hierhin::Item *item)
{
    QMetaObject::invokeMethod(this, "setElite", Qt::DirectConnection, Q_ARG(hierhin::Item*, item));
}

QMap<QString, MethodDef> TestEssenceA::commandDefs() const
{
    auto mp = Essence::commandDefs();
    ArgDef multArgDef;
    multArgDef.setDefaultValue(10);
//    multArgDef.setName("rightArg");
    MethodDef multCommandDef("multValue", {multArgDef});
    MethodDef sumCommandDef("sumValue", 2);

    mp.insert("doubleValue", MethodDef("doubleValue"));
    mp.insert("multValue", multCommandDef);
    mp.insert("sumValue", sumCommandDef);
    mp.insert("invoke", MethodDef("invoke"));

    return mp;
}

void TestEssenceA::setElite(hierhin::Item *item)
{
    item->setProperty("value", 1337);
}
