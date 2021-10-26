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

} // namespace def
} // namespace hierhin
