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

void ItemDef::insertPropertyDef(const PropertyDef &propertyDef)
{
    if (propertyDef.name().isEmpty()) {
        throw "EmptyPropertyException"; //TODO: Exception class
    }
    _propertyDefs.insert(propertyDef.name(), propertyDef);
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
    propDef.setName(name);
    propDef.validate(value);
}

const QMap<QString, MethodDef> &ItemDef::commandDefs() const
{
    return _commandDefs;
}

void ItemDef::setCommandDefs(const QMap<QString, MethodDef> &newCommandDefs)
{
    _commandDefs = newCommandDefs;
}

void ItemDef::insertCommandDef(const MethodDef &commandDef)
{
    if (commandDef.name().isEmpty()) {
        throw "EmptyCommandException"; //TODO: Exception class
    }

    _commandDefs.insert(commandDef.name(), commandDef);
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
