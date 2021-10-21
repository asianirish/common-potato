#include "Essence.h"

namespace hierhin {

Essence::Essence(Item *item, QObject *parent) : QObject(parent),
    _item(item)
{

}

} // namespace hierhin
