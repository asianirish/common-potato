#ifndef HIERHIN_IMPLCREATOR_H
#define HIERHIN_IMPLCREATOR_H

#include <type.h>

namespace hierhin {

class ItemCreator
{
public:
    ItemCreator();

    virtual ~ItemCreator() = default;

    ItemPtr createItem(const QVariantMap &mp) const;

private:
    virtual ItemPtr createItem() const = 0;
    virtual NodePtr createNode() const = 0;

    ItemPtr createItem(const BaseType &baseType) const;

};

} // namespace hierhin

#endif // HIERHIN_IMPLCREATOR_H
