#include "IncompatibleValueType.h"

namespace hierhin {
namespace ex {

IncompatibleValueType::IncompatibleValueType()
{

}

IncompatibleValueType::IncompatibleValueType(int typeId) : _typeId(typeId)
{

}

int IncompatibleValueType::typeId() const
{
    return _typeId;
}

void IncompatibleValueType::setTypeId(int newTypeId)
{
    _typeId = newTypeId;
}

} // namespace ex
} // namespace hierhin
