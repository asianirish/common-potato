#ifndef MENU_LINECOMMANDTRANSLATOR_H
#define MENU_LINECOMMANDTRANSLATOR_H

#include "CommandTranslator.h"

namespace menu {

class LineCommandTranslator : public CommandTranslator
{
public:
    LineCommandTranslator();

    CommandInfo translate(const QString &commandString) const override;
};

} // namespace menu

#endif // MENU_LINECOMMANDTRANSLATOR_H
