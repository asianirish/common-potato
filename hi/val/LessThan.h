#ifndef HI_VAL_LESSTHAN_H
#define HI_VAL_LESSTHAN_H

#include "Validator.h"

namespace hi {
namespace val {

template <typename T>
class LessThan : public Validator
{
public:
    LessThan();

    LessThan(T value);

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant value() const;
    void setValue(const QVariant &value);

private:
    QVariant _value;
};

template <typename T>
LessThan<T>::LessThan()
{

}

template <typename T>
LessThan<T>::LessThan(T value) : _value(value)
{

}

template <typename T>
bool LessThan<T>::validate(const QVariant &value) const
{
    return (value.value<T>() < _value.value<T>());
}

template <typename T>
QString LessThan<T>::errorMessage() const
{
    return QString("should less than %1").arg(_value.toString());
}

template <typename T>
QVariant LessThan<T>::value() const
{
    return _value;
}

template <typename T>
void LessThan<T>::setValue(const QVariant &value)
{
    _value = value;
}

} // namespace val
} // namespace hi

#endif // HI_VAL_LESSTHAN_H
