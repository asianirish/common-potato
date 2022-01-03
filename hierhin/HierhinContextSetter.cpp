#include "HierhinContextSetter.h"

#include <menu/util/SetLanguage.h>
#include <menu/Action.h>

HierhinContextSetter::HierhinContextSetter()
{

}

void HierhinContextSetter::setActionContext(menu::Action *action)
{
    menu::util::SetLanguage *setLan = dynamic_cast<menu::util::SetLanguage *>(action);

    if (setLan) {
        setLan->setFiles(QStringList{"hierhin", "vallib", "menulib"});
    }
}
