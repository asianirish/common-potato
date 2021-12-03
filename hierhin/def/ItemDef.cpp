#include "ItemDef.h"

#include "ex/NoSuchProperty.h"

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

void ItemDef::setPropertyDefs(const QMap<QString, PropertyDef> &propertyDefs)
{
    _propertyDefs = propertyDefs;
}

void ItemDef::insertPropertyDef(const QString &name, const PropertyDef &propertyDef)
{
    _propertyDefs.insert(name, propertyDef);
}

ItemDef::operator bool() const
{
    return toBool();
}

void ItemDef::validateProperty(const QString &name, const QVariant &value)
{
    if (!*this) {
        return; //nothing to validate
    }

    if (!_propertyDefs.contains(name)) {
        throw ex::NoSuchProperty(name);
    }

    auto propDef = _propertyDefs.value(name);
    propDef.validate(name, value);
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
