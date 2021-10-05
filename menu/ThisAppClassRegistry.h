#ifndef MENU_THISAPPCLASSREGISTRY_H
#define MENU_THISAPPCLASSREGISTRY_H


namespace menu {

class ThisAppClassRegistry
{
public:
    ThisAppClassRegistry();

    virtual void registerAllClasses() = 0;
};

} // namespace menu

#endif // MENU_THISAPPCLASSREGISTRY_H
