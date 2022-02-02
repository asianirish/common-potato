#ifndef MENU_MENU_H
#define MENU_MENU_H

#include "type.h"
#include "Action.h"
#include "CommandTranslator.h"
#include "ContextSetter.h"

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

    void registerCommand(const QString &cmd, const QString actionClass);

    void exec(const QString &command);

    void addItem(const QString &command, const QString &actionClassName);

    QList<QString> itemKeys() const;

    Launcher *launcher() const;
    void setLauncher(Launcher *newLauncher);

    ContextSetter *contextSetter() const;
    void setContextSetter(ContextSetter *contextSetter);

private:
    QMap<QString, QString> _commands;
    ContextSetter *_contextSetter;
    Launcher *_launcher;

    static potato_util::LazyPointer<menu::CommandTranslator> _commandTranslator;

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
