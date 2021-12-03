#ifndef VAL_LESSTHANOREQUALTO_H
#define VAL_LESSTHANOREQUALTO_H

#include "Validator.h"

namespace val {

template <typename T>
class LessThanOrEqualTo : public Validator
{
    Q_DECLARE_TR_FUNCTIONS(val)
public:
    LessThanOrEqualTo();

    LessThanOrEqualTo(T value);

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant value() const;
    void setValue(const QVariant &value);

private:
    QVariant _value;
};

template <typename T>
LessThanOrEqualTo<T>::LessThanOrEqualTo()
{

}

template <typename T>
LessThanOrEqualTo<T>::LessThanOrEqualTo(T value) : _value(value)
{

}

template <typename T>
bool LessThanOrEqualTo<T>::validate(const QVariant &value) const
{
    return (value.value<T>() <= _value.value<T>());
}

template <typename T>
QString LessThanOrEqualTo<T>::errorMessage() const
{
    return tr("the value should be less than or equal to") + " " + _value.toString();
}

template <typename T>
QVariant LessThanOrEqualTo<T>::value() const
{
    return _value;
}

template <typename T>
void LessThanOrEqualTo<T>::setValue(const QVariant &value)
{
    _value = value;
}

} // namespace val

#endif // VAL_LESSTHANOREQUALTO_H
