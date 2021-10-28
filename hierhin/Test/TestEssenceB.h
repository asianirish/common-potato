#ifndef TESTESSENCEB_H
#define TESTESSENCEB_H

#include <Essence.h>

class TestEssenceB : public hierhin::Essence
{
public:
    TestEssenceB();

    void execute(hierhin::Item *item) override;
};

#endif // TESTESSENCEB_H
