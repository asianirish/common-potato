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

//ItemPtr Node::childByName(const QString &name)
//{
//    const Node *cnode = dynamic_cast<const Node*>(this);
//    return cnode->childByName(name).constCast<Item>();
//}

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

void Node::assignRole(const Role &role, const Id &id)
{
    ItemPtr chld = child(id);

    if (!chld) {
        throw "NO SUCH A CHILD"; //TODO: exception class
    }

    assignRoleImpl(role, chld);
}

void Node::setLink(nav::ItemRef &targetRef, bool isBidirectional, const Role &linkRole, const QString &linkClass, const Role &ownerRole)
{
    if (!isKindOf("hierhin::LinkableEssence")) {
        throw "not a hierhin::LinkableEssence class"; //TODO: exception class
    }

    auto linkOwner = childByRole(ownerRole).dynamicCast<Node>();

    if (!linkOwner) {
        throw "lack of a link owner"; //TODO: exception class
    }

    auto link = createImpl(linkClass);

    nav::ItemRef sourceRef(absPath());
    auto sourceVar = QVariant::fromValue(sourceRef);
    auto targetVar = QVariant::fromValue(targetRef);
    link->setProperty("source", sourceVar); //TODO: const
    link->setProperty("target", targetVar); //TODO: const
    link->setProperty("bidir", isBidirectional); //TODO: const

    if (isBidirectional) {
        QSharedPointer<Item> thisPtr = sharedFromThis();
        ItemPtr targetPtr = targetRef.ptr(thisPtr);
        targetPtr->addValue(Const::LINK_REF_SIGN + ownerRole, QVariant::fromValue(nav::ItemRef(link/*->absPath()*/)));
    }

    linkOwner->addChild(link, linkRole);
}

QList<nav::ItemRef> Node::targets(const Role &linkOwnerRole)
{
    QList<nav::ItemRef> refLst;

    if (!isKindOf("hierhin::LinkableEssence")) {
        throw "not a hierhin::LinkableEssence class"; //TODO: exception class
    }

    auto linkOwner = childByRole(linkOwnerRole).dynamicCast<Node>();

    if (!linkOwner) {
        throw "lack of a link owner"; //TODO: exception class
    }

    auto idLst = linkOwner->idList();

    for (auto &id : idLst) {
        auto chItem = linkOwner->child(id);
        auto ch = chItem.dynamicCast<Node>();

        QVariant targetVar = ch->property("target");
        auto targetRef = targetVar.value<nav::ItemRef>();
        refLst.append(targetRef);
    }

    return refLst;
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
