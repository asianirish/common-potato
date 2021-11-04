#include "ValidatorException.h"

namespace hierhin {
namespace ex {

ValidatorException::ValidatorException(const QString &name, const QString &validatorErrorMsg) :
    PropertyException(name),
    _validatorErrorMsg(validatorErrorMsg)
{

}

} // namespace ex
} // namespace hierhin
