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

    void addDefaultArgs(const QVariantList &args, QVariantList &outArgs) const;

private:
    int _argMinNum;
    int _argMaxNum; //-1 means unlimited
    QMap<int, ArgDef> _argDefs;

    void addDefaultArgs(QVariantList &outArgs) const; //TODO: for future use (for named args)
};

} // namespace def
} // namespace menu

#endif // DEF_ACTIONDEF_H
