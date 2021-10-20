#ifndef HI_CHILDGROUP_H
#define HI_CHILDGROUP_H

#include <QString>
#include <QMap>

namespace hi {

class Node;
class Item;

class ChildGroup
{
public:
    ChildGroup();

    ChildGroup(const Node *owner);

    const Node *owner() const;
    void setOwner(const Node *owner);

    bool containsChild(const QString &id) const;

    Item *child(const QString &id) const;

    void addChild(Item *child);

    QString childItemClass() const;
    void setChildItemClass(const QString &childItemClass);

private:
    const Node *_owner;
    QString _childItemClass; //allowable child item class name (including inherited classes)

    QMap<QString, Item *> children() const;
};

} // namespace hi

#endif // HI_CHILDGROUP_H
