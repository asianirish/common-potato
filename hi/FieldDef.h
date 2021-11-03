#ifndef FIELDDEF_H
#define FIELDDEF_H

#include <val/Validator.h>

#include <QVariant>
#include <QSharedPointer>

namespace hi {

typedef QSharedPointer<val::Validator> ValidatorPtr;

class Item;

class FieldDef
{
public:
    FieldDef();

//    FieldDef(const FieldDef &fieldDef);

    FieldDef(const QString &itemClassName);

    QVariant defaultValue() const;
    void setDefaultValue(const QVariant &defaultValue);

    QList<ValidatorPtr> validators() const;
    void setValidators(const QList<ValidatorPtr> &validators);
    void addValidator(const ValidatorPtr &vptr);

    QString itemClassName() const;

private:
    QVariant _defaultValue;
    //TODO: QMetaType _metaType;?
    QList<ValidatorPtr> _validators;
    QString _itemClassName;
};

} // namespace hi

#endif // FIELDDEF_H
