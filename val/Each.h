#ifndef VAL_EACH_H
#define VAL_EACH_H

#include "Validator.h"

namespace val {

//validates each element of a list
class Each : public Validator
{
public:
    Each();

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    const QList<ValidatorPtr> &validators() const;
    void setValidators(const QList<ValidatorPtr> &newValidators);
    void addValidator(ValidatorPtr validatorPtr);

private:
    QList<ValidatorPtr> _validators;

    bool validateForEachValidator(const QVariant &value) const;
};

} // namespace val

#endif // VAL_EACH_H
