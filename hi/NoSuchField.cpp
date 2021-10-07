#include "NoSuchField.h"

namespace hi {

NoSuchField::NoSuchField(const QString &fieldName) : hi::SetFieldException(fieldName)
{

}

} // namespace hi
