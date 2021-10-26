#ifndef VAL_VALIDATOR_H
#define VAL_VALIDATOR_H

#include <QVariant>
#include <QString>

namespace val {

class Validator
{
public:
    Validator();

    virtual ~Validator() = default;

    virtual bool validate(const QVariant &value) const = 0;

    virtual QString errorMessage() const = 0;
};

} // namespace val

#endif // VAL_VALIDATOR_H
