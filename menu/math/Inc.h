#ifndef MENU_MATH_INC_H
#define MENU_MATH_INC_H

#include "menu/SimpleAction.h"

namespace menu {
namespace math {

class Inc : public SimpleAction
{
public:
    Inc();

    const char *alias() const final;

protected:
    QVariant simplyAct(const QVariantList &args) final;

private:
    def::ActionDef actionDef() const final;
};

} // namespace math
} // namespace menu

#endif // MENU_MATH_INC_H
