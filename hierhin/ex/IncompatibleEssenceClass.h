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
    IncompatibleEssenceClass(const Role &role);

    QString cause() const override {
        if (role().isEmpty()) {
            return tr("incompatible essence class");
        }

        return tr("incompatible essence class for role") + " '" + role() + "'";
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_INCOMPATIBLEESSENCECLASS_H
