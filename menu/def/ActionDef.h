#ifndef DEF_ACTIONDEF_H
#define DEF_ACTIONDEF_H

#include <QList>

namespace menu {
namespace def {

class ActionDef
{
public:
    ActionDef();

    int argNum() const;
    void setArgNum(int argNum);

    bool isUnlimitedArgNum() const;

private:
    int _argNum; //-1 means unlimited
//TODO:    QList<ArgDef> _argDefs;
};

} // namespace def
} // namespace menu

#endif // DEF_ACTIONDEF_H
