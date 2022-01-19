#include "Each.h"

#include <QSharedPointer>

namespace val {

Each::Each()
{

}

bool Each::validate(const QVariant &value) const
{
    if (value.canConvert<QVariantList>()) {
        auto lst = value.value<QVariantList>();

        for (auto &element : lst) {
            if (!validateForEachValidator(element)) {
                return false;
            }
        }

        return true;
    }

    return validateForEachValidator(value);
}

QString Each::errorMessage() const
{
    return _lastError;
}

const QList<ValidatorPtr> &Each::validators() const
{
    return _validators;
}

void Each::setValidators(const QList<ValidatorPtr> &newValidators)
{
    _validators = newValidators;
}

void Each::addValidator(ValidatorPtr validatorPtr)
{
    _validators.append(validatorPtr);
}

bool Each::validateForEachValidator(const QVariant &value) const
{
    for (auto &validator : _validators) {
        if (!validator->validate(value)) {
            _lastError = validator->errorMessage();
            return false;
        }
    }

    return true;
}

} // namespace val
