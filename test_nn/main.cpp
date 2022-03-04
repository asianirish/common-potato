#include "nn/NNClassRegistry.h"
#include "nn/Task.h"

#include <QCoreApplication>
#include <QSharedPointer>
#include <QTimer>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NNClassRegistry reg;
    reg.registerAllClasses();

    auto task = QSharedPointer<Task>(new Task());
    QObject::connect(task.get(), &Task::quit, &a, &QCoreApplication::quit);
    QTimer::singleShot(0, task.get(), SLOT(run()));

    return a.exec();
}
