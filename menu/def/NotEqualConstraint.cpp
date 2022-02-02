#include "NotEqualConstraint.h"

namespace menu {
namespace def {

NotEqualConstraint::NotEqualConstraint()
{

}

QVariant NotEqualConstraint::value() const
{
    return _value;
}

void NotEqualConstraint::setValue(const QVariant &value)
{
    _value = value;
}

void NotEqualConstraint::validateSpecific(const QVariant &arg, Error &err) const
{
    if (arg == _value) {
        err.setCode(Error::NOT_EQUAL_CONSTRAINT);
        err.addContext("value", _value);
    }
}

} // namespace def
} // namespace menu
