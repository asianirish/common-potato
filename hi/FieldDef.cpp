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

QList<ValidatorPtr> FieldDef::validators() const
{
    return _validators;
}

void FieldDef::setValidators(const QList<ValidatorPtr> &validators)
{
    _validators = validators;
}

void FieldDef::addValidator(const ValidatorPtr &vptr)
{
    _validators.append(vptr);
}

} // namespace hi
