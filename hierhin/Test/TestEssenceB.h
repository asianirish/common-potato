#ifndef TESTESSENCEB_H
#define TESTESSENCEB_H

#include <Essence.h>
#include <LinkedEssence.h>

using namespace hierhin::def;

class TestEssenceB : public hierhin::LinkedEssence
{
    Q_OBJECT
public:
    TestEssenceB();

protected:
    QMap<QString, PropertyDef> propertyDefs() const override;

};

#endif // TESTESSENCEB_H
