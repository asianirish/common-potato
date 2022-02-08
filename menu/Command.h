#ifndef MENU_COMMAND_H
#define MENU_COMMAND_H

#include "ContextSetter.h"

#include <QString>
#include <QSharedPointer>

namespace menu {

typedef QSharedPointer<ContextSetter> ContextSetterPtr;

class Command
{
public:
    Command();

    Command(const QString &actionClass, ContextSetterPtr contextSetter);

    const QString &actionClass() const;
    void setActionClass(const QString &newActionClass);

    ContextSetterPtr contextSetter() const;
    void setContextSetter(ContextSetterPtr newContexSetter);

private:
    QString _actionClass;
    ContextSetterPtr _contextSetter;
};

} // namespace menu

#endif // MENU_COMMAND_H
