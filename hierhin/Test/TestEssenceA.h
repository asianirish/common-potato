#ifndef TESTESSENCEA_H
#define TESTESSENCEA_H

#include <Essence.h>
#include <def/CommandDef.h>

using namespace hierhin::def;

class TestEssenceA : public hierhin::Essence
{
    Q_OBJECT
public:
    TestEssenceA();

    NodeDef nodeDef() const override;

protected:
    void executeImpl(hierhin::Item *item, const QString &command, const QVariantList &args) const override;

    QMap<QString, CommandDef> commandDefs() const override;

};

#endif // TESTESSENCEA_H
