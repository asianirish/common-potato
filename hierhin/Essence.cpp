#include "Essence.h"

namespace hierhin {



Essence::Essence() : QObject(nullptr)
{

}

//QString Essence::essenceClassName() const
//{
//    return this->metaObject()->className();
//}

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
