#include "FieldDef.h"

namespace hi {

FieldDef::FieldDef()
{

}

QVariant FieldDef::defaultValue() const
{
    return _defaultValue;
}

void FieldDef::setDefaultValue(const QVariant &defaultValue)
{
    _defaultValue = defaultValue;
}

} // namespace hi
