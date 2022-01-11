#ifndef HIERHIN_DEF_LINKEDESSENCE_H
#define HIERHIN_DEF_LINKEDESSENCE_H

#include "Essence.h"
#include "nav/ItemRef.h"

#include <QObject>

namespace hierhin {

class LinkedEssence : public Essence
{
public:
    LinkedEssence();

protected:
    QStringList methodNames() const override;

    void linkItem(Item *item, const nav::ItemRef &iRef) const;
};

} // namespace hierhin

#endif // HIERHIN_DEF_LINKEDESSENCE_H
