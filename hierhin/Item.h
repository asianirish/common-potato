#ifndef HIERHIN_ITEM_H
#define HIERHIN_ITEM_H

#include "def/NodeDef.h"

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

typedef QString Id;

class Item
{
public:
    static const QString DEFAULT_ID_GEN_CLASS_NAME;
    static const QString DEFAULT_ESSENCE_CLASS_NAME;
    static const QString ID_KEY;
    static const QString ESSENCE_CLASS_KEY;
    static const QString PROPERTIES_KEY;
    static const QString IS_NODE_KEY;

    Item();

    Id id() const;
    void setId(const Id &id);

    static void setIdGenClassName(const QString &className);

    void setEssenceClassName(const QString &className);

    QVariantMap toMap() const;

    QByteArray toJson();

    virtual bool isNode() const {
        return false;
    }

    virtual Node *parentNode() const = 0;

    virtual void setParentNode(Node *parentNode) = 0;

    QVariant property(const QString &name) const;

    void setProperty(const QString &name, const QVariant &value);

    void execute();

    def::NodeDef definition() const;

private:
    mutable Id _id;
    QVariantMap _properties;
    static util::LazyPointer<uniq::Value<Id>> _idGen;
    QString _essenceClassName;

    virtual void toMapNodeSpecific(QVariantMap &mp) const {
        Q_UNUSED(mp);
    }

    EssencePtr essencePtr() const;
};

} // namespace hierhin

#endif // HIERHIN_ITEM_H
