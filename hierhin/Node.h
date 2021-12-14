#ifndef HIERHIN_NODE_H
#define HIERHIN_NODE_H

#include <Item.h>

namespace hierhin {

class Node : public virtual Item
{
public:
    Node();

    virtual bool containsId(const Id &id) = 0;

    virtual ItemPtr child(const Id &id) const = 0;

    virtual ItemPtr childByRole(const Role &role) = 0;

    void addChild(ItemPtr item, const Role &role = Role());

    virtual IdList idList() const = 0;

//    virtual ItemPtr namedChild(const QString &name) = 0;

//    virtual void addNamedChild(const QString &id) = 0;

//    virtual NameList nameList() const = 0;

    BaseType baseType() const final;

protected:
    virtual void nodeImplToMap(QVariantMap &mp) const = 0;

    virtual void addChildImpl(ItemPtr item, const Role &role) = 0;

private:
    void nodeToMap(QVariantMap &mp) const final;

};

} // namespace hierhin

#endif // HIERHIN_NODE_H
