#ifndef ACTIONTHREAD_H
#define ACTIONTHREAD_H

#include "type.h"
#include "Action.h"

#include <QThread>

namespace menu {

class ActionThread : public QThread
{
    Q_OBJECT
public:
    ActionThread();

    void run() override;

    ActionPtr action() const;
    void setAction(const ActionPtr &action);

    QVariantList args() const;
    void setArgs(const QVariantList &args);

    QString taskId() const;
    void setTaskId(const QString &taskId);

private:
    ActionPtr _action;
    QVariantList _args;
    QString _taskId;

signals:
    void ready(const menu::Result &result);

private slots:
    void onTestReady(const Result &result);
};

} // namespace menu


#endif // ACTIONTHREAD_H
