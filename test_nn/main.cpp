#include "nn/NNClassRegistry.h"
#include "nn/Task.h"

#include <QCoreApplication>
#include <QSharedPointer>
#include <QTimer>
#include <QDebug>

QString useString(QString &str) {
    str = "HELLO";
    qDebug() << "STRING:" << str;
    return str;
}


using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    useString(QString());

    NNClassRegistry reg;
    reg.registerAllClasses();

    auto task = QSharedPointer<Task>(new Task());
    QObject::connect(task.get(), &Task::quit, &a, &QCoreApplication::quit);
    QTimer::singleShot(0, task.get(), SLOT(run()));

    return a.exec();
}
