#include "LessThan.h"

namespace hi {
namespace val {

LessThan::LessThan()
{

}

LessThan::LessThan(int value) : _value(value)
{

}

bool LessThan::validate(const QVariant &value) const
{
    return (value < _value);
}

QString LessThan::errorMessage() const
{
    return QString("should less than %1").arg(_value.toString());
}

QVariant LessThan::value() const
{
    return _value;
}

void LessThan::setValue(const QVariant &value)
{
    _value = value;
}

} // namespace val
} // namespace hi
