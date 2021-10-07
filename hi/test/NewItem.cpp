#include "NewItem.h"

#include "Currency.h"

#include <hi/InvalidValueException.h>
#include <hi/NoSuchField.h>

#include <QDebug>

namespace test {

NewItem::NewItem()
{

}

QVariant NewItem::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    QString result;

    try {
        hi::Item *item = new test::Currency();
        item->setField("code", "ETH");
        item->setField("usdPrice", 3391.03);

        result += "ITEM CLASS NAME: " + item->className() + "\n";
    //    result += "ITEM TO MAP: " + item->toMap(); TODO: toJson

        auto itemClone = item->cloneItem();
        result += "NEW ITEM CLASS NAME: " + item->className() + "\n";
    //    result += "NEW ITEM TO MAP: " + item->toMap();

//TEST:        item->setField("euPrice", 999.99);
//TEST:        item->setField("usdPrice", QVariant());
        qDebug() << "USD PRICE:" << item->field("usdPrice");
        qDebug() << "EU PRICE:" << item->field("euPrice");

    }  catch (hi::FieldException &e) {
        qDebug() << "error:" << e.cause();
        qDebug() << "field:" << e.fieldName();
        return QVariant();
    } catch (hi::Exception &e) {
        qDebug() << "error:" << e.cause();
        return QVariant();
    }

    return result;
}

} // namespace test
