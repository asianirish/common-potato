#include "ItemDef.h"

#include "ex/NoSuchProperty.h"
#include "ex/EmptyPropertyName.h"

namespace hierhin {
namespace def {

ItemDef::ItemDef() : _isLimitedPropertyList(false)
{

}

bool ItemDef::isLimitedPropertyList() const
{
    return _isLimitedPropertyList;
}

void ItemDef::setIsLimitedPropertyList(bool isLimitedPropertyList)
{
    _isLimitedPropertyList = isLimitedPropertyList;
}

QMap<QString, PropertyDef> ItemDef::propertyDefs() const
{
    return _propertyDefs;
}

PropertyDef ItemDef::propertyDef(const QString &name) const
{
    return _propertyDefs.value(name);
}

void ItemDef::setPropertyDefs(const QMap<QString, PropertyDef> &propertyDefs)
{
    _propertyDefs = propertyDefs;
}

void ItemDef::insertPropertyDef(const PropertyDef &propertyDef)
{
    if (propertyDef.name().isEmpty()) {
        throw ex::EmptyPropertyName();
    }
    _propertyDefs.insert(propertyDef.name(), propertyDef);
}

ItemDef::operator bool() const
{
    return toBool();
}

void ItemDef::validateProperty(const QString &name, const QVariant &value)
{
    if (_isLimitedPropertyList) {
        if (!_propertyDefs.contains(name)) {
            throw ex::NoSuchProperty(name);
        }
    }

    auto propDef = _propertyDefs.value(name);
    propDef.setName(name);
    propDef.validate(value);
}

const QStringList &ItemDef::methodNames() const
{
    return _methodNames;
}

void ItemDef::setMethodNames(const QStringList &newMethodNames)
{
    _methodNames = newMethodNames;
}

void ItemDef::insertMethodName(const QString &methodName)
{
    _methodNames.append(methodName);
}

BaseType ItemDef::requiredBaseType() const
{
    return BaseType::ITEM;
}

bool ItemDef::toBool() const
{
    if (!_isLimitedPropertyList) {
        return false;
    }

    return !_propertyDefs.isEmpty();
}

} // namespace def
} // namespace hierhin
