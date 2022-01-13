#include "GetChildByRole.h"

#include "Node.h"
#include "nav/ItemRef.h"

namespace hierhin {
namespace sys {

GetChildByRole::GetChildByRole()
{

}

menu::def::ActionDef GetChildByRole::actionDef() const
{
    menu::def::ActionDef aDef;
    menu::def::ArgDef argDef;

    argDef.setTypeId(QMetaType::QString); //TODO: or Role user type?

    aDef.setArgMinNum(1);
    aDef.setArgMaxNum(1);
    aDef.addArgDef(argDef);
    //TODO: aDef.set...
    return aDef;
}

QVariant GetChildByRole::actImpl(const QVariantList &args, Item *item)
{
    Node *node = dynamic_cast<Node *>(item);

    if (!node) {
        return QVariant(); //TODO: or exception?
    }

    Role role = args.at(0).toString();
    auto child = node->childByRole(role);

    if (child) {
        nav::ItemRef itemRef(child->absPath());
        return QVariant::fromValue(itemRef);
    }

    return QVariant(); //TODO: or exception?
}

} // namespace sys
} // namespace hierhin
