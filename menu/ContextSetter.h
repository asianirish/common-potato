#ifndef MENU_CONTEXTSETTER_H
#define MENU_CONTEXTSETTER_H

#include "type.h"

namespace menu {

class ContextSetter
{
public:
    ContextSetter();

    virtual void setActionContext(Action *actionPtr) = 0;
};

} // namespace menu

#endif // MENU_CONTEXTSETTER_H
