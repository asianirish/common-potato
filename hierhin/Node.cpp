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
    const Node *cnode = dynamic_cast<const Node*>(this);
    auto childItem = cnode->childByRole(role).constCast<Item>();

    if (!childItem) {
        QString mandatoryClassName = childMandatoryClassName(role);

        if (!mandatoryClassName.isEmpty()) {

            //create and add mandatory child
            auto newItem = createImpl(mandatoryClassName);
            addChild(newItem, role);
            return newItem;
        }
    }

    return childItem;
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

QString Node::childMandatoryClassName(const Role &role) const
{
    auto ess = essencePtr();

    if (ess) {
        auto nd = ess->nodeDef();

        auto req = nd.childRequirement(role);
        if (req.isMandatory()) {
            auto classNames = req.classNames();

            if (classNames.isEmpty()) {
                throw "empty class name list"; //TODO: Exception class
            }
            //only one class available for the mandatory one
           return classNames.at(0);
        }
    }

    return QString();
}

} // namespace hierhin
