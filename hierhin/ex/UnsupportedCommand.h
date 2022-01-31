#ifndef HIERHIN_EX_UNSUPPORTEDCOMMAND_H
#define HIERHIN_EX_UNSUPPORTEDCOMMAND_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class UnsupportedCommand : public Exception
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    UnsupportedCommand();
    UnsupportedCommand(const QString &command);

    const QString &command() const;
    void setCommand(const QString &newCommand);

    QString cause() const override {
        return tr("Unsupported command: %1").arg(_command);
    }
private:
    QString _command;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_UNSUPPORTEDCOMMAND_H
