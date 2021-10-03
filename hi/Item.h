#ifndef HI_ITEM_H
#define HI_ITEM_H

#include <util/LazyPointer.h>
#include <uniq/Value.h>

#include <QObject>
#include <QVariantMap>

namespace hi {

class Node;

class Item : public QObject
{
    Q_OBJECT
public:
    static const QString DEFAULT_ID_GEN_CLASS_NAME;

    explicit Item(QObject *parent = nullptr);

    virtual QString alias() const = 0;

    //TODO: parent node

    static void setIdGenClassName(const QString &className);

    QString id() const;
    void setId(const QString &id);

    //TODO: ItemDef

    //TODO: toMap and fromMap

    QVariant field(const QString &name) const;

    void setField(const QString &name, const QVariant &value);

signals:

private:
    mutable QString _id;
    QVariantMap _fields;
    static util::LazyPointer<uniq::Value<QString>> _idGen;

};

} // namespace hi

#endif // HI_ITEM_H
