#ifndef MENU_MATH_DIV_H
#define MENU_MATH_DIV_H

#include "menu/SimpleAction.h"

namespace menu {
namespace math {

class Div : public SimpleAction
{
public:
    Div();

protected:
    QVariant simplyAct(const QVariantList &args) final;

private:

    def::ActionDef actionDef() const final;
};

} // namespace math
} // namespace menu

#endif // MENU_MATH_DIV_H
