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

void TestEssenceA::testInvoke(hierhin::Item *item)
{
    QMetaObject::invokeMethod(this, "setElite", Qt::DirectConnection, Q_ARG(hierhin::Item*, item));
}

void TestEssenceA::nodeDef(NodeDef &nd) const
{
//    ItemReq defReq;
//    defReq.setCanBeEssenceless(false);
//    nd.setChildRequirement(defReq);

    nd.setIsLimitedPropertyList(true);
}

QMap<hierhin::Role, ItemReq> TestEssenceA::childRequirements() const
{
    QMap<hierhin::Role, ItemReq> chReq;
    chReq.insert("left", ItemReq("TestEssenceB"));
    chReq.insert("right", ItemReq("TestEssenceA"));
    chReq.insert("middle", ItemReq());
    chReq.insert("top", ItemReq("TestEssenceB"));

    return chReq;
}

QMap<QString, PropertyDef> TestEssenceA::propertyDefs() const
{
    QMap<QString, PropertyDef> propDefs = Essence::propertyDefs();

    {
        PropertyDef propDefValue;
        ValidatorPtr ltoet = ValidatorPtr(new val::Range<int>(13, 1337 * 2));
        propDefValue.addValidator(ltoet);
        propDefValue.setName("value");
        propDefs.insert("value", propDefValue);
    }

    {
        PropertyDef propDefValue;
        propDefValue.addValidator(ValidatorPtr(new val::Email()));
        propDefValue.addValidator(ValidatorPtr(new val::Length(12, 32)));
        propDefValue.setName("email");
        propDefs.insert("email", propDefValue);
    }

    {
        PropertyDef propDefValue;
        propDefValue.addValidator(ValidatorPtr(new val::Phone()));
        propDefValue.setName("phone");
        propDefs.insert("phone", propDefValue);
    }

    return propDefs;
}

QMap<QString, MethodDef> TestEssenceA::methodDefs() const
{
    auto mp = Essence::methodDefs();
    ArgDef argDef;
    argDef.setDefaultValue(10);
    MethodDef methodDef("PlusValue");
    methodDef.addArgDef(argDef);

//    MethodDef sumCommandDef("sumValue", 2);

    mp.insert(methodDef.name(), methodDef);


    return mp;
}

void TestEssenceA::setElite(hierhin::Item *item)
{
    item->setProperty("value", 1337);
}
