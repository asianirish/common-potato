#ifndef HIERHIN_DEF_PROPERTYDEF_H
#define HIERHIN_DEF_PROPERTYDEF_H

#include <val/Validator.h>

#include <QSharedPointer>

namespace hierhin {
namespace def {

typedef QSharedPointer<val::Validator> ValidatorPtr;

class PropertyDef
{
public:
    PropertyDef();

    QList<ValidatorPtr> validators() const;
    void setValidators(const QList<ValidatorPtr> &validators);
    void addValidator(const ValidatorPtr &vptr);

    QVariant defaultValue() const;
    void setDefaultValue(const QVariant &defaultValue);

private:
    QList<ValidatorPtr> _validators;
    QVariant _defaultValue;
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_PROPERTYDEF_H
