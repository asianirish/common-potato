#ifndef MENU_MATH_SUM_H
#define MENU_MATH_SUM_H

#include <SimpleAction.h>

namespace menu {
namespace math {

//to test Fold
class Sum : public SimpleAction
{
public:
    Sum();

protected:
    QVariant simplyAct(const QVariantList &args, const menu::TaskId &taskId) final;

private:

    def::ActionDef actionDef() const final;
};

} // namespace math
} // namespace menu

#endif // MENU_MATH_SUM_H
