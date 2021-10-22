#include "Item.h"
#include "Essence.h"

namespace hierhin {

const QString Item::DEFAULT_ID_GEN_CLASS_NAME("uniq::TimeQStringValue");
const QString Item::DEFAULT_ESSENCE_CLASS_NAME("hierhin::SimpleEssence");
const QString Item::ID_KEY("id");

util::LazyPointer<uniq::Value<QString>> Item::_idGen(Item::DEFAULT_ID_GEN_CLASS_NAME);

Item::Item() : _essence(DEFAULT_ESSENCE_CLASS_NAME)
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

void Item::setIdGenClassName(const QString &className)
{
    if (_idGen) {
        return;  //do not set if it already exists (ptr set)
    }

    _idGen.setClassName(className);
}

void Item::setEssenceClassName(const QString &className)
{
    if (_essence) {
        return; //do not set if it already exists
    }

    _essence.setClassName(className);
}

EssencePtr Item::essencePtr() const
{
    return _essence.ptr();
}

QVariantMap Item::toMap() const
{
    QVariantMap mp;
    mp.insert(ID_KEY, id());

    //TODO: implement
    toMapSpecific(mp);
    return mp;
}

} // namespace hierhin
