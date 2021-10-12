#include "FieldDef.h"
#include "Item.h"

namespace hi {

FieldDef::FieldDef() : FieldDef(QString())
{

}

//FieldDef::FieldDef(const FieldDef &fieldDef) :
//    _defaultValue(fieldDef._defaultValue),
//    _validators(fieldDef._validators),
//    _isInheritable(fieldDef._isInheritable),
//    _itemClassName(fieldDef._itemClassName)
//{

//}

FieldDef::FieldDef(const QString &itemClassName) : _isInheritable(true),
    _itemClassName(itemClassName)
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

bool FieldDef::isInheritable() const
{
    return _isInheritable;
}

void FieldDef::setIsInheritable(bool inheritable)
{
    _isInheritable = inheritable;
}

QString FieldDef::itemClassName() const
{
    return _itemClassName;
}

} // namespace hi
