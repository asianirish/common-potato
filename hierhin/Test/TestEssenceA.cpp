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

void TestEssenceA::nodeDef(NodeDef &nd) const
{
//    ItemReq defReq;
//    defReq.setCanBeEssenceless(false);
//    nd.setChildRequirement(defReq);

    nd.setIsLimitedPropertyList(true);
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

QStringList TestEssenceA::methodNames() const
{
    QStringList lst = Essence::methodNames();
    lst.append("PlusValue");
    return lst;
}

QMap<Role, ItemReq> TestEssenceA::nonLinkChildRequirements() const
{
    QMap<hierhin::Role, ItemReq> chReq;
    chReq.insert("left", ItemReq("TestEssenceB"));
    chReq.insert("right", ItemReq("TestEssenceA"));
    chReq.insert("middle", ItemReq());
    chReq.insert("top", ItemReq("TestEssenceB"));

    return chReq;
}
