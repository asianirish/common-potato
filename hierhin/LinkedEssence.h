#ifndef HIERHIN_DEF_LINKEDESSENCE_H
#define HIERHIN_DEF_LINKEDESSENCE_H

#include "Essence.h"
#include "nav/ItemRef.h"

#include <QObject>

namespace hierhin {
namespace def {

class LinkedEssence : public Essence
{
public:
    LinkedEssence();

protected:
    void executeImpl(Item *item, const QString &command, const QVariantList &args) const final;

    QMap<QString, def::MethodDef> commandDefs() const override;

    void linkItem(Item *item, const nav::ItemRef &iRef) const;

    virtual void executeLinkedEssence(Item *item, const QString &command, const QVariantList &args) const = 0;
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_LINKEDESSENCE_H
