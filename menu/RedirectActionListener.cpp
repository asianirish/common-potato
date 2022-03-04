#include "RedirectActionListener.h"

namespace menu {

RedirectActionListener::RedirectActionListener(QObject *parent)
    : ActionListener{parent}
{

}

void RedirectActionListener::onReadyImpl(const Result &result)
{
    emit ready(result);
}

void RedirectActionListener::onErrorImpl(const Error &err)
{
    emit error(err);
}

} // namespace menu
