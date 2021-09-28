#ifndef DEF_ACTIONDEF_H
#define DEF_ACTIONDEF_H

#include "../Error.h"

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

private:
    int _argMinNum;
    int _argMaxNum; //-1 means unlimited
//TODO:    QList<ArgDef> _argDefs;
};

} // namespace def
} // namespace menu

#endif // DEF_ACTIONDEF_H
