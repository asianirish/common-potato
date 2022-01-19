#include "TestEssenceMulty.h"

TestEssenceMulty::TestEssenceMulty()
{

}

void TestEssenceMulty::nodeDef(NodeDef &nd) const
{
    nd.setIsLimitedPropertyList(true);
}

QMap<QString, PropertyDef> TestEssenceMulty::propertyDefs() const
{
    QMap<QString, PropertyDef> mp;

    //TODO: implement


    return mp;
}

QMap<Role, ItemReq> TestEssenceMulty::nonLinkChildRequirements() const
{
    QMap<hierhin::Role, ItemReq> chReq;

    chReq.insert(hierhin::Role(), ItemReq("TestEssenceMulty"));

    return chReq;
}
