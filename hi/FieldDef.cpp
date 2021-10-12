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

FieldDef::FieldDef(const QString &itemClassName) : _itemClassName(itemClassName)
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

QString FieldDef::itemClassName() const
{
    return _itemClassName;
}

} // namespace hi
