#ifndef MENU_JSONCOMMANDTRANSLATOR_H
#define MENU_JSONCOMMANDTRANSLATOR_H

#include "CommandTranslator.h"

namespace menu {

//TODO: implement
//TODO: use named args
class JsonCommandTranslator : public CommandTranslator
{
public:
    static const QString ACTION_JSON_KEY;
    static const QString ARGS_JSON_KEY;
    JsonCommandTranslator();

    CommandInfo translate(const QString &commandString) const override;
};

} // namespace menu

#endif // MENU_JSONCOMMANDTRANSLATOR_H
