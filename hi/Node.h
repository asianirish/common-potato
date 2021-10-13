#ifndef HI_NODE_H
#define HI_NODE_H

#include "Item.h"

namespace hi {

class Node : public Item
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = nullptr);

    Item *child(const QString &id) const;

    void addChild(Item *item);

private:
    QMap<QString, Item *> _children;

    void nodeToMap(QVariantMap &mp) const final;

signals:

};

} // namespace hi

#endif // HI_NODE_H
