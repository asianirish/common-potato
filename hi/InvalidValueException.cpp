#include "InvalidValueException.h"

namespace hi {

InvalidValueException::InvalidValueException(const QString &fieldName) : hi::SetFieldException(fieldName)
{

}

} // namespace hi
