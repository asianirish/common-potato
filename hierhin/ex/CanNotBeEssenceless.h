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

    QString cause() const override {
        return tr("the child item can not be essenceless")/* + " '" + _role + "'"*/;
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_CANNOTBEESSENCELESS_H