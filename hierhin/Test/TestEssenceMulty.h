#ifndef TESTESSENCEMULTY_H
#define TESTESSENCEMULTY_H

#include <LinkableEssence.h>
#include <def/MethodDef.h>

using namespace hierhin;
using namespace hierhin::def;

class TestEssenceMulty : public hierhin::LinkableEssence
{
    //essence classes MUST contain Q_OBJECT in this version (because of metaObject()->className())
    Q_OBJECT
public:
    TestEssenceMulty();

protected:
    void nodeDef(NodeDef &nd) const override;
    QMap<QString, PropertyDef> propertyDefs() const override;

private:
    QMap<Role, ItemReq> nonLinkChildRequirements() const override;
};

#endif // TESTESSENCEMULTY_H
