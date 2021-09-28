#include "Action.h"

namespace menu {

Action::Action(QObject *parent) : QObject(parent)
{

}

void Action::addDef(const def::ActionDef &actionDef)
{
    _defs.append(actionDef);

}

} // namespace menu
