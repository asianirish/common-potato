#ifndef TESTESSENCEB_H
#define TESTESSENCEB_H

#include <Essence.h>

using namespace hierhin::def;

class TestEssenceB : public hierhin::Essence
{
    Q_OBJECT
public:
    TestEssenceB();

    void execute(hierhin::Item *item) const override;

    NodeDef nodeDef() const override;
};

#endif // TESTESSENCEB_H
