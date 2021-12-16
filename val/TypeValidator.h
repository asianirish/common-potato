#ifndef VAL_TYPEVALIDATOR_H
#define VAL_TYPEVALIDATOR_H

#include "Validator.h"

#include <QString>
#include <QMetaType>

namespace val {

class TypeValidator : public Validator
{
public:
    TypeValidator();

    TypeValidator(QMetaType type, int userType);

    bool validate(const QVariant &value) const override;

    virtual QString errorMessage() const override;

    QMetaType::Type type() const;
    void setType(QMetaType::Type newType);

    int userType() const;
    void setUserType(int newUserType);

private:
    QMetaType::Type _type;
    int _userType;
};

} // namespace val

#endif // VAL_TYPEVALIDATOR_H
