#include "Node.h"
#include "ex/EmptyClassNameList.h"
#include "ex/NoSuchLinkOwner.h"
#include "ex/NotKindOf.h"

#include <LinkableEssence.h>

namespace hierhin {

const QString Node::LINK_BACK_REF_SIGN("@");

QString Node::backRef(const QString &ref)
{
    return LINK_BACK_REF_SIGN + ref;
}

Node::Node()
{

}

ItemPtr Node::child(const Id &id)
{
    const Node *cnode = dynamic_cast<const Node*>(this);
    return cnode->child(id).constCast<Item>();
}

QList<ItemPtr> Node::children()
{
    const Node *cnode = dynamic_cast<const Node*>(this);
    return cnode->children();
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
    item->setParentNode(sharedFromThis().template dynamicCast<Node>().toWeakRef());
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

ItemPtr Node::setLink(nav::ItemRef &targetRef, bool isBidirectional, const Role &linkRole, const QString &linkClass, const Role &ownerRole)
{
    if (!isKindOf(ESSENCE_CLASS(hierhin::LinkableEssence))) {
        throw ex::NotKindOf(ESSENCE_CLASS(hierhin::LinkableEssence));
    }

    auto linkOwner = childByRole(ownerRole).dynamicCast<Node>();

    if (!linkOwner) {
        throw ex::NoSuchLinkOwner(ownerRole);
    }

    auto link = createImpl(linkClass);

    nav::ItemRef sourceRef(absPath());
    auto sourceVar = QVariant::fromValue(sourceRef);
    auto targetVar = QVariant::fromValue(targetRef);
    link->setProperty(Const::SOURCE_PROP, sourceVar);
    link->setProperty(Const::TARGET_PROP, targetVar);
    link->setProperty(Const::BIDIR_PROP, isBidirectional);

    if (isBidirectional) {
        QSharedPointer<Item> thisPtr = sharedFromThis();
        ItemPtr targetPtr = targetRef.ptr(thisPtr);
        targetPtr->addValue(backRef(ownerRole), QVariant::fromValue(nav::ItemRef(link/*->absPath()*/)));
    }

    linkOwner->addChild(link, linkRole);

    return link;
}

ItemPtr Node::setLink(ItemPtr target, bool isBidirectional, const Role &linkRole, const QString &linkClass, const Role &ownerRole)
{
    if (!isKindOf(ESSENCE_CLASS(hierhin::LinkableEssence))) {
        throw ex::NotKindOf(ESSENCE_CLASS(hierhin::LinkableEssence));
    }

    auto linkOwner = childByRole(ownerRole).dynamicCast<Node>();

    if (!linkOwner) {
        throw ex::NoSuchLinkOwner(ownerRole);
    }

    auto link = createImpl(linkClass);

    link->setProperty(Const::SOURCE_PROP, sharedFromThis());
    link->setProperty(Const::TARGET_PROP, target);
    link->setProperty(Const::BIDIR_PROP, isBidirectional);

    if (isBidirectional) {
        QSharedPointer<Item> thisPtr = sharedFromThis();
        target->addValue(backRef(ownerRole), QVariant::fromValue(nav::ItemRef(link/*->absPath()*/)));
    }

    linkOwner->addChild(link, linkRole);

    return link;
}

QList<nav::ItemRef> Node::targets(const Role &linkOwnerRole)
{
    QList<nav::ItemRef> refLst;

    if (!isKindOf(ESSENCE_CLASS(hierhin::LinkableEssence))) {
        throw ex::NotKindOf(ESSENCE_CLASS(hierhin::LinkableEssence));
    }

    auto linkOwner = childByRole(linkOwnerRole).dynamicCast<Node>();

    if (!linkOwner) {
        throw ex::NoSuchLinkOwner(linkOwnerRole);
    }

    auto idLst = linkOwner->idList();

    for (auto &id : idLst) {
        auto chItem = linkOwner->child(id);
        auto ch = chItem.dynamicCast<Node>();

        QVariant targetVar = ch->property(Const::TARGET_PROP);
        auto targetRef = targetVar.value<nav::ItemRef>();
        refLst.append(targetRef);
    }

    return refLst;
}

QList<ItemPtr> Node::links(const Role &ownerRole)
{

    if (!isKindOf(ESSENCE_CLASS(hierhin::LinkableEssence))) {
        throw ex::NotKindOf(ESSENCE_CLASS(hierhin::LinkableEssence));
    }

    auto owner = this->linkOwner(ownerRole);
    return owner->children();
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
                throw ex::EmptyClassNameList(role);
            }
            //only one class available for the mandatory one
           return classNames.at(0);
        }
    }

    return QString();
}


NodePtr Node::linkOwner(const Role &ownerRole)
{
    auto owner = this->childByRole(ownerRole).dynamicCast<hierhin::Node>();
    return owner;
}

} // namespace hierhin
