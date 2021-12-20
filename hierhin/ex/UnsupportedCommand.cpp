#include "UnsupportedCommand.h"

namespace hierhin {
namespace ex {

UnsupportedCommand::UnsupportedCommand() : UnsupportedCommand(QString())
{

}

UnsupportedCommand::UnsupportedCommand(const QString &command) : _command(command)
{

}

const QString &UnsupportedCommand::command() const
{
    return _command;
}

void UnsupportedCommand::setCommand(const QString &newCommand)
{
    _command = newCommand;
}

} // namespace ex
} // namespace hierhin
