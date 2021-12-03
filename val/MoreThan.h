#ifndef VAL_MORETHAN_H
#define VAL_MORETHAN_H

#include "Validator.h"

namespace val {

template <typename T>
class MoreThan : public Validator
{
    Q_DECLARE_TR_FUNCTIONS(val)
public:
    MoreThan();

    MoreThan(int value);

    MoreThan(double value);

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant value() const;
    void setValue(const QVariant &value);

private:
    QVariant _value;
};

template <typename T>
MoreThan<T>::MoreThan()
{

}

template <typename T>
MoreThan<T>::MoreThan(int value) : _value(value)
{

}

template <typename T>
MoreThan<T>::MoreThan(double value) : _value(value)
{

}

template <typename T>
bool MoreThan<T>::validate(const QVariant &value) const
{
    return (value.value<T>() > _value.value<T>());
}

template <typename T>
QString MoreThan<T>::errorMessage() const
{
    return tr("the value should be more than %n", "", _value.toInt());
}

template <typename T>
QVariant MoreThan<T>::value() const
{
    return _value;
}

template <typename T>
void MoreThan<T>::setValue(const QVariant &value)
{
    _value = value;
}

} // namespace val

#endif // VAL_MORETHAN_H
