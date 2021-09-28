#include "ActionDef.h"

namespace menu {
namespace def {

ActionDef::ActionDef() : _argNum(1)
{

}

int ActionDef::argNum() const
{
    return _argNum;
}

void ActionDef::setArgNum(int argNum)
{
    _argNum = argNum;
}

bool ActionDef::isUnlimitedArgNum() const
{
    return (_argNum < 0);
}

} // namespace def
} // namespace menu
