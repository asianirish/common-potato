#ifndef TESTESSENCEA_H
#define TESTESSENCEA_H

#include <LinkableEssence.h>
#include <def/MethodDef.h>

using namespace hierhin;
using namespace hierhin::def;

class TestEssenceA : public hierhin::LinkableEssence
{
    Q_OBJECT
public:
    TestEssenceA();

protected:
    void nodeDef(NodeDef &nd) const override;
//    QMap<hierhin::Role, ItemReq> childRequirements() const override;
    QMap<QString, PropertyDef> propertyDefs() const override;
    QStringList methodNames() const override;

private:
//    QList<std::pair<Role, QString> > linkRoles() const;
    QMap<Role, ItemReq> nonLinkChildRequirements() const override;

};

#endif // TESTESSENCEA_H
