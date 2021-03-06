#ifndef DEF_ACTIONDEF_H
#define DEF_ACTIONDEF_H

#include "../Error.h"
#include "ArgDef.h"

#include <QList>

namespace menu {
namespace def {

class ActionDef
{
public:
    static const int UNLIMITED_MAX = -1;
    ActionDef();

    bool isUnlimitedArgNum() const;

    int argMinNum() const;
    void setArgMinNum(int argMinNum);

    int argMaxNum() const;
    void setArgMaxNum(int argMaxNum);

    Error validate(const QVariantList &args) const;

    void addArgDef(const ArgDef &argDef);

    void insertArgDef(int index, const ArgDef &argDef);

    void addDefaultArgs(const QVariantList &args, QVariantList &outArgs) const;

    QString description() const;
    void setDescription(const QString &description);

    void toPositionalArguments(const QVariantMap &namedArgs, QVariantList &posArgs);

private:
    int _argMinNum;
    int _argMaxNum; //-1 means unlimited
    QMap<int, ArgDef> _argDefs;
    QString _description;

};

} // namespace def
} // namespace menu

#endif // DEF_ACTIONDEF_H
