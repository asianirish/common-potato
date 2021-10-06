#ifndef HI_ITEM_H
#define HI_ITEM_H

#include "FieldDef.h"

#include <util/LazyPointer.h>
#include <uniq/Value.h>

#include <QObject>
#include <QVariantMap>
#include <QSharedPointer>

namespace hi {

class Item;

typedef QSharedPointer<Item> ItemPtr;

class Node;

class Item : public QObject
{
    Q_OBJECT
public:
    static const QString DEFAULT_ID_GEN_CLASS_NAME;
    static const QString CLASS_NAME_KEY;
    static const QString ID_KEY;
    static const QString FIELDS_KEY;


    explicit Item(QObject *parent = nullptr);

    Node *parentNode() const;

    QString className() const;

    static void setIdGenClassName(const QString &className);

    QString id() const;
    void setId(const QString &id);

    //TODO: ItemDef

    QVariantMap toMap() const;
    void fromMap(const QVariantMap &mp);

    QVariant field(const QString &name) const;

    void setField(const QString &name, const QVariant &value);

    static ItemPtr newItem(const QVariantMap &mp);

    ItemPtr clone() const;

private:
    mutable QString _id;
    QVariantMap _fields;
    static util::LazyPointer<uniq::Value<QString>> _idGen;

    virtual void nodeToMap(QVariantMap &mp) const {
        Q_UNUSED(mp);
    }

    virtual void toMapClassSpecific(QVariantMap &mp) const {
        Q_UNUSED(mp);
    }

    virtual QMap<QString, FieldDef> fieldDefs() const = 0;

signals:

};

} // namespace hi

#endif // HI_ITEM_H
