#ifndef HIERHINDESTRUCTOR_H
#define HIERHINDESTRUCTOR_H



#include <util/Destructor.h>
#include <menu/Menu.h>
#include <menu/Launcher.h>

class HierhinDestructor : public AppDestructor
{
public:
    HierhinDestructor(QCoreApplication *app, menu::Menu *menu, menu::Launcher *launcher);

    ~HierhinDestructor();

protected:
    void cleanUp() override;

private:
    menu::Menu *_menu;
    menu::Launcher *_launcher;
};

#endif // HIERHINDESTRUCTOR_H
