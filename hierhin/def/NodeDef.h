#ifndef HIERHIN_DEF_NODEDEF_H
#define HIERHIN_DEF_NODEDEF_H

#include "ItemDef.h"

namespace hierhin {

typedef QString Role;

class Item;
typedef QSharedPointer<Item> ItemPtr;

namespace def {

class NodeDef : public ItemDef
{
public:
    NodeDef();

    const QMap<Role, QString> &childEssenceClassNames() const;
    QString childEssenceClassName(const Role &role = Role()) const;
    void setChildEssenceClassNames(const QMap<Role, QString> &newChildEssenceClassNames);
    void setChildEssenceClassName(const QString &className, const Role &role = "");

    QList<Role> roles() const;

    void validateChild(ItemPtr item, const Role &role) const;

private:
    //maps roles onto class names
    QMap<Role, QString> _childEssenceClassNames;
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_NODEDEF_H
