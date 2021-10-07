#ifndef HI_VAL_NOTEQUALTO_H
#define HI_VAL_NOTEQUALTO_H

#include "Validator.h"

namespace hi {
namespace val {

class NotEqualTo : public Validator
{
public:
    NotEqualTo();

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant value() const;
    void setValue(const QVariant &value);

private:
    QVariant _value;
};

} // namespace val
} // namespace hi

#endif // HI_VAL_NOTEQUALTO_H
