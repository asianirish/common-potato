#ifndef VAL_MORETHANOREQUALTO_H
#define VAL_MORETHANOREQUALTO_H

#include "Validator.h"

namespace val {

template <typename T>
class MoreThanOrEqualTo : public Validator
{
public:
    MoreThanOrEqualTo();

    MoreThanOrEqualTo(int value);

    MoreThanOrEqualTo(double value);

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant value() const;
    void setValue(const QVariant &value);

private:
    QVariant _value;
};

template <typename T>
MoreThanOrEqualTo<T>::MoreThanOrEqualTo()
{

}

template <typename T>
MoreThanOrEqualTo<T>::MoreThanOrEqualTo(int value) : _value(value)
{

}

template <typename T>
MoreThanOrEqualTo<T>::MoreThanOrEqualTo(double value) : _value(value)
{

}

template <typename T>
bool MoreThanOrEqualTo<T>::validate(const QVariant &value) const
{
    return (value.value<T>() >= _value.value<T>());
}

template <typename T>
QString MoreThanOrEqualTo<T>::errorMessage() const
{
    return QString("should more than or equal to %1").arg(_value.toString());
}

template <typename T>
QVariant MoreThanOrEqualTo<T>::value() const
{
    return _value;
}

template <typename T>
void MoreThanOrEqualTo<T>::setValue(const QVariant &value)
{
    _value = value;
}

} // namespace val

#endif // VAL_MORETHANOREQUALTO_H
