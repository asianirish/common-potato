#ifndef MENU_DEF_ARGDEF_H
#define MENU_DEF_ARGDEF_H

#include <QVariant>

namespace menu {
namespace def {

class ArgDef
{
public:
    ArgDef();

    QVariant defaultValue() const;
    void setDefaultValue(const QVariant &defaultValue);

private:
    QVariant _defaultValue;
};

} // namespace def
} // namespace menu

#endif // MENU_DEF_ARGDEF_H
