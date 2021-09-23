#include "Result.h"

namespace menu {

const int Result::SUCCESSFUL_RESULT = 0;

Result::Result() : Result(QVariant())
{

}

Result::Result(const QVariant &value) : _value(value),
    _errorCode(SUCCESSFUL_RESULT)
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
    return _errorCode;
}

void Result::setErrorCode(int errorCode)
{
    _errorCode = errorCode;
}

QString Result::errorDescription() const
{
    return _errorDescription;
}

void Result::setErrorDescription(const QString &errorDescription)
{
    _errorDescription = errorDescription;
}

QVariantMap Result::errorContext() const
{
    return _errorContext;
}

void Result::setErrorContext(const QVariantMap &errorContext)
{
    _errorContext = errorContext;
}

Result &Result::operator =(const QVariant &value)
{
    _value = value;
    _errorCode = SUCCESSFUL_RESULT;
    _errorDescription.clear();
    _errorContext.clear();

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

menu::Result::operator QVariant()
{
    if (_errorCode == SUCCESSFUL_RESULT) {
        return _value;
    }
    
    return QVariant();
}

} // namespace menu
