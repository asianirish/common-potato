#ifndef SETFIELDEXCEPTION_H
#define SETFIELDEXCEPTION_H

#include "Exception.h"

namespace hi {

class SetFieldException : public hi::Exception
{
public:
    SetFieldException(const QString &fieldName);

    QByteArray cause() const override {
        return QByteArray("unknown set field exception");
    }

    QString fieldName() const;
    void setFieldName(const QString &fieldName);

private:
    QString _fieldName;
};

} // namespace hi

#endif // SETFIELDEXCEPTION_H
