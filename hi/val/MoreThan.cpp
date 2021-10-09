#include "MoreThan.h"

namespace hi {
namespace val {

MoreThan::MoreThan()
{

}

MoreThan::MoreThan(int value) : _value(value)
{

}

MoreThan::MoreThan(double value) : _value(value)
{

}

bool MoreThan::validate(const QVariant &value) const
{
    return (value > _value);
}

QString MoreThan::errorMessage() const
{
    return QString("should more than %1").arg(_value.toString());
}

QVariant MoreThan::value() const
{
    return _value;
}

void MoreThan::setValue(const QVariant &value)
{
    _value = value;
}

} // namespace val
} // namespace hi