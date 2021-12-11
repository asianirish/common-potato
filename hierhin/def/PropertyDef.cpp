#include "PropertyDef.h"
#include "ex/ValidatorException.h"

namespace hierhin {
namespace def {

PropertyDef::PropertyDef()
{

}

QList<val::ValidatorPtr> PropertyDef::validators() const
{
    return _validators;
}

void PropertyDef::setValidators(const QList<val::ValidatorPtr> &validators)
{
    _validators = validators;
}

void PropertyDef::addValidator(const val::ValidatorPtr &vptr)
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

void PropertyDef::validate(const QString &name, const QVariant &value)
{
    for (auto &validator : _validators) {
        if (!validator->validate(value)) {
            throw ex::ValidatorException(name, validator->errorMessage());
        }
    }
}

} // namespace def
} // namespace hierhin
