#include "Essence.h"

namespace hierhin {

Essence::Essence() : Essence(nullptr, nullptr)
{

}

Essence::Essence(Item *item, QObject *parent) : QObject(parent),
    _item(item)
{

}

Item *Essence::item() const
{
    return _item;
}

void Essence::setItem(Item *item)
{
    _item = item;
}

} // namespace hierhin
