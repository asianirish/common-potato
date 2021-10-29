#ifndef TESTESSENCEA_H
#define TESTESSENCEA_H

#include <Essence.h>

using namespace hierhin::def;

class TestEssenceA : public hierhin::Essence
{
public:
    TestEssenceA();

    void execute(hierhin::Item *item) override;

    NodeDef nodeDef() const override;
};

#endif // TESTESSENCEA_H
