#ifndef HIERHIN_ITEMCONTEXTSETTER_H
#define HIERHIN_ITEMCONTEXTSETTER_H

#include <menu/ContextSetter.h>

namespace hierhin {

class Item;

class ItemContextSetter : public menu::ContextSetter
{
public:
    ItemContextSetter();

    void setActionContext(menu::Action *action) override;

    Item *item() const;
    void setItem(Item *newItem);

private:
    Item *_item;
};

} // namespace hierhin

#endif // HIERHIN_ITEMCONTEXTSETTER_H
