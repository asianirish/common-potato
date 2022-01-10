#ifndef HIERHIN_ESSENCE_H
#define HIERHIN_ESSENCE_H

#include "def/NodeDef.h"
#include "def/MethodDef.h" //TODO: delete this include
#include "menu/def/ActionDef.h"


#include <menu/ThreadLauncher.h>

#include <QObject>

namespace hierhin {

using namespace def;

class Item;

class Essence : public QObject
{
    Q_OBJECT
public:
    static const QString DEFAULT_COMMAND;

    Essence();

    virtual ~Essence() = default;

    NodeDef nodeDef() const;

    QString className() const;

    QStringList classNames() const;

    bool isKindOf(const QString &className) const;

protected:
    virtual void nodeDef(NodeDef &nd) const;
    virtual QMap<Role, ItemReq> childRequirements() const;
    virtual QMap<QString, def::PropertyDef> propertyDefs() const;
    virtual QMap<QString, def::MethodDef> methodDefs() const;
    virtual QStringList methodNames() const;

private:
    static menu::ThreadLauncher *_launcher; //TODO: where to delete _launcher?

signals:

};

} // namespace hierhin

#endif // HIERHIN_ESSENCE_H
