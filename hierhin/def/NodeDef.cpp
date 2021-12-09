#include "NodeDef.h"
#include "ex/NoSuchRoleExceptin.h"
#include "ex/IncompatibleEssenceClass.h"
#include "../Item.h"

namespace hierhin {
namespace def {

NodeDef::NodeDef()
{

}

const QMap<Role, QString> &NodeDef::childEssenceClassNames() const
{
    return _childEssenceClassNames;
}

QString NodeDef::childEssenceClassName(const Role &role) const
{
    return _childEssenceClassNames.value(role);
}

void NodeDef::setChildEssenceClassNames(const QMap<Role, QString> &newChildEssenceClassNames)
{
    _childEssenceClassNames = newChildEssenceClassNames;
}

void NodeDef::setChildEssenceClassName(const QString &className, const Role &role)
{
    _childEssenceClassNames.insert(role, className);
}

QList<Role> NodeDef::roles() const
{
    return _childEssenceClassNames.keys();
}

void NodeDef::validateChild(ItemPtr item, const Role &role) const
{
    if (!role.isEmpty() && !roles().contains(role)) {
        ex::NoSuchRoleExceptin ex;
        ex.setRole(role);
        throw ex;
    }

    if (!item->isKindOf(childEssenceClassName(role))) {
        ex::IncompatibleEssenceClass ex;
        //TODO: ...
        throw ex;
    }
}

} // namespace def
} // namespace hierhin
