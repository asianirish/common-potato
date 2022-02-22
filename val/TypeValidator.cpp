#include "TypeValidator.h"

namespace val {

TypeValidator::TypeValidator()
{

}

TypeValidator::TypeValidator(QMetaType::Type type, int userType) : _type(type),
    _userType(userType)
{

}

bool TypeValidator::validate(const QVariant &value) const
{
    if (static_cast<QMetaType::Type>(value.type()) >= QMetaType::User) {
        return (value.userType() == _userType);
    }

    return value.canConvert(_type);
}

QString TypeValidator::errorMessage() const
{
    return QString("incompatible type QMetaType::Type: %1, User type: %2").arg(_type).arg(_userType);
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
