#ifndef HIERHIN_NOSUCHFIELD_H
#define HIERHIN_NOSUCHFIELD_H

#include "PropertyException.h"

namespace hierhin {
namespace ex {

class NoSuchProperty : public PropertyException
{
public:
    NoSuchProperty(const QString &name);

    QByteArray cause() const override {
        return QByteArray("no such a property");
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_NOSUCHFIELD_H
