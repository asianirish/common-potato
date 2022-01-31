#ifndef HIERHIN_EX_NOTLISTTYPE_H
#define HIERHIN_EX_NOTLISTTYPE_H

#include "PropertyException.h"

namespace hierhin {
namespace ex {

class NotListType : public PropertyException
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    NotListType();
    NotListType(const QString &name);

    QString cause() const override {
        return tr("not a list type property %1").arg(name());
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_NOTLISTTYPE_H
