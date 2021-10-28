#ifndef TESTESSENCEA_H
#define TESTESSENCEA_H

#include <Essence.h>

class TestEssenceA : public hierhin::Essence
{
public:
    TestEssenceA();

    void execute(hierhin::Item *item) override;
};

#endif // TESTESSENCEA_H
