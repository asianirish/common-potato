#ifndef HI_NOSUCHFIELD_H
#define HI_NOSUCHFIELD_H

#include "FieldException.h"

namespace hi {

class NoSuchField : public hi::FieldException
{
public:
    NoSuchField(const QString &fieldName);

    QByteArray cause() const override {
        return QByteArray("no such field");
    }
};

} // namespace hi

#endif // HI_NOSUCHFIELD_H
