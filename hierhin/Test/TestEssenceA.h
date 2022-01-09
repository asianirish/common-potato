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

protected:
    void nodeDef(NodeDef &nd) const override;
    QMap<hierhin::Role, ItemReq> childRequirements() const override;
    QMap<QString, PropertyDef> propertyDefs() const override;
    QMap<QString, MethodDef> methodDefs() const override;

private:
    Q_INVOKABLE void setElite(hierhin::Item *item);

};

#endif // TESTESSENCEA_H
