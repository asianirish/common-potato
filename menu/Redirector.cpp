#include "Redirector.h"

namespace menu {

Redirector::Redirector(QObject *parent)
    : ActionListener{parent}
{

}

void Redirector::onReadyImpl(const Result &result)
{
    Q_UNUSED(result)
}

void Redirector::onErrorImpl(const Error &err)
{
    Q_UNUSED(err)
}

} // namespace menu
