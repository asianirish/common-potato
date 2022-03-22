#ifndef HIERHIN_ITEMACTION_H
#define HIERHIN_ITEMACTION_H

#include "Item.h"

#include <menu/SimpleAction.h>

namespace hierhin {

class Method : public menu::SimpleAction
{
public:
    Method();

    Item *item() const;
    void setItem(Item *item);

    //used in METHOD_CLASS_NAME
    static QString checkMethodClass(const QString &methodClassName) {
        return methodClassName;
    }

    menu::Result act(Item *item, const QVariantList &args);
    menu::Result act(Item *item, const QVariantMap &namedArgs);

protected:
    QVariant simplyAct(const QVariantList &args, const menu::TaskId &taskId) final;

private:
    Item *_item;

    virtual QVariant actImpl(const QVariantList &args, Item *item, const menu::TaskId &taskId) = 0;
};

#define METHOD_CLASS(className) className::checkMethodClass(#className)

} // namespace hierhin

#endif // HIERHIN_ITEMACTION_H
