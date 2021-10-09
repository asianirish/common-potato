#include "Range.h"

namespace hi {
namespace val {

Range::Range()
{

}

Range::Range(int minValue, int maxValue) : _minValue(minValue),
    _maxValue(maxValue)
{

}

Range::Range(double minValue, double maxValue) : _minValue(minValue),
    _maxValue(maxValue)
{

}

bool Range::validate(const QVariant &value) const
{
    return (value >= _minValue && value <= _maxValue);
}

QString Range::errorMessage() const
{
    return QString("should be within a range of %1 and %2").arg(_minValue.toString(), _maxValue.toString());
}

QVariant Range::minValue() const
{
    return _minValue;
}

void Range::setMinValue(const QVariant &minValue)
{
    _minValue = minValue;
}

QVariant Range::maxValue() const
{
    return _maxValue;
}

void Range::setMaxValue(const QVariant &maxValue)
{
    _maxValue = maxValue;
}

} // namespace val
} // namespace hi
