#ifndef HI_ITEM_H
#define HI_ITEM_H

#include <QObject>
#include <QVariantMap>

namespace hi {

class Node;

class Item : public QObject
{
    Q_OBJECT
public:
    explicit Item(QObject *parent = nullptr);

    //TODO: parent node

    //TODO: uniq id generator

    //TODO: ItemDef

    //TODO: toMap and fromMap

    QVariant field(const QString &name) const;

    void setField(const QString &name, const QVariant &value);

signals:

private:
    QString _id;
    QVariantMap _fields;

};

} // namespace hi

#endif // HI_ITEM_H
