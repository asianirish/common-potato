#include "FieldException.h"

namespace hi {
namespace ex {

FieldException::FieldException(const QString &fieldName) : _fieldName(fieldName)
{

}

QString FieldException::fieldName() const
{
    return _fieldName;
}

void FieldException::setFieldName(const QString &fieldName)
{
    _fieldName = fieldName;
}

} // namespace ex
} // namespace hi
