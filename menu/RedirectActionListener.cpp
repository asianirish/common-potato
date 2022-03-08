#include "RedirectActionListener.h"

namespace menu {

RedirectActionListener::RedirectActionListener(QObject *parent)
    : ActionListener{parent}
{

}

void RedirectActionListener::onReadyImpl(const Result &result)
{
    Q_UNUSED(result)
}

void RedirectActionListener::onErrorImpl(const Error &err)
{
    Q_UNUSED(err)
}

} // namespace menu
