#ifndef NNCLASSREGISTRY_H
#define NNCLASSREGISTRY_H

#include <menu/ThisAppClassRegistry.h>

class NNClassRegistry : public menu::ThisAppClassRegistry
{
public:
    NNClassRegistry();

    void registerAllClasses() const override;
};

#endif // NNCLASSREGISTRY_H
