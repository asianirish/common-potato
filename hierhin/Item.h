#ifndef HIERHIN_ITEM_H
#define HIERHIN_ITEM_H

#include "def/NodeDef.h"
#include "type.h"
#include "ItemCreator.h"
#include "nav/Path.h"

#include <util/LazyPointer.h>
#include <uniq/Value.h>

#include <QString>
#include <QVariantMap>

using namespace util;

namespace hierhin {

class Item : public QEnableSharedFromThis<Item>
{
public:
    static const QString DEFAULT_ID_GEN_CLASS_NAME;
    static const QString DEFAULT_ESSENCE_CLASS_NAME;
    static const QString ID_KEY;
    static const QString ESSENCE_CLASS_KEY;
    static const QString PROPERTIES_KEY;
    static const QString BASE_TYPE_KEY;

    Item();

    Id id() const;
    void setId(const Id &id);

    static void setIdGenClassName(const QString &className);

    void setEssenceClassName(const QString &className);

    QVariantMap toMap() const;
    void fromMap(const QVariantMap &mp);

    QByteArray toJson();

    virtual NodeWeakPtr parentNode() const = 0; //TODO: or use a weak pointer?

    virtual void setParentNode(NodeWeakPtr parentNode) = 0;

    QVariant property(const QString &name) const;

    void setProperty(const QString &name, const QVariant &value);

    void execute();

    def::NodeDef definition() const;

    QString essenceClassName() const;

    QStringList essenceClassNames() const;

    bool isKindOf(const QString &className) const;

    BaseType baseType() const;

    ItemPtr clone() const;

    nav::Path absPath() const;

protected:
    virtual ItemCreator *createCreator() const = 0;

private:
    mutable Id _id;
    QVariantMap _properties;
    static util::LazyPointer<uniq::Value<Id>> _idGen;
    QString _essenceClassName;

    virtual void nodeToMap(QVariantMap &mp) const {
        Q_UNUSED(mp);
    }

    virtual void nodeFromMap(const QVariantMap &mp) {
        Q_UNUSED(mp);
    }

    EssencePtr essencePtr() const;
};

} // namespace hierhin

#endif // HIERHIN_ITEM_H
