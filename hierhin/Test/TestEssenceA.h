#ifndef TESTESSENCEA_H
#define TESTESSENCEA_H

#include <Essence.h>
#include <def/MethodDef.h>

using namespace hierhin::def;

class TestEssenceA : public hierhin::Essence
{
    Q_OBJECT
public:
    TestEssenceA();

    NodeDef nodeDef() const override;

    void testInvoke(hierhin::Item *item);

protected:
    QMap<QString, MethodDef> commandDefs() const override;

private:
    Q_INVOKABLE void setElite(hierhin::Item *item);

};

#endif // TESTESSENCEA_H
