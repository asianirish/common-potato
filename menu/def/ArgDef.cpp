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

bool ArgDef::isDefaultValue() const
{
    return _defaultValue.isValid();
}

void ArgDef::addConstraint(QSharedPointer<Constraint> constraint)
{
    _constraints.append(constraint);
}

} // namespace def
} // namespace menu
