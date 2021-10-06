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

    QString result;

    hi::Item *item = new test::Currency();
    item->setField("code", "ETH");
    item->setField("usdPrice", 3391.03);

    result += "ITEM CLASS NAME: " + item->className() + "\n";
//    result += "ITEM TO MAP: " + item->toMap(); TODO: toJson

    auto itemClone = item->cloneItem();
    result += "NEW ITEM CLASS NAME: " + item->className() + "\n";
//    result += "NEW ITEM TO MAP: " + item->toMap();

    return result;
}

} // namespace test
