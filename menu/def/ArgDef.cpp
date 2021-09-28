#include "ArgDef.h"

namespace menu {
namespace def {

ArgDef::ArgDef()
{

}

QVariant ArgDef::defaultValue() const
{
    return _defaultValue;
}

void ArgDef::setDefaultValue(const QVariant &defaultValue)
{
    _defaultValue = defaultValue;
}

} // namespace def
} // namespace menu
