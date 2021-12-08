#ifndef HIERHIN_EX_INCOMPATIBLEESSENCECLASS_H
#define HIERHIN_EX_INCOMPATIBLEESSENCECLASS_H

#include "ChildItemException.h"

namespace hierhin {
namespace ex {

class IncompatibleEssenceClass : public ChildItemException
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    IncompatibleEssenceClass();

    QString cause() const override {
        return QObject::tr("incompatible essence class")/* + " '" + _role + "'"*/;
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_INCOMPATIBLEESSENCECLASS_H
