#include "SimpleAction.h"

namespace menu {

SimpleAction::SimpleAction()
{

}

Result SimpleAction::act(const QVariantList &args)
{
    auto result = simplyAct(args);
    emit ready(result);
    return result;
}

} // namespace menu
