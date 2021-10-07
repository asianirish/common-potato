#ifndef HI_NOSUCHFIELD_H
#define HI_NOSUCHFIELD_H

#include "SetFieldException.h"

namespace hi {

class NoSuchField : public hi::SetFieldException
{
public:
    NoSuchField(const QString &fieldName);

    QByteArray cause() const override {
        return QByteArray("no such field");
    }
};

} // namespace hi

#endif // HI_NOSUCHFIELD_H
