#ifndef HI_EX_VALIDATOREXCEPTION_H
#define HI_EX_VALIDATOREXCEPTION_H

#include "FieldException.h"

namespace hi {
namespace ex {

class ValidatorException : public FieldException
{
public:
    ValidatorException(const QString &fieldName, const QString &validatorErrorMsg);

    QByteArray cause() const override {
        return _validatorErrorMsg.toLatin1();
    }
private:
    QString _validatorErrorMsg;
};

} // namespace ex
} // namespace hi

#endif // HI_EX_VALIDATOREXCEPTION_H
