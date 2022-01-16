#ifndef HIERHIN_TYPE_H
#define HIERHIN_TYPE_H

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
    NODE
};

} // namespace hierhin

#endif // HIERHIN_TYPE_H
