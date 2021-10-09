#ifndef HI_VAL_LESSTHANOREQUALTO_H
#define HI_VAL_LESSTHANOREQUALTO_H

#include "Validator.h"

namespace hi {
namespace val {

class LessThanOrEqualTo : public Validator
{
public:
    LessThanOrEqualTo();

    LessThanOrEqualTo(int value);

    LessThanOrEqualTo(double value)

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant value() const;
    void setValue(const QVariant &value);

private:
    QVariant _value;
};

} // namespace val
} // namespace hi

#endif // HI_VAL_LESSTHANOREQUALTO_H
