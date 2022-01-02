#include "ThreadLauncher.h"
#include "ActionThread.h"

#include <QDebug>

namespace menu {

ThreadLauncher::ThreadLauncher()
{

}

void ThreadLauncher::launchImpl(ActionPtr action, const QVariantList &args, const QString &actionId)
{
    ActionThread *thread = new ActionThread();
    thread->setAction(action);
    thread->setArgs(args);
    thread->setTaskId(actionId);

    bool isValid = connect(thread, &ActionThread::ready, this, &ThreadLauncher::onActionComplete, Qt::QueuedConnection);
//    bool isValid = connect(action.get(), &Action::ready, this, &ThreadLauncher::onActionComplete, Qt::QueuedConnection);

    if (isValid) {
        qDebug() << "CONNECTION IS VALID";
    } else {
        qDebug() << "CONNECTION IS INVALID";
    }

    connect(thread, &ActionThread::finished, thread, &QObject::deleteLater);

    thread->start();
}

} // namespace menu
