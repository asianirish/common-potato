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
        err.setType(Error::ERROR_TYPE::ARG_NUM);
        err.setDescription("arg number must be greater than or equal to");
        QVariantMap cntx;
        cntx.insert("number", _argMinNum);
        err.setContext(cntx);
        return err;
    }

    if (!isUnlimitedArgNum() && localArgs.size() > _argMaxNum) {
        Error err;
        err.setCode(2); //TODO: const
        err.setType(Error::ERROR_TYPE::ARG_NUM);
        err.setDescription("arg number must be less than or equal to");
        QVariantMap cntx;
        cntx.insert("number", _argMaxNum);
        err.setContext(cntx);
        return err;
    }

    int index = 0;

    for (auto &arg : localArgs) {

        if (_argDefs.contains(index)) {
            ArgDef argDef = _argDefs.value(index);
            Error err = argDef.validate(arg);

            if (err) {
                return err;
            }

        }

        index++;
    }

    return Error();
}

void ActionDef::addArgDef(const ArgDef &argDef)
{
    _argDefs.insert(_argDefs.size(), argDef);
}

void ActionDef::addDefaultArgs(const QVariantList &args, QVariantList &outArgs) const
{
    outArgs = args;

    int last = args.size();
    int diff = _argMinNum - last;

    if (diff > 0) {
        for (int i = 0; i < diff; i++) {
            int index = last + i;
            if (!_argDefs.contains(index)) {
                break;
            }

            outArgs.append(_argDefs.value(index).defaultValue());
        }
    }

}

void ActionDef::addDefaultArgs(QVariantList &outArgs) const
{
    int index = 0;

    for (auto &arg : outArgs) {
        if (_argDefs.contains(index)) {
            //replace ALL INVALID values with default ones
            if (!arg.isValid()) {
                arg = _argDefs.value(index).defaultValue();
            }
        }

        index++;
    }
}

} // namespace def
} // namespace menu
