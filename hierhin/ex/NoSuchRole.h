#ifndef HIERHIN_EX_NOSUCHROLEEXCEPTIN_H
#define HIERHIN_EX_NOSUCHROLEEXCEPTIN_H

#include "ChildItemException.h"

namespace hierhin {
namespace ex {

class NoSuchRole : public ChildItemException
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    NoSuchRole();
    NoSuchRole(const Role &role);

    QString cause() const override {
        return tr("no such a role '%1'").arg(role());
    }

};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_NOSUCHROLEEXCEPTIN_H
