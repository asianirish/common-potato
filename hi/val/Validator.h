#ifndef HI_VAL_VALIDATOR_H
#define HI_VAL_VALIDATOR_H

#include <QVariant>
#include <QString>

namespace hi {
namespace val {

class Validator
{
public:
    Validator();

    virtual bool validate(const QVariant &value) const = 0;

    virtual QString errorMessage() const = 0;
};

} // namespace val
} // namespace hi

#endif // HI_VAL_VALIDATOR_H
