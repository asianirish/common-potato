#ifndef TESTESSENCEB_H
#define TESTESSENCEB_H

#include <Essence.h>

using namespace hierhin::def;

class TestEssenceB : public hierhin::Essence
{
public:
    TestEssenceB();

    void execute(hierhin::Item *item) override;

    NodeDef nodeDef() const override;
};

#endif // TESTESSENCEB_H
