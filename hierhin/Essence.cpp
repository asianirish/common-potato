#include "Essence.h"
#include "Item.h"
#include "ItemContextSetter.h"
#include "sys/GetName.h"
#include "sys/GetProperty.h"

namespace hierhin {

const QString Essence::DEFAULT_COMMAND("command");
menu::ThreadLauncher *Essence::_launcher = nullptr;

Essence::Essence() : QObject(nullptr)
{
    if (!_launcher) {
        _launcher = new menu::ThreadLauncher();
    }

    static bool yes = false;
    if (!yes) {
        REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, sys::GetName);
        REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, sys::GetProperty);
        yes = true;
    }
}

NodeDef Essence::nodeDef() const
{
    NodeDef nd;
    nodeDef(nd);

    auto chReq = childRequirements();
    nd.setChildRequirements(chReq);

    auto propDefs = propertyDefs();
    nd.setPropertyDefs(propDefs);

    //TODO: nd.setMethodNames();

    return nd;
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

QMap<Role, ItemReq> Essence::childRequirements() const
{
    return {};
}

QMap<QString, PropertyDef> Essence::propertyDefs() const
{
    PropertyDef nameDef;
    nameDef.setName("name");
    //TODO: nameDef.setType()?
    return {{"name", nameDef}};
}

QStringList Essence::methodNames() const
{
    return {"sys::GetName", "sys::GetProperty"};
}

} // namespace hierhin
