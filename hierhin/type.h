#ifndef TYPE_H
#define TYPE_H

#include <QSharedPointer>
#include <QList>

namespace hierhin {

class Essence;

typedef QSharedPointer<Essence> EssencePtr;

class Item;

typedef QSharedPointer<Item> ItemPtr;
typedef QSharedPointer<const Item> ConstItemPtr;

typedef QString Role;

typedef QWeakPointer<Item> ItemWeakPtr;

class Node;
typedef QSharedPointer<Node> NodePtr;
typedef QWeakPointer<Node> NodeWeakPtr;
typedef QSharedPointer<const Node> ConstNodePtr;

typedef QString Id;

typedef QList<Id> IdList;
typedef QList<QString> NameList;

enum class BaseType {
    ITEM,
    NODE,
    LINK
};

} // namespace hierhin

#endif // TYPE_H
