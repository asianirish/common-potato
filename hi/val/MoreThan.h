#ifndef HI_VAL_MORETHAN_H
#define HI_VAL_MORETHAN_H

#include "Validator.h"

namespace hi {
namespace val {

class MoreThan : public Validator
{
public:
    MoreThan();

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant value() const;
    void setValue(const QVariant &value);

private:
    QVariant _value;
};

} // namespace val
} // namespace hi

#endif // HI_VAL_MORETHAN_H
