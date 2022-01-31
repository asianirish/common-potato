#include "NoSuchLinkOwner.h"

namespace hierhin {
namespace ex {

NoSuchLinkOwner::NoSuchLinkOwner()
{

}

NoSuchLinkOwner::NoSuchLinkOwner(const Role &role) : ChildItemException(role)
{

}

} // namespace ex
} // namespace hierhin
