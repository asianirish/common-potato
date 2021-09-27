#include "Result.h"

namespace menu {

const int Result::SUCCESSFUL_RESULT = 0;

Result::Result() : Result(QVariant())
{

}

Result::Result(const QVariant &value) : _value(value)
{

}

QVariant Result::value() const
{
    return _value;
}

void Result::setValue(const QVariant &value)
{
    _value = value;
}

int Result::errorCode() const
{
    return _error.code();
}

void Result::setErrorCode(int errorCode)
{
    _error.setCode(errorCode);
}

QString Result::errorDescription() const
{
    return _error.description();
}

void Result::setErrorDescription(const QString &errorDescription)
{
    _error.setDescription(errorDescription);
}

QVariantMap Result::errorContext() const
{
    return _error.context();
}

void Result::setErrorContext(const QVariantMap &errorContext)
{
    _error.setContext(errorContext);
}

Result &Result::operator =(const QVariant &value)
{
    _value = value;
    _error.clear();

    return *this;
}

QString Result::taskId() const
{
    return _taskId;
}

void Result::setTaskId(const QString &taskId)
{
    _taskId = taskId;
}

Error Result::error() const
{
    return _error;
}

void Result::setError(const Error &error)
{
    _error = error;
}

menu::Result::operator QVariant()
{
    if (!_error) {
        return _value;
    }
    
    return QVariant();
}

} // namespace menu
