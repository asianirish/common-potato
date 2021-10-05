#ifndef MENU_THISAPPCLASSREGISTRY_H
#define MENU_THISAPPCLASSREGISTRY_H

#include <util/Factory.h>

namespace menu {

class ThisAppClassRegistry
{
public:
    ThisAppClassRegistry();

    virtual void registerAllClasses() const = 0;
};

} // namespace menu

#endif // MENU_THISAPPCLASSREGISTRY_H
