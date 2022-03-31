#ifndef DOUBLERANDVALUE_H
#define DOUBLERANDVALUE_H

#include <QVariant>


namespace potato_util
{

class DoubleRandValue
{
public:
    DoubleRandValue();

    DoubleRandValue(const double &dMin, const double &dMax);

    operator double() const;

    operator QVariant() const;

private:
    double _dMin;
    double _dMax;
};

} // namespace potato_util

Q_DECLARE_METATYPE(potato_util::DoubleRandValue)

#endif // DOUBLERANDVALUE_H
