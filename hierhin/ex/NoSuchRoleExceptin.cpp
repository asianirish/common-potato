#include "NoSuchRoleExceptin.h"

namespace hierhin {
namespace ex {

NoSuchRoleExceptin::NoSuchRoleExceptin()
{

}

const QString &NoSuchRoleExceptin::role() const
{
    return _role;
}

void NoSuchRoleExceptin::setRole(const QString &newRole)
{
    _role = newRole;
}

} // namespace ex
} // namespace hierhin
