#include "PropertyDef.h"

namespace hierhin {
namespace def {

PropertyDef::PropertyDef()
{

}

QList<ValidatorPtr> PropertyDef::validators() const
{
    return _validators;
}

void PropertyDef::setValidators(const QList<ValidatorPtr> &validators)
{
    _validators = validators;
}

void PropertyDef::addValidator(const ValidatorPtr &vptr)
{
    _validators.append(vptr);
}

QVariant PropertyDef::defaultValue() const
{
    return _defaultValue;
}

void PropertyDef::setDefaultValue(const QVariant &defaultValue)
{
    _defaultValue = defaultValue;
}

} // namespace def
} // namespace hierhin
