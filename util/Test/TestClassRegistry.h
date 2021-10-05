#ifndef TESTCLASSREGISTRY_H
#define TESTCLASSREGISTRY_H

#include <menu/ThisAppClassRegistry.h>

class TestClassRegistry : public menu::ThisAppClassRegistry
{
public:
    TestClassRegistry();

    void registerAllClasses() const override;
};

#endif // TESTCLASSREGISTRY_H
