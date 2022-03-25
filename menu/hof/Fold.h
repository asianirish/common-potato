#ifndef MENU_HOF_FOLD_H
#define MENU_HOF_FOLD_H

#include "../SimpleAction.h"
#include "../Launcher.h"

namespace menu {
namespace hof {

class Fold : public SimpleAction
{
public:
    Fold();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:
    def::ActionDef actionDef() const override;
};

} // namespace hof
} // namespace menu

#endif // MENU_HOF_FOLD_H
