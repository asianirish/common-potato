#include "TypeValidator.h"

namespace val {

TypeValidator::TypeValidator()
{

}

bool TypeValidator::validate(const QVariant &value) const
{
    //TODO: implement
    Q_UNUSED(value)
    return true;
}

QString TypeValidator::errorMessage() const
{
    //TODO: implement
    return QString();
}

QMetaType::Type TypeValidator::type() const
{
    return _type;
}

void TypeValidator::setType(QMetaType::Type newType)
{
    _type = newType;
}

int TypeValidator::userType() const
{
    return _userType;
}

void TypeValidator::setUserType(int newUserType)
{
    _userType = newUserType;
}

} // namespace val
