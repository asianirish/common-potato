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

} // namespace def
} // namespace menu
