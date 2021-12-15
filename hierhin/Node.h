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

protected:
    virtual void nodeImplToMap(QVariantMap &mp) const = 0;
    virtual void nodeImplFromMap(const QVariantMap &mp) = 0;

    virtual void addChildImpl(ItemPtr item, const Role &role) = 0;

private:
    void nodeToMap(QVariantMap &mp) const final;
    void nodeFromMap(const QVariantMap &mp) final;

};

} // namespace hierhin

#endif // HIERHIN_NODE_H
