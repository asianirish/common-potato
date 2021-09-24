#include "CommandInfo.h"

namespace menu {

CommandInfo::CommandInfo() : CommandInfo(QString(), QVariantList())
{

}

CommandInfo::CommandInfo(const QString &name, const QVariantList &args) : _name(name), _args(args)
{

}

QString CommandInfo::name() const
{
    return _name;
}

void CommandInfo::setName(const QString &name)
{
    _name = name;
}

QVariantList CommandInfo::args() const
{
    return _args;
}

void CommandInfo::setArgs(const QVariantList &args)
{
    _args = args;
}

} // namespace menu
