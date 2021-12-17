#ifndef TESTESSENCEB_H
#define TESTESSENCEB_H

#include <Essence.h>

using namespace hierhin::def;

class TestEssenceB : public hierhin::Essence
{
    Q_OBJECT
public:
    TestEssenceB();

    NodeDef nodeDef() const override;

protected:
    void executeImpl(hierhin::Item *item, const QString &command, const QVariantList &args) const override;
};

#endif // TESTESSENCEB_H
