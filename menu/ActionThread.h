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

    Action *action() const;
    void setAction(Action *action);

    QVariantList args() const;
    void setArgs(const QVariantList &args);

    TaskId taskId() const;
    void setTaskId(const TaskId &taskId);

private:
    Action *_action;
    QVariantList _args;
    TaskId _taskId;

signals:
    void ready(const menu::Result &result);

private slots:
    void onTestReady(const Result &result); //TODO: fully-qualified
};

} // namespace menu


#endif // ACTIONTHREAD_H
