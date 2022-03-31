#include "DoubleRandValue.h"
#include "gfunc.h"

namespace potato_util
{

DoubleRandValue::DoubleRandValue() : DoubleRandValue(0., 1.)
{

}

DoubleRandValue::DoubleRandValue(const double &dMin, const double &dMax) : _dMin(dMin),
    _dMax(dMax)
{

}

double DoubleRandValue::toDouble() const
{
    return dRand(_dMin, _dMax);
}

DoubleRandValue::operator double() const
{
    return toDouble();
}

//DoubleRandValue::operator QVariant() const
//{
//    return toDouble();
//}

} // namespace potato_util
