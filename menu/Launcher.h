#ifndef MENU_LAUNCHER_H
#define MENU_LAUNCHER_H

#include "Result.h"
#include "type.h"

#include <QObject>

namespace menu {

class ContextSetter;

class Launcher : public QObject
{
    Q_OBJECT
public:
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

};

} // namespace menu

#endif // MENU_LAUNCHER_H
