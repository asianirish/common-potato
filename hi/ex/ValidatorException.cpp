#include "ValidatorException.h"

namespace hi {
namespace ex {

ValidatorException::ValidatorException(const QString &fieldName, const QString &validatorErrorMsg) :
    FieldException(fieldName),
    _validatorErrorMsg(validatorErrorMsg)
{

}

} // namespace ex
} // namespace hi
