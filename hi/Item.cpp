#include "Item.h"
#include "Node.h"

namespace hi {

const QString Item::DEFAULT_ID_GEN_CLASS_NAME("uniq::TimeQStringValue");

util::LazyPointer<uniq::Value<QString>> Item::_idGen(Item::DEFAULT_ID_GEN_CLASS_NAME);

Item::Item(QObject *parent) : QObject(parent)
{

}

Node *Item::parentNode() const
{
    return qobject_cast<Node *>(parent());
}

QString Item::className()
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
    return _fields.value(name);
}

void Item::setField(const QString &name, const QVariant &value)
{
    _fields.insert(name, value);
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

} // namespace hi
