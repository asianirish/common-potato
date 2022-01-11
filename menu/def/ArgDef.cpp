#include "ArgDef.h"

namespace menu {
namespace def {

ArgDef::ArgDef() : _typeId(QMetaType::UnknownType)
{

}

QVariant ArgDef::defaultValue() const
{
    return _defaultValue;
}

void ArgDef::setDefaultValue(const QVariant &defaultValue)
{
    _defaultValue = defaultValue;
    _typeId = _defaultValue.userType();
}

bool ArgDef::isDefaultValue() const
{
    return _defaultValue.isValid();
}

void ArgDef::addConstraint(QSharedPointer<Constraint> constraint)
{
    _constraints.append(constraint);
}

Error ArgDef::validate(const QVariant &arg) const
{
    for (auto &cn : _constraints) {
        Error err = cn->validate(arg);
        if (err) {
            return err;
        }
    }

    return Error();
}

QString ArgDef::name() const
{
    return _name;
}

void ArgDef::setName(const QString &name)
{
    _name = name;
}

QString ArgDef::description() const
{
    return _description;
}

void ArgDef::setDescription(const QString &description)
{
    _description = description;
}

int ArgDef::typeId() const
{
    return _typeId;
}

void ArgDef::setTypeId(int newTypeId)
{
    _typeId = newTypeId;
}

} // namespace def
} // namespace menu
