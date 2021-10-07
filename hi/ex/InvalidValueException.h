#ifndef HI_INVALIDVALUEEXCEPTION_H
#define HI_INVALIDVALUEEXCEPTION_H

#include "FieldException.h"

namespace hi {
namespace ex {

class InvalidValueException : public FieldException
{
public:
    InvalidValueException(const QString &fieldName);

    QByteArray cause() const override {
        return QByteArray("invalid value");
    }
};

} // namespace ex
} // namespace hi

#endif // HI_INVALIDVALUEEXCEPTION_H
