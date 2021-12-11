#include "NoSuchRole.h"

namespace hierhin {
namespace ex {

NoSuchRole::NoSuchRole()
{

}

NoSuchRole::NoSuchRole(const Role &role) : ChildItemException(role)
{

}

} // namespace ex
} // namespace hierhin
