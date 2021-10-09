#ifndef FIELDDEF_H
#define FIELDDEF_H

#include "val/Validator.h"

#include <QVariant>
#include <QSharedPointer>

namespace hi {

typedef QSharedPointer<val::Validator> ValidatorPtr;

class FieldDef
{
public:
    FieldDef();

    QVariant defaultValue() const;
    void setDefaultValue(const QVariant &defaultValue);

    QList<ValidatorPtr> validators() const;
    void setValidators(const QList<ValidatorPtr> &validators);
    void addValidator(const ValidatorPtr &vptr);

    bool inheritable() const;
    void setInheritable(bool inheritable);

private:
    QVariant _defaultValue;
    //TODO: QMetaType _metaType;?
    QList<ValidatorPtr> _validators;
    bool _inheritable;
};

} // namespace hi

#endif // FIELDDEF_H
