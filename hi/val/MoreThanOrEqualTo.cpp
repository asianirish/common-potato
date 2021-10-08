#include "MoreThanOrEqualTo.h"

namespace hi {
namespace val {

MoreThanOrEqualTo::MoreThanOrEqualTo()
{

}

bool MoreThanOrEqualTo::validate(const QVariant &value) const
{
    return (value >= _value);
}

QString MoreThanOrEqualTo::errorMessage() const
{
    return QString("should more than or equal to %1").arg(_value.toString());
}

QVariant MoreThanOrEqualTo::value() const
{
    return _value;
}

void MoreThanOrEqualTo::setValue(const QVariant &value)
{
    _value = value;
}

} // namespace val
} // namespace hi
