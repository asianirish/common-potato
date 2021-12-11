#ifndef TYPE_H
#define TYPE_H

#include <QSharedPointer>
#include <QList>

namespace hierhin {

class Essence;

typedef QSharedPointer<Essence> EssencePtr;

class Item;
typedef QWeakPointer<Item> ItemWeakPtr;

class Node;
typedef QSharedPointer<Node> NodePtr;

typedef QString Id;

} // namespace hierhin

#endif // TYPE_H
