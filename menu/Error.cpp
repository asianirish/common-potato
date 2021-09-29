#include "Error.h"

namespace menu {

const int Error::NO_ERROR = 0;

Error::Error() : _code(NO_ERROR),
    _type(ERROR_TYPE::UNDEFINED)
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

void Error::addContext(const QString &key, const QVariant &value)
{
    _context.insert(key, value);
}

void Error::clear()
{
    _code = NO_ERROR;
    _description.clear();
    _context.clear();
}

Error::ERROR_TYPE Error::type() const
{
    return _type;
}

void Error::setType(const ERROR_TYPE &type)
{
    _type = type;
}

menu::Error::operator bool() const
{
    return !(_code == NO_ERROR);
}

} // namespace menu
