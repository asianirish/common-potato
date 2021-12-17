#ifndef TESTESSENCEC_H
#define TESTESSENCEC_H

#include <Essence.h>

using namespace hierhin::def;

class TestEssenceC : public hierhin::Essence
{
public:
    TestEssenceC();

    NodeDef nodeDef() const override {
        return NodeDef();
    }

protected:
    void executeImpl(hierhin::Item *item) const override {
        Q_UNUSED(item)
    }
};

#endif // TESTESSENCEC_H
