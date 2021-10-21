#ifndef HIERHIN_ITEM_H
#define HIERHIN_ITEM_H

#include <util/LazyPointer.h>
#include <uniq/Value.h>

#include <QString>
#include <QVariantMap>


using namespace util;

namespace hierhin {

class Essence;

class Item
{
public:
    static const QString DEFAULT_ID_GEN_CLASS_NAME;

    Item();

    QString id() const;
    void setId(const QString &id);

    static void setIdGenClassName(const QString &className);

private:
    mutable QString _id;
    QVariantMap _properties;
    static util::LazyPointer<uniq::Value<QString>> _idGen;
//TODO:    LazyPointer<Essence> _essence;
};

} // namespace hierhin

#endif // HIERHIN_ITEM_H
