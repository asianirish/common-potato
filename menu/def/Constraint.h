#ifndef MENU_DEF_CONSTRAINT_H
#define MENU_DEF_CONSTRAINT_H

#include <QVariant>


namespace menu {
namespace def {

class Constraint
{
public:
    Constraint();

    virtual bool validate(const QVariant &arg) const = 0;
};

} // namespace def
} // namespace menu

#endif // MENU_DEF_CONSTRAINT_H
