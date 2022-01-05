#ifndef HIERHIN_ITEMCONTEXTSETTER_H
#define HIERHIN_ITEMCONTEXTSETTER_H

#include <menu/ContextSetter.h>

namespace hierhin {

class ItemContextSetter : public menu::ContextSetter
{
public:
    ItemContextSetter();

    void setActionContext(menu::Action *action) override;
};

} // namespace hierhin

#endif // HIERHIN_ITEMCONTEXTSETTER_H
