#ifndef FIELDEXCEPTION_H
#define FIELDEXCEPTION_H

#include "Exception.h"

namespace hi {
namespace ex {

class FieldException : public Exception
{
public:
    FieldException(const QString &fieldName);

    QByteArray cause() const override {
        return QByteArray("unknown set field exception");
    }

    QString fieldName() const;
    void setFieldName(const QString &fieldName);

private:
    QString _fieldName;
};

} // namespace ex
} // namespace hi

#endif // FIELDEXCEPTION_H
