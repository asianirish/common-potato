#ifndef TESTESSENCEB_H
#define TESTESSENCEB_H

#include <LinkableEssence.h>

using namespace hierhin::def;

class TestEssenceB : public hierhin::LinkableEssence
{
    Q_OBJECT
public:
    TestEssenceB();

protected:
    QMap<QString, PropertyDef> propertyDefs() const override;

};

#endif // TESTESSENCEB_H
