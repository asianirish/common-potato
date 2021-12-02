#ifndef HIERHIN_INVALIDVALUEEXCEPTION_H
#define HIERHIN_INVALIDVALUEEXCEPTION_H

#include "PropertyException.h"

namespace hierhin {
namespace ex {

class InvalidValueException : public PropertyException
{
public:
    InvalidValueException(const QString &name);

    QString cause() const override {
        return QObject::tr("invalid value");
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_INVALIDVALUEEXCEPTION_H
