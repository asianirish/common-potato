#include "ActionDef.h"

namespace menu {
namespace def {

ActionDef::ActionDef() : _argMinNum(0),
    _argMaxNum(UNLIMITED_MAX)
{

}

bool ActionDef::isUnlimitedArgNum() const
{
    return (_argMaxNum == UNLIMITED_MAX);
}

int ActionDef::argMinNum() const
{
    return _argMinNum;
}

void ActionDef::setArgMinNum(int argMinNum)
{
    _argMinNum = argMinNum;
}

int ActionDef::argMaxNum() const
{
    return _argMaxNum;
}

void ActionDef::setArgMaxNum(int argMaxNum)
{
    _argMaxNum = argMaxNum;
}

Error ActionDef::validate(const QVariantList &args) const
{

    if (args.size() < _argMinNum) {
        Error err;
        err.setCode(1); //TODO: const
        err.setDescription("arg number must be greater than or equal to");
        QVariantMap cntx;
        cntx.insert("number", _argMinNum);
        err.setContext(cntx);
        return err;
    }

    if (!isUnlimitedArgNum() && args.size() > _argMaxNum) {
        Error err;
        err.setCode(2); //TODO: const
        err.setDescription("arg number must be less than or equal to");
        QVariantMap cntx;
        cntx.insert("number", _argMaxNum);
        err.setContext(cntx);
        return err;
    }

    //TODO: validate every arg

    return Error();
}

} // namespace def
} // namespace menu
