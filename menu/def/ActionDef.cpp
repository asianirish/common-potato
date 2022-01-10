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
    //TODO: compare with MethodDef::validate
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

void ActionDef::insertArgDef(int index, const ArgDef &argDef)
{
    _argDefs.insert(index, argDef);
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

QString ActionDef::description() const
{
    return _description;
}

void ActionDef::setDescription(const QString &description)
{
    _description = description;
}

void ActionDef::toPositionalArguments(const QVariantMap &namedArgs, QVariantList &posArgs)
{
    for (int i = 0; i < _argMinNum; i++) {
        if (!_argDefs.contains(i)) {
            break; //all arg definitions should be defined for named args
        }

        auto argDef = _argDefs.value(i);

        if (!namedArgs.contains(argDef.name())) { //if no such a named arg
            if (argDef.isDefaultValue()) {
                posArgs.append(argDef.defaultValue()); //add a default value
            } else {
                break;
            }
        } else {
            posArgs.append(namedArgs.value(argDef.name()));
        }

    }
}


} // namespace def
} // namespace menu
