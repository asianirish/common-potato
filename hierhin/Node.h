#ifndef HIERHIN_NODE_H
#define HIERHIN_NODE_H

#include <Item.h>

namespace hierhin {

typedef QList<Id> IdList;
typedef QList<QString> NameList;

class Node : public virtual Item
{
public:
    Node();

//    virtual ItemPtr child(const QString &id) const = 0;

//    virtual void addChild(ItemPtr item) = 0;

//    virtual ItemPtr namedChild(const QString &name) = 0;

//    virtual void addNamedChild(const QString &id) = 0;

//    virtual IdList idList() const = 0;
//    virtual NameList nameList() const = 0;

//protected:
//    virtual void toMapNodeImplSpecific(QVariantMap &mp) const = 0;

private:
    void toMapNodeSpecific(QVariantMap &mp) const final;

};

} // namespace hierhin

#endif // HIERHIN_NODE_H
