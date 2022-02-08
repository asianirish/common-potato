#ifndef MENU_MENU_H
#define MENU_MENU_H

#include "type.h"
#include "Action.h"
#include "CommandTranslator.h"
#include "Command.h"

#include <uniq/Value.h>
#include <util/LazyPointer.h>

#include <QObject>
#include <QMap>
#include <QString>
#include <QSharedPointer>
#include <QSet>

namespace menu {

class Launcher;

class Menu : public QObject
{
    Q_OBJECT
public:
    static const QString DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME;

    explicit Menu(QObject *parent=nullptr);

//    explicit Menu(const QString &taskIdGenClassName,
//                  const QString &commandTranslatorClassName,
//                  QObject *parent=nullptr);

    //TODO: use instead of addItem
    void registerCommand(const QString &cmd, const QString actionClass, ContextSetterPtr cntx = {});

    void exec(const QString &command);

    [[deprecated]] void addItem(const QString &command, const QString &actionClassName);

    QList<QString> itemKeys() const;

    Launcher *launcher() const;
    void setLauncher(Launcher *newLauncher);

    ContextSetter *contextSetter() const;
    void setContextSetter(ContextSetter *contextSetter);

private:
    [[deprecated]] QMap<QString, QString> _commandsOld;
    QMap<QString, Command> _commands;

    ContextSetter *_contextSetter;
    Launcher *_launcher;

    static potato_util::LazyPointer<menu::CommandTranslator> _commandTranslator;

    [[deprecated]] void execOld(const CommandInfo &commandInfo);
    void exec(const CommandInfo &commandInfo);

signals:
    void ready(const QVariant &result, const menu::TaskId &taskId);
    void error(const menu::Error &error);

public slots:
    void onResult(const QVariant &value, const menu::TaskId &taskId); //Launcher based
    //TODO: onError
};

} // namespace menu

#endif // MENU_MENU_H
