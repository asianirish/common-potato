#ifndef HIERHIN_EX_NOSUCHLINKOWNER_H
#define HIERHIN_EX_NOSUCHLINKOWNER_H

#include "ChildItemException.h"

namespace hierhin {
namespace ex {

class NoSuchLinkOwner : public ChildItemException
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    NoSuchLinkOwner();

    NoSuchLinkOwner(const Role &role);

    QString cause() const override {
        return tr("no such link owner: '%1'").arg(role());
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_NOSUCHLINKOWNER_H
