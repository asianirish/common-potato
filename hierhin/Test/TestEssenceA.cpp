#include "TestEssenceA.h"

#include <hierhin/Item.h>
#include <val/LessThanOrEqualTo.h>
#include <val/MoreThanOrEqualTo.h>
#include <val/Range.h>
#include <val/Email.h>
#include <val/Phone.h>
#include <val/Length.h>

#include <QDebug>

using namespace val;

TestEssenceA::TestEssenceA()
{

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

void TestEssenceA::executeImpl(hierhin::Item *item, const QString &command, const QVariantList &args) const
{
    Q_UNUSED(command)
    Q_UNUSED(args)

    if (command == "doubleValue") {
        int value = item->property("value").toInt();
        item->setProperty("value", value * 2);
    } else if (command == "multValue") {
        int value = item->property("value").toInt();
        int arg = args.at(0).toInt();
        item->setProperty("value", value * arg);
    }
}

QMap<QString, CommandDef> TestEssenceA::commandDefs() const
{
    auto mp = Essence::commandDefs();
    ArgDef multArgDef;
    multArgDef.setDefaultValue(10);
//    multArgDef.setName("rightArg");
    CommandDef multCommandDef("multValue", {multArgDef});

    mp.insert("doubleValue", CommandDef("doubleValue"));
    mp.insert("multValue", multCommandDef);
    return mp;
}
