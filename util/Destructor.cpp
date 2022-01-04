#include "Destructor.h"

namespace potato_util {

Destructor::Destructor(QCoreApplication *app)
    : QObject{app}
{
    connect(app, &QCoreApplication::aboutToQuit, this, &Destructor::onQuit);
}

void Destructor::onQuit()
{
    cleanUp();
}

} // namespace util
