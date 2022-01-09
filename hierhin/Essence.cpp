#include "Essence.h"
#include "Item.h"
#include "ItemContextSetter.h"

#include <hierhin/ex/UnsupportedCommand.h>
#include <hierhin/ex/IncompatibleEssenceExecution.h>

namespace hierhin {

const QString Essence::DEFAULT_COMMAND("command");
menu::ThreadLauncher *Essence::_launcher = nullptr;

Essence::Essence() : QObject(nullptr)
{
    if (!_launcher) {
        _launcher = new menu::ThreadLauncher();
    }
}

void Essence::execute(Item *item, const QString &command, const QVariantList &args) const
{
    auto cmdDefs = methodDefs();

    if (!cmdDefs.contains(command)) {
        throw ex::UnsupportedCommand(command);
    }

    auto cmdDef = cmdDefs.value(command);
    auto validatedArgs = cmdDef.validate(args);

    if (className() == item->essenceClassName()) {
        auto launcher = item->launcher();

        ItemContextSetter cntx;
        cntx.setItem(item);

        //TODO: connect launcher
        launcher->launch(command, validatedArgs, &cntx);
    } else {
        throw ex::IncompatibleEssenceExecution(className(), item->essenceClassName());
    }
}

QString Essence::className() const
{
    return metaObject()->className();
}

QStringList Essence::classNames() const
{
    QStringList lst;
    const QMetaObject *mo = metaObject();

    while (mo) {
        lst.append(mo->className());
        mo = mo->superClass();
    }

    return lst;
}

bool Essence::isKindOf(const QString &className) const
{
    return classNames().contains(className);
}

void Essence::nodeDef(NodeDef &nd) const
{
    Q_UNUSED(nd)
}

QMap<QString, PropertyDef> Essence::propertyDefs() const
{
    PropertyDef nameDef;
    nameDef.setName("name");
    //TODO: nameDef.setType()?
    return {{"name", nameDef}};
}

QMap<QString, MethodDef> Essence::methodDefs() const
{
    return {{DEFAULT_COMMAND, MethodDef(DEFAULT_COMMAND)}};
}


} // namespace hierhin
