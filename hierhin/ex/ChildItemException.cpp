#include "ChildItemException.h"

namespace hierhin {
namespace ex {

ChildItemException::ChildItemException() : ChildItemException(Role())
{

}

ChildItemException::ChildItemException(const Role &role) : _role(role)
{

}

const QString &ChildItemException::role() const
{
    return _role;
}

void ChildItemException::setRole(const QString &newRole)
{
    _role = newRole;
}


} // namespace ex
} // namespace hierhin
