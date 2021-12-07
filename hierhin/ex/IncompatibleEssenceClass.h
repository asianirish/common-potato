#ifndef HIERHIN_EX_INCOMPATIBLEESSENCECLASS_H
#define HIERHIN_EX_INCOMPATIBLEESSENCECLASS_H

#include "ChildItemException.h"

namespace hierhin {
namespace ex {

class IncompatibleEssenceClass : public ChildItemException
{
public:
    IncompatibleEssenceClass();

    QString cause() const override {
        return QObject::tr("incompatible essence class")/* + " '" + _role + "'"*/;
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_INCOMPATIBLEESSENCECLASS_H
