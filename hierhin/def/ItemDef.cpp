#include "ItemDef.h"

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

PropertyDefs ItemDef::propertyDefs() const
{
    return _propertyDefs;
}

void ItemDef::setPropertyDefs(const PropertyDefs &propertyDefs)
{
    _propertyDefs = propertyDefs;
}

void ItemDef::insertPropertyDef(const QString &name, const PropertyDefList &propertyDef)
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
