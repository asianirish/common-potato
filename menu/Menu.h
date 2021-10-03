#ifndef MENU_MENU_H
#define MENU_MENU_H

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

typedef QSharedPointer<Action> ActionPtr;

class Menu : public QObject
{
    Q_OBJECT
public:
    static const QString DEFAULT_TASK_ID_GENERATOR_CLASS_NAME;
    static const QString DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME;

    explicit Menu(QObject *parent=nullptr);

    explicit Menu(const QString &taskIdGenClassName,
                  const QString &commandTranslatorClassName,
                  QObject *parent=nullptr);

    void registerCommand(const QString &itemKey, ActionPtr action);

    static void setTaskIdGenClassName(const QString &className);

    static QString newTaskId();

    void exec(const QString &command);

    void addItem(const QString &command, ActionPtr action);

    QList<QString> itemKeys() const;

private:
    QMap<QString, ActionPtr> _items;
    static util::LazyPointer<uniq::Value<QString>> _taskIdGen;
    util::LazyPointer<menu::CommandTranslator> _commandTranslator;
    QSet<QString> _pendingTasks;

    void exec(const CommandInfo &commandInfo);

signals:
    void ready(const QVariant &result);
    void error(const Error &error);

public slots:
    void onTaskComplete(const Result &result);
};

} // namespace menu

#endif // MENU_MENU_H
