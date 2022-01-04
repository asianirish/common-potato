#ifndef MENU_DESTRUCTOR_H
#define MENU_DESTRUCTOR_H

#include "Menu.h"
#include "Launcher.h"

#include <util/Destructor.h>

namespace menu {

class Destructor : public potato_util::Destructor
{
    Q_OBJECT
public:
    Destructor(QCoreApplication *app, Menu *menu, Launcher *launcher);

    void cleanUp() override;

private:
    Menu *_menu;
    Launcher *_launcher;
};

} // namespace menu

#endif // MENU_DESTRUCTOR_H
