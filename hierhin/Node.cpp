#include "Node.h"

namespace hierhin {

Node::Node()
{

}

ItemPtr Node::child(const Id &id)
{
    const Node *cnode = dynamic_cast<const Node*>(this);
    return cnode->child(id).constCast<Item>();
}

ItemPtr Node::childByRole(const Role &role)
{
//    auto ess = essencePtr();

//    if (ess) {
//        ess->nodeDef()
//    }

    const Node *cnode = dynamic_cast<const Node*>(this);
    return cnode->childByRole(role).constCast<Item>();
}

void Node::addChild(ItemPtr item, const Role &role)
{
    definition().validateChild(item, role);

    addChildImpl(item, role);
}

QList<nav::ItemRef> Node::childRefs() const
{
    QList<nav::ItemRef> lst;
    IdList ids = idList();

    for (auto &id : ids) {
        auto item = child(id);
        nav::ItemRef ref(item->absPath());
        lst.append(ref);
    }

    return lst;
}

void Node::setLink(const QString &name, const nav::ItemRef &ref)
{
    if (isKindOf("hierhin::LinkedEssence")) {
        auto linkOwner = childByRole("links");

        if (!linkOwner) {
            //TODO: create LinkOwnerEssence subclass
        }
    }
}

void Node::nodeToMap(QVariantMap &mp) const
{
    //TODO: implement
    //TODO: write links and named items
    nodeImplToMap(mp);
}

void Node::nodeFromMap(const QVariantMap &mp)
{
    //TODO: read links
    nodeImplFromMap(mp);
}

} // namespace hierhin
