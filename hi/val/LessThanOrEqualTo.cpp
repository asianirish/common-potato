#include "LessThanOrEqualTo.h"

namespace hi {
namespace val {

LessThanOrEqualTo::LessThanOrEqualTo()
{

}

bool LessThanOrEqualTo::validate(const QVariant &value) const
{
    return (value <= _value);
}

QString LessThanOrEqualTo::errorMessage() const
{
    return QString("should less than or equal to %1").arg(_value.toString());
}

QVariant LessThanOrEqualTo::value() const
{
    return _value;
}

void LessThanOrEqualTo::setValue(const QVariant &value)
{
    _value = value;
}

} // namespace val
} // namespace hi
