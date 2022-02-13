#include "SetLink.h"
#include "nav/ItemRef.h"

#include <hierhin/LinkEssence.h>
#include <hierhin/Const.h>
#include <hierhin/Node.h>

namespace hierhin {
namespace sys {

SetLink::SetLink()
{

}

menu::def::ActionDef SetLink::actionDef() const
{
    menu::def::ActionDef aDef;

    menu::def::ArgDef targetDef;
    menu::def::ArgDef isBidirDef;
    menu::def::ArgDef linkRoleDef;
    menu::def::ArgDef linkClassDef;
    menu::def::ArgDef ownerRoleDef;

    //0
    targetDef.setTypeId(qMetaTypeId<hierhin::nav::ItemRef>());

    //1
    isBidirDef.setTypeId(qMetaTypeId<bool>());
    isBidirDef.setDefaultValue(false);

    //2
    linkRoleDef.setTypeId(qMetaTypeId<hierhin::Role>());
    linkRoleDef.setDefaultValue(Role());

    //3
    linkClassDef.setTypeId(qMetaTypeId<QString>());
    linkClassDef.setDefaultValue(ESSENCE_CLASS(hierhin::LinkEssence));

    //4
    ownerRoleDef.setTypeId(qMetaTypeId<hierhin::Role>());
    ownerRoleDef.setDefaultValue(LinkableEssence::DEFAULT_LINK_OWNER_ROLE);

    aDef.setArgMinNum(1);

    aDef.addArgDef(targetDef);
    aDef.addArgDef(isBidirDef);
    aDef.addArgDef(linkRoleDef);
    aDef.addArgDef(linkClassDef);
    aDef.addArgDef(ownerRoleDef);

    return aDef;
}

QVariant SetLink::actNodeImpl(const QVariantList &args, Node *node)
{
    hierhin::nav::ItemRef ref = args.at(0).value<hierhin::nav::ItemRef>();
    bool isDir = args.at(1).toBool();
    hierhin::Role linkRole = args.at(2).value<hierhin::Role>();
    QString linkClass = args.at(3).toString();
    hierhin::Role linkOwnerRole = args.at(4).value<hierhin::Role>();

    node->setLink(ref, isDir, linkRole, linkClass, linkOwnerRole);

    return true; //TODO: what to return?
}

} // namespace sys
} // namespace hierhin
