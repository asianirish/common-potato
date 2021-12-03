#include "NotEqualTo.h"

namespace val {

NotEqualTo::NotEqualTo()
{

}

NotEqualTo::NotEqualTo(int value) : _value(value)
{

}

NotEqualTo::NotEqualTo(double value) : _value(value)
{

}

bool NotEqualTo::validate(const QVariant &value) const
{
    if (value == this->value()) {
        return false;
    }

    return true;
}

QString NotEqualTo::errorMessage() const
{
    return tr("the value should not be equal to %n", "", _value.toInt());
}

QVariant NotEqualTo::value() const
{
    return _value;
}

void NotEqualTo::setValue(const QVariant &value)
{
    _value = value;
}

} // namespace val

