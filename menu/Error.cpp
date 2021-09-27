#include "Error.h"

namespace menu {

const int Error::NO_ERROR = 0;

Error::Error()
{

}

int Error::code() const
{
    return _code;
}

void Error::setCode(int code)
{
    _code = code;
}

QString Error::description() const
{
    return _description;
}

void Error::setDescription(const QString &description)
{
    _description = description;
}

QVariantMap Error::context() const
{
    return _context;
}

void Error::setContext(const QVariantMap &context)
{
    _context = context;
}

} // namespace menu
