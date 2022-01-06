#ifndef MENU_LAUNCHER_H
#define MENU_LAUNCHER_H

#include "Result.h"
#include "type.h"

#include <util/LazyPointer.h>
#include <uniq/Value.h>

#include <QObject>

namespace menu {

class ContextSetter;

//TODO: make ActionListener (?)
class Launcher : public QObject
{
    Q_OBJECT
public:
    static const QString DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME;

    explicit Launcher(QObject *parent = nullptr);

    void launch(const QString &actionClassName, const QVariantList &args, ContextSetter *cnxtSetter);
    void launch(const QString &actionClassName, const QVariantMap &namedArgs, ContextSetter *cnxtSetter);

    static void setActionIdGenClassName(const QString &className);

protected:
    virtual void launchImpl(Action *action, const QVariantList &args, const QString &actionId) = 0;

private:
    QMap<QString, Action *> _pendingActions;
    static potato_util::LazyPointer<uniq::Value<QString>> _actionIdGen;

    QString initAction(const QString &actionClassName, ContextSetter *cnxtSetter);

signals:
    void ready(const QVariant &result);
    void error(const menu::Error &error);

protected:
    void onActionComplete(const menu::Result &result);

};

} // namespace menu

#endif // MENU_LAUNCHER_H
