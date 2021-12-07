#ifndef HIERHIN_ESSENCE_H
#define HIERHIN_ESSENCE_H

#include "def/NodeDef.h"

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

    virtual void execute(Item *item) = 0;

    virtual NodeDef nodeDef() const = 0;

    QStringList classNames() const;

    bool isKindOf(const QString &className) const;

private:

signals:

};

} // namespace hierhin

#endif // HIERHIN_ESSENCE_H
