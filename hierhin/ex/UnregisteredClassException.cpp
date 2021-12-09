#include "UnregisteredClassException.h"

namespace hierhin {
namespace ex {

UnregisteredClassException::UnregisteredClassException()
{

}

const QString &UnregisteredClassException::className() const
{
    return _className;
}

void UnregisteredClassException::setClassName(const QString &newClassName)
{
    _className = newClassName;
}

} // namespace ex
} // namespace hierhin
