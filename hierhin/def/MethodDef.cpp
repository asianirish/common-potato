#include "MethodDef.h"

#include "ex/IncompatibleArgNumber.h"

namespace hierhin {
namespace def {

MethodDef::MethodDef() : MethodDef(QString())
{

}

MethodDef::MethodDef(const QString &name, const QList<ArgDef> &argDefs) :
    _name(name),
    _argDefs(argDefs)
{

}

MethodDef::MethodDef(const QString &name, int argNum) :
    _name(name)
{
    for (int i = 0; i < argNum; i++) {
        _argDefs.append(ArgDef());
    }
}

const QString &MethodDef::name() const
{
    return _name;
}

void MethodDef::setName(const QString &newName)
{
    _name = newName;
}

const QList<ArgDef> &MethodDef::argDefs() const
{
    return _argDefs;
}

void MethodDef::setArgDefs(const QList<ArgDef> &newArgDefs)
{
    _argDefs = newArgDefs;
}

void MethodDef::addArgDef(const ArgDef argDef)
{
    _argDefs.append(argDef);
}

QVariantList MethodDef::validate(const QVariantList &args)
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
