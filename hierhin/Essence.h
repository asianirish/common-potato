#ifndef HIERHIN_ESSENCE_H
#define HIERHIN_ESSENCE_H

#include "def/NodeDef.h"

#include <menu/def/ActionDef.h>
#include <menu/ThreadLauncher.h>

#include <QObject>

namespace hierhin {

using namespace def;

class Item;

class Essence : public QObject
{
    Q_OBJECT
public:
    Essence();

    virtual ~Essence() = default;

    NodeDef nodeDef() const;

    QString className() const;

    QStringList classNames() const;

    bool isKindOf(const QString &className) const;

    //used in ESSENCE_CLASS_NAME
    static QString checkEssenceClass(const QString &essenceClassName) {
        return essenceClassName;
    }

//protected:
    virtual void nodeDef(NodeDef &nd) const;
    virtual QMap<Role, ItemReq> childRequirements() const;
    virtual QMap<QString, def::PropertyDef> propertyDefs() const;
    virtual QStringList methodNames() const;
    virtual ItemReq everyChildRequirement() const;

    virtual BaseType requiredBaseType() const;

signals:

};

#define ESSENCE_CLASS(className) className::checkEssenceClass(#className)

} // namespace hierhin

#endif // HIERHIN_ESSENCE_H
