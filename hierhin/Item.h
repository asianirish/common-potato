#ifndef HIERHIN_ITEM_H
#define HIERHIN_ITEM_H

#include "def/NodeDef.h"
#include "type.h"
#include "ItemCreator.h"
#include "nav/Path.h"
#include "Essence.h"

#include <util/LazyPointer.h>
#include <uniq/Value.h>

#include <QString>
#include <QVariantMap>

using namespace potato_util;

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

    QByteArray toJson() const;

    virtual NodeWeakPtr parentNode() const = 0;

    virtual void setParentNode(NodeWeakPtr parentNode) = 0;

    QVariant property(const QString &name) const;

    void setProperty(const QString &name, const QVariant &value);

    menu::TaskId execute(const QString &method, const QVariantList &args = QVariantList(), menu::TaskId *taskIdOut = nullptr);

    def::NodeDef definition() const;

    QString essenceClassName() const;

    QStringList essenceClassNames() const;

    bool isKindOf(const QString &className) const;

    BaseType baseType() const;

    ItemPtr clone() const;

    nav::Path absPath() const;

    bool isRoot() const;

    ItemPtr itemByProperty(const QString &name);

    int launcherIndex() const;
    void setLauncherIndex(int launcherIndex);

    QSharedPointer<menu::Launcher> launcher() const;

    ItemPtr refPtr(const QString &refName);

    QStringList essenceMethodNames() const;

protected:
    virtual ItemCreator *createCreator() const = 0;

    ItemPtr create();

    EssencePtr essencePtr() const;

private:
    mutable Id _id;
    QVariantMap _properties;
    static potato_util::LazyPointer<uniq::Value<Id>> _idGen;
    QString _essenceClassName;
    int _launcherIndex;

    virtual void nodeToMap(QVariantMap &mp) const {
        Q_UNUSED(mp);
    }

    virtual void nodeFromMap(const QVariantMap &mp) {
        Q_UNUSED(mp);
    }
};

} // namespace hierhin

#endif // HIERHIN_ITEM_H
