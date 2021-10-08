#include "LessThan.h"

namespace hi {
namespace val {

LessThan::LessThan()
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

} // namespace val
} // namespace hi
