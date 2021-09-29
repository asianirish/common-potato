#ifndef MENU_DEF_NOTEQUALCONSTRAINT_H
#define MENU_DEF_NOTEQUALCONSTRAINT_H

#include "Constraint.h"

namespace menu {
namespace def {

class NotEqualConstraint : public Constraint
{
public:
    NotEqualConstraint();

    QVariant value() const;
    void setValue(const QVariant &value);

private:
    void validateSpecific(const QVariant &arg, Error &err) const override;

private:
    QVariant _value;
};

} // namespace def
} // namespace menu

#endif // MENU_DEF_NOTEQUALCONSTRAINT_H
