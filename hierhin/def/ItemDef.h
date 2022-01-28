#ifndef HIERHIN_DEF_ITEMDEF_H
#define HIERHIN_DEF_ITEMDEF_H

#include "PropertyDef.h"
#include "MethodDef.h"
#include "../type.h"

#include <QString>
#include <QMap>

namespace hierhin {
namespace def {

class ItemDef
{
public:
    ItemDef();

    bool isLimitedPropertyList() const;
    void setIsLimitedPropertyList(bool isLimitedPropertyList);

    QMap<QString, PropertyDef> propertyDefs() const;
    PropertyDef propertyDef(const QString &name) const;
    void setPropertyDefs(const QMap<QString, PropertyDef> &propertyDefs);
    void insertPropertyDef(const PropertyDef &propertyDef);

    //'false' means 'no limitations'
    operator bool() const;

    void validateProperty(const QString &name, const QVariant &value);

    const QStringList &methodNames() const;
    void setMethodNames(const QStringList &newMethodNames);
    void insertMethodName(const QString &methodName);

    virtual BaseType requiredBaseType() const;

private:
    bool _isLimitedPropertyList; // limited to the specified set of definitions
    QMap<QString, PropertyDef> _propertyDefs;
    QStringList _methodNames;

    virtual bool toBool() const;
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_ITEMDEF_H
