#ifndef HI_INVALIDVALUEEXCEPTION_H
#define HI_INVALIDVALUEEXCEPTION_H

#include "SetFieldException.h"

namespace hi {

class InvalidValueException : public hi::FieldException
{
public:
    InvalidValueException(const QString &fieldName);

    QByteArray cause() const override {
        return QByteArray("invalid value");
    }
};

} // namespace hi

#endif // HI_INVALIDVALUEEXCEPTION_H
