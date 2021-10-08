#ifndef HI_VAL_MORETHANOREQUALTO_H
#define HI_VAL_MORETHANOREQUALTO_H

#include "Validator.h"

namespace hi {
namespace val {

class MoreThanOrEqualTo : public Validator
{
public:
    MoreThanOrEqualTo();

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant value() const;
    void setValue(const QVariant &value);

private:
    QVariant _value;
};

} // namespace val
} // namespace hi

#endif // HI_VAL_MORETHANOREQUALTO_H
