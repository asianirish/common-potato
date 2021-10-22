#ifndef HIERHIN_ITEM_H
#define HIERHIN_ITEM_H

#include <util/LazyPointer.h>
#include <uniq/Value.h>

#include <QString>
#include <QVariantMap>


using namespace util;

namespace hierhin {

class Essence;

typedef QSharedPointer<Essence> EssencePtr;

class Item;
typedef QSharedPointer<Item> ItemPtr;

class Node;
typedef QSharedPointer<Node> NodePtr;

class Item
{
public:
    static const QString DEFAULT_ID_GEN_CLASS_NAME;
    static const QString DEFAULT_ESSENCE_CLASS_NAME;
    static const QString ID_KEY;
    static const QString ESSENCE_CLASS_KEY;
    static const QString PROPERTIES_KEY;
    static const QString IS_NODE_KEY;

    enum NODE_IMPL {
        DIRECT_IMPL,
        ROOT_CONTAINS_ALL_IMPL,
        CHILDREN_OR_ID_IMPL
    };

    Item();

    QString id() const;
    void setId(const QString &id);

    static void setIdGenClassName(const QString &className);

    void setEssenceClassName(const QString &className);

    EssencePtr essencePtr() const;

    QVariantMap toMap() const;

    virtual bool isNode() const {
        return false;
    }

private:
    mutable QString _id;
    QVariantMap _properties;
    static util::LazyPointer<uniq::Value<QString>> _idGen;
    LazyPointer<Essence> _essence;

    virtual void toMapSpecific(QVariantMap &mp) const {
        Q_UNUSED(mp);
    }

    static ItemPtr create(NODE_IMPL nodeImpl);
};

} // namespace hierhin

#endif // HIERHIN_ITEM_H
