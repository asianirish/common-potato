#ifndef HIERHIN_ITEMACTION_H
#define HIERHIN_ITEMACTION_H

#include "Item.h"

#include <menu/SimpleAction.h>

namespace hierhin {

class Method : public menu::SimpleAction
{
public:
    Method();

    Item *item() const;
    void setItem(Item *item);

protected:
    QVariant simplyAct(const QVariantList &args) final;

private:
    Item *_item;

    virtual QVariant actImpl(const QVariantList &args, Item *item) = 0;
};

} // namespace hierhin

#endif // HIERHIN_ITEMACTION_H