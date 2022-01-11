#ifndef HIERHIN_DEF_PROPERTYDEF_H
#define HIERHIN_DEF_PROPERTYDEF_H

#include <val/Validator.h>

#include <QSharedPointer>

namespace hierhin {
namespace def {

class PropertyDef
{
public:
    PropertyDef();

    QList<val::ValidatorPtr> validators() const;
    void setValidators(const QList<val::ValidatorPtr> &validators);
    void addValidator(const val::ValidatorPtr &vptr);

    QVariant defaultValue() const;
    void setDefaultValue(const QVariant &defaultValue);

    void validate(const QVariant &value);

    const QString &name() const;
    void setName(const QString &newName);

    int typeId() const;
    void setTypeId(int newTypeId);

private:
    QList<val::ValidatorPtr> _validators;
    QVariant _defaultValue;
    QString _name;
    int _typeId;
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_PROPERTYDEF_H
