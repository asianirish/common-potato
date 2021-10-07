#include "NewItem.h"

#include "Currency.h"

#include <hi/ex/InvalidValueException.h>
#include <hi/ex/NoSuchField.h>
#include <hi/JsonSerializer.h>

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
        hi::Serializer *srl = new hi::JsonSerializer();
        hi::ItemPtr item = hi::ItemPtr(new test::Currency());
        item->setField("code", "ETH");
        item->setField("usdPrice", 3391.03);

        result += "ITEM CLASS NAME: " + item->className() + "\n";
        result += "ITEM TO MAP: " + srl->serialize(item);

        auto itemClone = item->cloneItem();
        result += "CLONE CLASS NAME: " + itemClone->className() + "\n";
        result += "CLONE TO MAP: " + srl->serialize(itemClone);

//TEST:        item->setField("euPrice", 999.99);
//TEST:        item->setField("usdPrice", QVariant());
        result += "USD PRICE: " + QString::number(item->field("usdPrice").toDouble());
//TEST:        qDebug() << "EU PRICE:" << item->field("euPrice");

    }  catch (hi::ex::FieldException &e) {
        qDebug() << "error:" << e.cause();
        qDebug() << "field:" << e.fieldName();
        return QVariant();
    } catch (hi::ex::Exception &e) {
        qDebug() << "error:" << e.cause();
        return QVariant();
    }

    return result;
}

} // namespace test
