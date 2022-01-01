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

    void launch(const QString &actionClassName, QVariantList &args);

    ContextSetter *contextSetter() const;
    void setContextSetter(ContextSetter *contextSetter);

protected:
    virtual void launchImpl(ActionPtr action, QVariantList &args) = 0;

signals:
    void ready(const Result &result);

private:
    ContextSetter *_contextSetter;
    QMap<QString, ActionPtr> _pendingActions;
    static util::LazyPointer<uniq::Value<QString>> _actionIdGen;

};

} // namespace menu

#endif // MENU_LAUNCHER_H
