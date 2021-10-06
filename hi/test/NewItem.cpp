#include "NewItem.h"

#include "Currency.h"

#include <QDebug>

namespace test {

NewItem::NewItem()
{

}

QVariant NewItem::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    hi::Item *item = new test::Currency();
    item->setField("code", "ETH");
    item->setField("usdPrice", 3391.03);

    qDebug() << "ITEM CLASS NAME:" << item->className();
    qDebug() << "ITEM TO MAP:" << item->toMap();

    auto itemClone = item->clone();
    qDebug() << "NEW ITEM CLASS NAME:" << item->className();
    qDebug() << "NEW ITEM TO MAP:" << item->toMap();

    return QVariant();
}

} // namespace test
