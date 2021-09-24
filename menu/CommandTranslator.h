#ifndef MENU_COMMANDTRANSLATOR_H
#define MENU_COMMANDTRANSLATOR_H

#include "CommandInfo.h"

namespace menu {

class CommandTranslator
{
public:
    CommandTranslator();

    virtual CommandInfo translate(const QString &commandString) const = 0;
};

} // namespace menu

#endif // MENU_COMMANDTRANSLATOR_H
