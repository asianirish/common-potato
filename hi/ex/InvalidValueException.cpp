#include "InvalidValueException.h"

namespace hi {
namespace ex {

InvalidValueException::InvalidValueException(const QString &fieldName) : FieldException(fieldName)
{

}

} // namespace ex
} // namespace hi
