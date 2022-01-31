#ifndef HIERHIN_NOSUCHFIELD_H
#define HIERHIN_NOSUCHFIELD_H

#include "PropertyException.h"

namespace hierhin {
namespace ex {

class NoSuchProperty : public PropertyException
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    NoSuchProperty(const QString &name);

    QString cause() const override {
        return tr("no such a property '%1'").arg(name());
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_NOSUCHFIELD_H
