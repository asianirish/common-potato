#ifndef MENU_CONTEXTSETTER_H
#define MENU_CONTEXTSETTER_H

#include "type.h"

namespace menu {

class ContextSetter
{
public:
    ContextSetter();

    virtual ~ContextSetter() = default;

    virtual void setActionContext(Action *action) = 0;
};

typedef QSharedPointer<ContextSetter> ContextSetterPtr;

} // namespace menu

#endif // MENU_CONTEXTSETTER_H
