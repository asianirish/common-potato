#include "Destructor.h"

namespace menu {

Destructor::Destructor(QCoreApplication *app, Menu *menu, Launcher *launcher) : util::Destructor(app),
    _menu(menu),
    _launcher(launcher)
{

}

void Destructor::cleanUp()
{
    delete _menu;
    delete _launcher;
}

} // namespace menu
