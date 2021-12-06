#ifndef HIERHIN_NODE_H
#define HIERHIN_NODE_H

#include <Item.h>

namespace hierhin {

typedef QList<Id> IdList;
typedef QList<QString> NameList;

typedef QString Role;

class Node : public virtual Item
{
public:
    Node();

    virtual bool containsId(const Id &id) = 0;

    virtual ItemPtr child(const Id &id) const = 0;

    void addChild(ItemPtr item);

    virtual IdList idList() const = 0;

//    virtual ItemPtr namedChild(const QString &name) = 0;

//    virtual void addNamedChild(const QString &id) = 0;

//    virtual NameList nameList() const = 0;

    bool isNode() const {
        return true;
    }

protected:
    virtual void nodeImplToMap(QVariantMap &mp) const = 0;

    virtual void addChildImpl(ItemPtr item) = 0;

private:
    void nodeToMap(QVariantMap &mp) const final;

};

} // namespace hierhin

#endif // HIERHIN_NODE_H
