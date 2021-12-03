#ifndef HIERHIN_NOSUCHFIELD_H
#define HIERHIN_NOSUCHFIELD_H

#include "PropertyException.h"

namespace hierhin {
namespace ex {

class NoSuchProperty : public PropertyException
{
public:
    NoSuchProperty(const QString &name);

    QString cause() const override {
        return QObject::tr("no such a property") + " '" + name() + "'";
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_NOSUCHFIELD_H
