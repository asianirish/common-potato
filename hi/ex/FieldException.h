#ifndef FIELDEXCEPTION_H
#define FIELDEXCEPTION_H

#include "Exception.h"

namespace hi {

class FieldException : public hi::Exception
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

} // namespace hi

#endif // FIELDEXCEPTION_H
