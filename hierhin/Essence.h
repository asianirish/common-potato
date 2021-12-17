#ifndef HIERHIN_ESSENCE_H
#define HIERHIN_ESSENCE_H

#include "def/NodeDef.h"
#include "def/CommandDef.h"

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

    void execute(Item *item, const QString &command = DEFAULT_COMMAND, const QVariantList &args = QVariantList()) const;

    virtual NodeDef nodeDef() const = 0;

    QString className() const;

    QStringList classNames() const;

    bool isKindOf(const QString &className) const;

protected:
    virtual void executeImpl(Item *item, const QString &command, const QVariantList &args) const = 0;

    virtual QMap<QString, def::CommandDef> commandDefs() const; //TODO: or inside def::EssenceDef

signals:

};

} // namespace hierhin

#endif // HIERHIN_ESSENCE_H
