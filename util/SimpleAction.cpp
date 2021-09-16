#include "SimpleAction.h"

namespace util {

SimpleAction::SimpleAction()
{

}

void SimpleAction::act(const QVariantList &args)
{
    auto result = simplyAct(args);
    emit ready(result);
}

} // namespace util
