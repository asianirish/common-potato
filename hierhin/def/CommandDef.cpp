#include "CommandDef.h"

#include "ex/IncompatibleArgNumber.h"

namespace hierhin {
namespace def {

CommandDef::CommandDef() : CommandDef(QString())
{

}

CommandDef::CommandDef(const QString &name, const QList<ArgDef> &argDefs) :
    _name(name),
    _argDefs(argDefs)
{

}

const QString &CommandDef::name() const
{
    return _name;
}

void CommandDef::setName(const QString &newName)
{
    _name = newName;
}

const QList<ArgDef> &CommandDef::argDefs() const
{
    return _argDefs;
}

void CommandDef::setArgDefs(const QList<ArgDef> &newArgDefs)
{
    _argDefs = newArgDefs;
}

void CommandDef::addArgDef(const ArgDef argDef)
{
    _argDefs.append(argDef);
}

QVariantList CommandDef::validate(const QVariantList &args)
{
    int argsSz = args.size();
    int argDefSz = _argDefs.size();
    int mandatoryArgDefNum = 0;

    for (auto &argDef : _argDefs) {
        if (argDef.defaultValue().isValid()) { //Do not count definitions with a default value
            break;
        }

        mandatoryArgDefNum++;
    }

    QVariantList retArgs;

    if (argsSz != mandatoryArgDefNum) {
        throw ex::IncompatibleArgNumber(argsSz, mandatoryArgDefNum);
    }

    for (int i = 0; i < argDefSz; i++) {
        auto def = _argDefs.at(i);
        if (i >= argsSz) {
            retArgs.append(def.defaultValue());
        } else {
            retArgs.append(args.at(i));
        }
    }

    return retArgs;
}

} // namespace def
} // namespace hierhin
