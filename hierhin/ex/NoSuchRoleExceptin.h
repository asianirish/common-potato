#ifndef HIERHIN_EX_NOSUCHROLEEXCEPTIN_H
#define HIERHIN_EX_NOSUCHROLEEXCEPTIN_H

#include "ChildItemException.h"

namespace hierhin {
namespace ex {

class NoSuchRoleExceptin : public ChildItemException
{
public:
    NoSuchRoleExceptin();

    QString cause() const override {
        return QObject::tr("no such a role") + " '" + _role + "'";
    }

    const QString &role() const;
    void setRole(const QString &newRole);

private:
    QString _role;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_NOSUCHROLEEXCEPTIN_H
