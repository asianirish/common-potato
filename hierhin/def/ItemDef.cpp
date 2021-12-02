#include "ItemDef.h"

namespace hierhin {
namespace def {

ItemDef::ItemDef() : _isLimitedPropertyList(false)
{

}

QString ItemDef::essenceClass() const
{
    return _essenceClass;
}

void ItemDef::setEssenceClass(const QString &essenceClass)
{
    _essenceClass = essenceClass;
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

bool ItemDef::toBool() const
{
    if (!_isLimitedPropertyList) {
        return false;
    }

    return !_propertyDefs.isEmpty();
}

} // namespace def
} // namespace hierhin
