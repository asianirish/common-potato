#ifndef HI_VAL_ABSTRACTREGEX_H
#define HI_VAL_ABSTRACTREGEX_H

#include "Validator.h"

namespace hi {
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
} // namespace hi

#endif // HI_VAL_ABSTRACTREGEX_H
