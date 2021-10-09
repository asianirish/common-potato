#ifndef HI_VAL_LESSTHAN_H
#define HI_VAL_LESSTHAN_H

#include "Validator.h"

namespace hi {
namespace val {

class LessThan : public Validator
{
public:
    LessThan();

    LessThan(int value);

    LessThan(double value);

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant value() const;
    void setValue(const QVariant &value);

private:
    QVariant _value;
};

} // namespace val
} // namespace hi

#endif // HI_VAL_LESSTHAN_H
