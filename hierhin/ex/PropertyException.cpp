#include "PropertyException.h"

namespace hierhin {
namespace ex {

PropertyException::PropertyException(const QString &name) : _name(name)
{

}

QString PropertyException::name() const
{
    return _name;
}

void PropertyException::setName(const QString &name)
{
    _name = name;
}

} // namespace ex
} // namespace hierhin
