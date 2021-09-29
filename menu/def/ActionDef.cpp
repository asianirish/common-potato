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
    QVariantList localArgs;

    addDefaultArgs(args, localArgs);

    if (localArgs.size() < _argMinNum) {
        Error err;
        err.setCode(1); //TODO: const
        err.setDescription("arg number must be greater than or equal to");
        QVariantMap cntx;
        cntx.insert("number", _argMinNum);
        err.setContext(cntx);
        return err;
    }

    if (!isUnlimitedArgNum() && localArgs.size() > _argMaxNum) {
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

void ActionDef::addArgDef(const ArgDef &argDef)
{
    _argDefs.append(argDef);
}

void ActionDef::addDefaultArgs(const QVariantList &args, QVariantList &outArgs) const
{
    auto argIt = args.begin();

    for (auto &argDef : _argDefs) {
        if (argIt != args.end()) {
            outArgs.append(*argIt);
            ++argIt;
        } else {
            if (argDef.isDefaultValue()) {
                outArgs.append(argDef.defaultValue());
            }
        }
    }

    int diff = args.size() - outArgs.size();

    if (diff) {
        for (; argIt != args.end(); ++argIt) {
            outArgs.append(*argIt);
        }
    }


}

} // namespace def
} // namespace menu
