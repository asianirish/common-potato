#include "Item.h"

namespace hierhin {

const QString Item::DEFAULT_ID_GEN_CLASS_NAME("uniq::TimeQStringValue");

util::LazyPointer<uniq::Value<QString>> Item::_idGen(Item::DEFAULT_ID_GEN_CLASS_NAME);

Item::Item()
{

}

QString Item::id() const
{
    if (_id.isEmpty()) {
        _id = _idGen->value();
    }
    return _id;
}

void Item::setId(const QString &id)
{
    if (_id.isEmpty()) {
        _id = id; //set once
    }
}

} // namespace hierhin
