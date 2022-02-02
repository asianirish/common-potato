#include "Error.h"

namespace menu {

const int Error::NO_USER_ERROR = 0;

Error::Error() : _code(NO_ERROR),
    _userCode(NO_USER_ERROR)
{

}

Error::CODE Error::code() const
{
    return _code;
}

void Error::setCode(CODE code)
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
    _code = CODE::NO_ERROR;
    _description.clear();
    _context.clear();
}

menu::Error::operator bool() const
{
    return !(_code == NO_ERROR) && !(_userCode == NO_USER_ERROR);
}

int Error::userCode() const
{
    return _userCode;
}

void Error::setUserCode(int newUserCode)
{
    _userCode = newUserCode;
    if (_userCode != NO_USER_ERROR) {
        _code = USER_DEFINED;
    }
}

} // namespace menu
