#ifndef HIERHIN_DEF_NODEDEF_H
#define HIERHIN_DEF_NODEDEF_H

#include "ItemDef.h"

namespace hierhin {

typedef QString Role;

namespace def {

class NodeDef : public ItemDef
{
public:
    NodeDef();

    const QMap<Role, QString> &childEssenceClassNames() const;
    void setChildEssenceClassNames(const QMap<Role, QString> &newChildEssenceClassNames);
    void setChildEssenceClassName(const QString &className, const Role &role = "");

    const QList<Role> &roles() const;
    void setRoles(const QList<Role> &newRoles);
    void addRole(const Role &role);

    void validateChildRole(const Role &role);

private:
    //maps roles onto class names
    QMap<Role, QString> _childEssenceClassNames;
    QList<Role> _roles;
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_NODEDEF_H
