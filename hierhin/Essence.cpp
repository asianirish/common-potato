#include "Essence.h"
#include "Item.h"
#include <hierhin/ex/IncompatibleEssenceExecution.h>

namespace hierhin {



Essence::Essence() : QObject(nullptr)
{

}

void Essence::execute(Item *item) const
{
    if (className() == item->essenceClassName()) {
        executeImpl(item);
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


} // namespace hierhin
