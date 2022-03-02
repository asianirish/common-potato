#include "ActionListener.h"

namespace menu {

ActionListener::ActionListener(QObject *parent) : QObject(parent)
{

}

void menu::ActionListener::onReady(const menu::Result &result)
{
    onReadyImpl(result);
    emit handled();
}

void ActionListener::onError(const Error &error)
{
    onErrorImpl(error);
    emit handled();
}


}
