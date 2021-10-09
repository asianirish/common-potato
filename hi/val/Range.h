#ifndef HI_VAL_RANGE_H
#define HI_VAL_RANGE_H

#include "Validator.h"

namespace hi {
namespace val {

class Range : public Validator
{
public:
    Range();

    Range(int minValue, int maxValue);

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

} // namespace val
} // namespace hi

#endif // HI_VAL_RANGE_H
