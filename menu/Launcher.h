#ifndef MENU_LAUNCHER_H
#define MENU_LAUNCHER_H

#include "Result.h"
#include "type.h"

#include <util/LazyPointer.h>
#include <uniq/Value.h>

#include <QObject>

namespace menu {

class ContextSetter;

class Launcher : public QObject
{
    Q_OBJECT
public:
    static const QString DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME;

    explicit Launcher(QObject *parent = nullptr);

    void launch(const QString &actionClassName, const QVariantList &args);

    ContextSetter *contextSetter() const;
    void setContextSetter(ContextSetter *contextSetter);

    static void setActionIdGenClassName(const QString &className);

protected:
    virtual void launchImpl(ActionPtr action, const QVariantList &args, const QString &actionId) = 0;

private:
    ContextSetter *_contextSetter;
    QMap<QString, ActionPtr> _pendingActions;
    static util::LazyPointer<uniq::Value<QString>> _actionIdGen;

signals:
    void ready(const QVariant &result);
    void error(const Error &error);

protected:
    void onActionComplete(const Result &result);

};

} // namespace menu

#endif // MENU_LAUNCHER_H
