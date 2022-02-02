#include "Constraint.h"

namespace menu {
namespace def {

Constraint::Constraint()
{

}

Error Constraint::validate(const QVariant &arg) const
{
    Error err;

    validateSpecific(arg, err);

    return err;
}

} // namespace def
} // namespace menu
