#ifndef MENU_DEF_CONSTRAINT_H
#define MENU_DEF_CONSTRAINT_H

#include "../Error.h"

#include <QVariant>

namespace menu {
namespace def {

class Constraint
{
public:
    Constraint();

    Error validate(const QVariant &arg) const;

private:
    virtual void validateSpecific(const QVariant &arg, Error &err) const = 0;
};

} // namespace def
} // namespace menu

#endif // MENU_DEF_CONSTRAINT_H
