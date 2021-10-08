#include "Item.h"
#include "Node.h"

#include "ex/InvalidValueException.h"
#include "ex/NoSuchField.h"
#include "ex/ValidatorException.h"

namespace hi {

const QString Item::DEFAULT_ID_GEN_CLASS_NAME("uniq::TimeQStringValue");

const QString Item::CLASS_NAME_KEY("class");
const QString Item::ID_KEY("id");
const QString Item::FIELDS_KEY("fields");

util::LazyPointer<uniq::Value<QString>> Item::_idGen(Item::DEFAULT_ID_GEN_CLASS_NAME);

Item::Item(QObject *parent) : QObject(parent)
{

}

Node *Item::parentNode() const
{
    return qobject_cast<Node *>(parent());
}

QString Item::className() const
{
    return this->metaObject()->className();
}

void Item::setIdGenClassName(const QString &className)
{
    if (_idGen) {
        return;  //do not set if it already exists (ptr set)
    }

    _idGen.setClassName(className);
}

QVariant Item::field(const QString &name) const
{
    if (!_fields.contains(name)) {
        if (fieldDefs().contains(name)) { //TODO: isDefaultValue()?
            return fieldDefs().value(name).defaultValue();
        }

        throw ex::NoSuchField(name);
    }

    return _fields.value(name);
}

void Item::setField(const QString &name, const QVariant &value)
{
    if (!value.isValid()) {
        throw ex::InvalidValueException(name);
    }

    auto fieldDefs = this->fieldDefs();
    if (!fieldDefs.contains(name)) {
        throw ex::NoSuchField(name);
    }

    auto fieldDef = fieldDefs.value(name);
    auto validators = fieldDef.validators();

    for (auto &validator : validators) {
        if (!validator->validate(value)) {
            throw ex::ValidatorException(name, validator->errorMessage());
        }
    }

    _fields.insert(name, value);
}

ItemPtr Item::newItem(const QVariantMap &mp)
{
    QString className = mp.value(CLASS_NAME_KEY).toString();
    Item *ptr = util::Factory<Item>::create(className.toStdString());

    ptr->fromMap(mp);

    return ItemPtr(ptr);
}

NodePtr Item::newNode(const QVariantMap &mp)
{
    return newItem(mp).dynamicCast<Node>();
}

ItemPtr Item::cloneItem() const
{
    return newItem(this->toMap());
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

QVariantMap Item::toMap() const
{
    QVariantMap mp;
    mp.insert(CLASS_NAME_KEY, className());
    mp.insert(ID_KEY, id());

    if (!_fields.isEmpty()) {
        mp.insert(FIELDS_KEY, _fields);
    }

    nodeToMap(mp);

    toMapClassSpecific(mp);

    return mp;
}

void Item::fromMap(const QVariantMap &mp)
{
    QVariant idVar = mp.value(ID_KEY);
    setId(idVar.toString());

    QVariant fieldsVar = mp.value(FIELDS_KEY);
    QVariantMap fieldMap = fieldsVar.toMap();

    auto keys = fieldMap.keys();
    for (auto &key : keys) {
        setField(key, fieldMap.value(key));
    }

    //TODO: nodeFromMap

    //TODO: fromMapSpecific

}

} // namespace hi
