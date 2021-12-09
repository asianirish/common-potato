#include "Item.h"
#include "Essence.h"
#include "Node.h"

#include <util/SingletonRegistry.h>

#include <QJsonDocument>
#include <QJsonObject>

namespace hierhin {

const QString Item::DEFAULT_ID_GEN_CLASS_NAME("uniq::TimeQStringValue");
//const QString Item::DEFAULT_ESSENCE_CLASS_NAME("hierhin::SimpleEssence");
const QString Item::ID_KEY("id");
const QString Item::ESSENCE_CLASS_KEY("essenceClass");
const QString Item::PROPERTIES_KEY("prop");
const QString Item::IS_NODE_KEY("isNode");

util::LazyPointer<uniq::Value<Id>> Item::_idGen(Item::DEFAULT_ID_GEN_CLASS_NAME);

Item::Item()
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
    if (_essenceClassName.isEmpty()) {
        _essenceClassName = className;
    }
}

EssencePtr Item::essencePtr() const
{
    return util::SingletonRegistry<hierhin::Essence>::ptr(_essenceClassName);
}

QVariantMap Item::toMap() const
{
    QVariantMap mp;
    mp.insert(ID_KEY, id());

    if (!_essenceClassName.isEmpty()) {
        mp.insert(ESSENCE_CLASS_KEY, _essenceClassName);
    }

    if (!_properties.isEmpty()) {
        mp.insert(PROPERTIES_KEY, _properties);
    }

    mp.insert(IS_NODE_KEY, isNode());

    //TODO: implement
    nodeToMap(mp);
    return mp;
}

QByteArray Item::toJson()
{
    QJsonObject jObj = QJsonObject::fromVariantMap(toMap());
    return QJsonDocument(jObj).toJson();
}

QVariant Item::property(const QString &name) const
{
    return _properties.value(name);
}

void Item::setProperty(const QString &name, const QVariant &value)
{
    auto def = definition();

    if (!def) { //no constraints
        _properties.insert(name, value);
    } else {

        def.validateProperty(name, value);

        _properties.insert(name, value);
    }
}

void Item::execute()
{
    auto ptr = essencePtr();

    if (ptr) {
        ptr->execute(this);
    }
}

NodeDef Item::definition() const
{
    EssencePtr essPtr = essencePtr();

    if (essPtr) {
        return essPtr->nodeDef();
    }

    return {};
}

QString Item::essenceClassName() const
{
    return essencePtr()->className();
}

QStringList Item::essenceClassNames() const
{
    EssencePtr essPtr = essencePtr();

    if (essPtr) {
        return essPtr->classNames();
    }

    return {};
}

bool Item::isKindOf(const QString &className) const
{
    EssencePtr essPtr = essencePtr();

    if (essPtr) {
        return essPtr->isKindOf(className);
    }

    return false;
}

} // namespace hierhin
