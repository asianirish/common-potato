#include "TypeValidator.h"

namespace val {

TypeValidator::TypeValidator()
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
