#include "NotEqualTo.h"

namespace hi {
namespace val {

NotEqualTo::NotEqualTo()
{

}

bool NotEqualTo::validate(const QVariant &value) const
{
    if (value == this->value()) {
        return false;
    }

    return true;
}

QString NotEqualTo::errorMessage() const
{
    return QString("should not be equal to %1").arg(_value.toString());
}

QVariant NotEqualTo::value() const
{
    return _value;
}

void NotEqualTo::setValue(const QVariant &value)
{
    _value = value;
}

} // namespace val
} // namespace hi
