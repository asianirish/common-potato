#ifndef HI_ABSTRACTREGEX_H
#define HI_ABSTRACTREGEX_H

#include "Validator.h"

namespace val {

class AbstractRegex : public Validator
{
public:
    AbstractRegex();

    bool validate(const QVariant &value) const final;
    QString errorMessage() const override;

private:
    virtual QString pattern() const = 0;
};

} // namespace val

#endif // VAL_ABSTRACTREGEX_H
