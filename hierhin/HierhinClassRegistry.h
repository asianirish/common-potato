#ifndef HIERHINCLASSREGISTRY_H
#define HIERHINCLASSREGISTRY_H

#include <menu/ThisAppClassRegistry.h>

class HierhinClassRegistry : public menu::ThisAppClassRegistry
{
public:
    HierhinClassRegistry();

    void registerAllClasses() const override;
};

#endif // HIERHINCLASSREGISTRY_H
