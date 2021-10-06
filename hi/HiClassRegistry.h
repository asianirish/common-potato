#ifndef HICLASSREGISTRY_H
#define HICLASSREGISTRY_H

#include <menu/ThisAppClassRegistry.h>

class HiClassRegistry : public menu::ThisAppClassRegistry
{
public:
    HiClassRegistry();

    void registerAllClasses() const override;
};

#endif // HICLASSREGISTRY_H
