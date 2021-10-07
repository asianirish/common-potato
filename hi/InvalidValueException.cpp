#include "InvalidValueException.h"

namespace hi {

InvalidValueException::InvalidValueException(const QString &fieldName) : hi::FieldException(fieldName)
{

}

} // namespace hi
