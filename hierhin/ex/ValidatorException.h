#ifndef HIERHIN_EX_VALIDATOREXCEPTION_H
#define HIERHIN_EX_VALIDATOREXCEPTION_H

#include "PropertyException.h"

namespace hierhin {
namespace ex {

class ValidatorException : public PropertyException
{
public:
    ValidatorException(const QString &name, const QString &validatorErrorMsg);

    QString cause() const override {
        return _validatorErrorMsg;
    }
private:
    QString _validatorErrorMsg;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_VALIDATOREXCEPTION_H
