#include "NoSuchField.h"

namespace hi {

NoSuchField::NoSuchField(const QString &fieldName) : hi::FieldException(fieldName)
{

}

} // namespace hi
