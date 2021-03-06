#include "PropertyDef.h"
#include "ex/ValidatorException.h"
#include "ex/IncompatibleValueType.h"

namespace hierhin {
namespace def {

PropertyDef::PropertyDef() : _typeId(QMetaType::UnknownType)
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
    _typeId = _defaultValue.userType();
}

void PropertyDef::validate(const QVariant &value)
{
    if (_typeId != QMetaType::UnknownType) {
        if (!value.canConvert(_typeId)) {
            throw ex::IncompatibleValueType(_typeId);
        }
    }

    for (auto &validator : _validators) {
        if (!validator->validate(value)) {
            throw ex::ValidatorException(_name, validator->errorMessage());
        }
    }
}

const QString &PropertyDef::name() const
{
    return _name;
}

void PropertyDef::setName(const QString &newName)
{
    _name = newName;
}

int PropertyDef::typeId() const
{
    return _typeId;
}

void PropertyDef::setTypeId(int newTypeId)
{
    _typeId = newTypeId;
}

bool PropertyDef::isListType() const
{
    if (QMetaType::QVariantList == _typeId) {
        return true;
    }

    //TODO: other list types

    return false;
}

} // namespace def
} // namespace hierhin
