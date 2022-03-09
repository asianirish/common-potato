#include "ActionListener.h"

namespace menu {

ActionListener::ActionListener(QObject *parent) : QObject(parent)
{

}

void menu::ActionListener::handleResult(const menu::Result &result)
{
    if (result.isError()) {
        onErrorImpl(result.error());
        //TODO: emit error(result.error()); ?
    } else {
        onReadyImpl(result);
        //TODO: emit ready(result); ?
    }
    emit handled(result);
}


}
