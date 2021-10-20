#ifndef HI_NODE_H
#define HI_NODE_H

#include "Item.h"
#include "ItemRef.h"
#include "ChildGroup.h"

namespace hi {

typedef QSharedPointer<ChildGroup> ChildGroupPtr;

class Node : public Item
{
    Q_OBJECT
public:
    static const QString DEFAULT_CHILD_GROUP_NAME;

    explicit Node(QObject *parent = nullptr);

    Item *child(const QString &id, const QString &childGroup = DEFAULT_CHILD_GROUP_NAME) const;

    void addChild(Item *child, const QString &childGroup = DEFAULT_CHILD_GROUP_NAME);

    QMap<QString, ChildGroup> childGroups() const;

protected:
    ChildGroup defaultChildGroup() const;

    virtual QMap<QString, ChildGroup> createChildGroups() const;

private:
    [[deprecated]] QMap<QString, ItemRef> _children;
    mutable QMap<QString, ChildGroup> _childGroups;

    void nodeToMap(QVariantMap &mp) const final;

signals:

};

} // namespace hi

#endif // HI_NODE_H
