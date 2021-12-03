#ifndef VAL_NOTEQUALTO_H
#define VAL_NOTEQUALTO_H

#include "Validator.h"

namespace val {

class NotEqualTo : public Validator
{
    Q_DECLARE_TR_FUNCTIONS(val)
public:
    NotEqualTo();

    NotEqualTo(int value);

    NotEqualTo(double value);

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant value() const;
    void setValue(const QVariant &value);

private:
    QVariant _value;
};

} // namespace val

#endif // VAL_NOTEQUALTO_H
