#include "TestEssenceMulty.h"

#include <hierhin/Item.h>
#include <hierhin/type.h>

#include <val/Each.h>
#include <val/LessThanOrEqualTo.h>
#include <val/MoreThanOrEqualTo.h>
#include <val/Range.h>
#include <val/Length.h>
#include <val/TypeValidator.h>


#include <QDebug>
#include <QMetaObject>

using namespace val;
using namespace hierhin;

TestEssenceMulty::TestEssenceMulty()
{

}

void TestEssenceMulty::nodeDef(NodeDef &nd) const
{
    nd.setIsLimitedPropertyList(true);
}

QMap<QString, PropertyDef> TestEssenceMulty::propertyDefs() const
{
    QMap<QString, PropertyDef> propDefs = Essence::propertyDefs();

    {
        PropertyDef propDef;

        ValidatorPtr rangeVal = ValidatorPtr(new val::Range<int>(1, 13));
        ValidatorPtr each = ValidatorPtr(new val::Each());
        each.dynamicCast<val::Each>()->addValidator(rangeVal);

        propDef.addValidator(each);
        propDef.setName("numbers");
        propDef.setTypeId(QMetaType::QVariantList);
        propDefs.insert("numbers", propDef);
    }

    {
        PropertyDef propDef;

        ValidatorPtr typeVal = ValidatorPtr(new val::TypeValidator(QMetaType::User, nav::ItemRef::typeId()));
        ValidatorPtr each = ValidatorPtr(new val::Each());
        each.dynamicCast<val::Each>()->addValidator(typeVal);

        propDef.addValidator(each);
        propDef.setName("refs");
        propDef.setTypeId(QMetaType::QVariantList);
        propDefs.insert("refs", propDef);
    }


    return propDefs;
}

QMap<Role, ItemReq> TestEssenceMulty::nonLinkChildRequirements() const
{
    QMap<hierhin::Role, ItemReq> chReq;

    chReq.insert(hierhin::Role(), ItemReq("TestEssenceMulty"));

    return chReq;
}
