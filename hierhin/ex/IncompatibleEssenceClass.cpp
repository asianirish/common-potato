#include "IncompatibleEssenceClass.h"

namespace hierhin {
namespace ex {

IncompatibleEssenceClass::IncompatibleEssenceClass()
{

}

IncompatibleEssenceClass::IncompatibleEssenceClass(const Role &role) : ChildItemException(role)
{

}

} // namespace ex
} // namespace hierhin
