#ifndef MENU_DEF_ARGDEF_H
#define MENU_DEF_ARGDEF_H

#include "Constraint.h"

#include <QVariant>

namespace menu {
namespace def {

class ArgDef
{
public:
    ArgDef();

    QVariant defaultValue() const;
    void setDefaultValue(const QVariant &defaultValue);

    bool isDefaultValue() const;

    void addConstraint(QSharedPointer<Constraint> constraint);

private:
    QVariant _defaultValue;
    QList<QSharedPointer<Constraint>> _constraints;
};

} // namespace def
} // namespace menu

#endif // MENU_DEF_ARGDEF_H
