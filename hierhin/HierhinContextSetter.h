#ifndef HIERHINCONTEXTSETTER_H
#define HIERHINCONTEXTSETTER_H

#include <menu/ContextSetter.h>

class HierhinContextSetter : public menu::ContextSetter
{
public:
    HierhinContextSetter();

    void setActionContext(menu::Action *action) override;
};

#endif // HIERHINCONTEXTSETTER_H
