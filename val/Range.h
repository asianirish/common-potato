#ifndef VAL_RANGE_H
#define VAL_RANGE_H

#include "Validator.h"

namespace val {

template <typename T>
class Range : public Validator
{
public:
    Range();

    Range(T minValue, T maxValue);

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant minValue() const;
    void setMinValue(const QVariant &minValue);

    QVariant maxValue() const;
    void setMaxValue(const QVariant &maxValue);

private:
    QVariant _minValue;
    QVariant _maxValue;
};

template <typename T>
Range<T>::Range()
{

}

template <typename T>
Range<T>::Range(T minValue, T maxValue) : _minValue(minValue),
    _maxValue(maxValue)
{

}

template <typename T>
bool Range<T>::validate(const QVariant &value) const
{
    return (value.value<T>() >= _minValue.value<T>() &&
            value.value<T>() <= _maxValue.value<T>());
}

template <typename T>
QString Range<T>::errorMessage() const
{
    return QString("should be within a range of %1 and %2").arg(_minValue.toString(), _maxValue.toString());
}

template <typename T>
QVariant Range<T>::minValue() const
{
    return _minValue;
}

template <typename T>
void Range<T>::setMinValue(const QVariant &minValue)
{
    _minValue = minValue;
}

template <typename T>
QVariant Range<T>::maxValue() const
{
    return _maxValue;
}

template <typename T>
void Range<T>::setMaxValue(const QVariant &maxValue)
{
    _maxValue = maxValue;
}

} // namespace val

#endif // VAL_RANGE_H
