#include "SetFieldException.h"

namespace hi {

SetFieldException::SetFieldException(const QString &fieldName) : _fieldName(fieldName)
{

}

QString SetFieldException::fieldName() const
{
    return _fieldName;
}

void SetFieldException::setFieldName(const QString &fieldName)
{
    _fieldName = fieldName;
}

} // namespace hi
