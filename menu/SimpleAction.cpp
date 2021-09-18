#include "SimpleAction.h"

namespace menu {

SimpleAction::SimpleAction()
{

}

void SimpleAction::act(const QVariantList &args)
{
    auto result = simplyAct(args);
    emit ready(result);
}

} // namespace menu
