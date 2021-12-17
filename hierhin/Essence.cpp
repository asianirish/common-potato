#include "Essence.h"
#include "Item.h"
#include <hierhin/ex/IncompatibleEssenceExecution.h>

namespace hierhin {

const QString Essence::DEFAULT_COMMAND("command");

Essence::Essence() : QObject(nullptr)
{

}

void Essence::execute(Item *item, const QString &command, const QVariantList &args) const
{
    //TODO: supported commands and throw UnsupportedCommand
    if (className() == item->essenceClassName()) {
        executeImpl(item, command, args);
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

QMap<QString, CommandDef> Essence::commandDefs() const
{
    return {{DEFAULT_COMMAND, CommandDef(DEFAULT_COMMAND)}};
}


} // namespace hierhin
