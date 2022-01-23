#include "Essence.h"
#include "Item.h"
#include "ItemContextSetter.h"
#include "sys/GetName.h"
#include "sys/GetProperty.h"
#include "sys/SetProperty.h"
#include "sys/GetClassName.h"
#include "sys/GetMethodNames.h"
#include "sys/GetClassNames.h"
#include "sys/GetChildren.h"
#include "sys/GetChildByRole.h"

namespace hierhin {

Essence::Essence() : QObject(nullptr)
{
    static bool yes = false;

    if (!yes) {
        REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, sys::GetName);
        REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, sys::GetProperty);
        REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, sys::SetProperty);
        REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, sys::GetClassName);
        REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, sys::GetMethodNames);
        REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, sys::GetClassNames);

        //Node actions
        REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, sys::GetChildren);
        REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, sys::GetChildByRole);

        yes = true;
    }
}

NodeDef Essence::nodeDef() const
{
    NodeDef nd;
    nodeDef(nd);

    auto bsTp = requiredBaseType();
    nd.setRequiredBaseType(bsTp);

    if (bsTp == BaseType::NODE) {
        auto chReq = childRequirements();
        nd.setChildRequirements(chReq);

        auto itemReq = everyChildRequirement();
        nd.setEveryChildRequirement(itemReq);
    }

    auto propDefs = propertyDefs();
    nd.setPropertyDefs(propDefs);

    auto mthNames = methodNames();
    nd.setMethodNames(mthNames);

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
    //"name" is not using as a child identifier now
    PropertyDef nameDef;
    nameDef.setName("name");
    //TODO: nameDef.setType()?
    return {{"name", nameDef}};
}

QStringList Essence::methodNames() const
{
    return {"sys::GetName",
        "sys::GetProperty",
        "sys::SetProperty",
        "sys::GetClassName",
        "sys::GetMethodNames",
        "sys::GetClassNames",
        "sys::GetChildren",
        "sys::GetChildByRole"
    };
}

ItemReq Essence::everyChildRequirement() const
{
    ItemReq req;
    req.setAlwaysValid(true);
    return req;
}

BaseType Essence::requiredBaseType() const
{
    return BaseType::NODE;
}

} // namespace hierhin
