#include "Item.h"
#include "Essence.h"
#include "Node.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace hierhin {

const QString Item::DEFAULT_ID_GEN_CLASS_NAME("uniq::TimeQStringValue");
const QString Item::DEFAULT_ESSENCE_CLASS_NAME("hierhin::SimpleEssence");
const QString Item::ID_KEY("id");
const QString Item::ESSENCE_CLASS_KEY("essenceClass");
const QString Item::PROPERTIES_KEY("prop");
const QString Item::IS_NODE_KEY("isNode");

util::LazyPointer<uniq::Value<Id>> Item::_idGen(Item::DEFAULT_ID_GEN_CLASS_NAME);

Item::Item() : _essence(DEFAULT_ESSENCE_CLASS_NAME)
{

}

Id Item::id() const
{
    if (_id.isEmpty()) {
        _id = _idGen->value();
    }
    return _id;
}

void Item::setId(const Id &id)
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
    mp.insert(ESSENCE_CLASS_KEY, _essence.className());
    mp.insert(PROPERTIES_KEY, _properties);
    mp.insert(IS_NODE_KEY, isNode());

    //TODO: implement
    toMapNodeSpecific(mp);
    return mp;
}

QByteArray Item::toJson()
{
    QJsonObject jObj = QJsonObject::fromVariantMap(toMap());
    return QJsonDocument(jObj).toJson();
}

} // namespace hierhin
