#ifndef MENU_MENU_H
#define MENU_MENU_H

#include "type.h"
#include "Action.h"
#include "CommandTranslator.h"

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
    static const QString DEFAULT_TASK_ID_GENERATOR_CLASS_NAME;
    static const QString DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME;

    explicit Menu(QObject *parent=nullptr);

//    explicit Menu(const QString &taskIdGenClassName,
//                  const QString &commandTranslatorClassName,
//                  QObject *parent=nullptr);

    void registerCommand(const QString &itemKey, ActionPtr action);
    void registerCommand(const QString &cmd, const QString actionClass);

    static void setTaskIdGenClassName(const QString &className);

    static QString newTaskId();

    void exec(const QString &command);

    [[deprecated]] void addItem(const QString &command, ActionPtr action);
    void addItem(const QString &command, const QString &actionClassName);

    QList<QString> itemKeys() const;

    Launcher *launcher() const;
    void setLauncher(Launcher *newLauncher);

private:
    [[deprecated]] QMap<QString, ActionPtr> _items;

    QMap<QString, QString> _commands;

    [[deprecated]] static potato_util::LazyPointer<uniq::Value<QString>> _taskIdGen;
    static potato_util::LazyPointer<menu::CommandTranslator> _commandTranslator;
    [[deprecated]] QSet<QString> _pendingTasks;

    Launcher *_launcher;

    void exec(const CommandInfo &commandInfo);

    void execAlt(const CommandInfo &commandInfo);

signals:
    void ready(const QVariant &result);
    void error(const menu::Error &error);

public slots:
    [[deprecated]] void onTaskComplete(const menu::Result &result);
    void onResult(const QVariant &value); //Launcher based
    //TODO: onError
};

} // namespace menu

#endif // MENU_MENU_H
