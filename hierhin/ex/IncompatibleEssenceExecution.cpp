#include "IncompatibleEssenceExecution.h"

namespace hierhin {
namespace ex {

IncompatibleEssenceExecution::IncompatibleEssenceExecution()
{

}

IncompatibleEssenceExecution::IncompatibleEssenceExecution(const QString &intendedClass, const QString &actualClass) :
    _intendedClass(intendedClass),
    _actualClass(actualClass)
{

}

const QString &IncompatibleEssenceExecution::actualClass() const
{
    return _actualClass;
}

void IncompatibleEssenceExecution::setActualClass(const QString &newActualClass)
{
    _actualClass = newActualClass;
}

const QString &IncompatibleEssenceExecution::intendedClass() const
{
    return _intendedClass;
}

void IncompatibleEssenceExecution::setIntendedClass(const QString &newIntendedClass)
{
    _intendedClass = newIntendedClass;
}

} // namespace ex
} // namespace hierhin

