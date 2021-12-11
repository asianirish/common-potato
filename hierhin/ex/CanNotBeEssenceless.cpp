#include "CanNotBeEssenceless.h"

namespace hierhin {
namespace ex {

CanNotBeEssenceless::CanNotBeEssenceless()
{

}

CanNotBeEssenceless::CanNotBeEssenceless(const Role &role) : ChildItemException(role)
{

}

} // namespace ex
} // namespace hierhin
