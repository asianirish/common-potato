#ifndef HIERHIN_IMPLCREATOR_H
#define HIERHIN_IMPLCREATOR_H

#include <type.h>

namespace hierhin {

class ImplCreator
{
public:
    ImplCreator();

    ItemPtr createItem(const BaseType &baseType);

    virtual ItemPtr createItem() = 0;
    virtual NodePtr createNode() = 0;
//TODO:    virtual LinkPtr createLink() = 0;

};

} // namespace hierhin

#endif // HIERHIN_IMPLCREATOR_H
