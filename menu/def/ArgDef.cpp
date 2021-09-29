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

} // namespace def
} // namespace menu
