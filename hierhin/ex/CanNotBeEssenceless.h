#ifndef HIERHIN_EX_CANNOTBEESSENCELESS_H
#define HIERHIN_EX_CANNOTBEESSENCELESS_H

#include "ChildItemException.h"

namespace hierhin {
namespace ex {

class CanNotBeEssenceless : public ChildItemException
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    CanNotBeEssenceless();

    CanNotBeEssenceless(const Role &role);

    QString cause() const override {
        if (role().isEmpty()) {
            return tr("the child item can not be essenceless");
        }

        return tr("the child item can not be essenceless for role") + " '" + role() + "'";
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_CANNOTBEESSENCELESS_H
