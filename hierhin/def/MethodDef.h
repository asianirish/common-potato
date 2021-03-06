#ifndef HIERHIN_DEF_COMMANDDEF_H
#define HIERHIN_DEF_COMMANDDEF_H

#include "PropertyDef.h"

#include <QString>

namespace hierhin {
namespace def {

typedef PropertyDef ArgDef;

class [[deprecated("use ActionDef instead")]] MethodDef
{
public:
    MethodDef();
    MethodDef(const QString &name, const QList<ArgDef> &argDefs = {});
    MethodDef(const QString &name, int argNum);

    const QString &name() const;
    void setName(const QString &newName);

    const QList<ArgDef> &argDefs() const;
    void setArgDefs(const QList<ArgDef> &newArgDefs);
    void addArgDef(const ArgDef argDef);

    QVariantList validate(const QVariantList &args);

private:
    QString _name;
    QList<ArgDef> _argDefs;

};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_COMMANDDEF_H
