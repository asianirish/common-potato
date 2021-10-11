#include "ActionNewItem.h"

#include "Bitcoin.h"

#include <hi/ex/InvalidValueException.h>
#include <hi/ex/NoSuchField.h>
#include <hi/JsonSerializer.h>

#include <QDebug>
#include <iostream>

namespace test {

ActionNewItem::ActionNewItem()
{

}

QVariant ActionNewItem::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    QString result;

    try {
        hi::Serializer *srl = new hi::JsonSerializer();
//        hi::ItemPtr item = hi::ItemPtr(new test::Currency());
//        item->setField("code", "ETH");
//        item->setField("usdPrice", 3391.03);

//        result += "ITEM CLASS NAME: " + item->className() + "\n";
//        result += "ITEM TO MAP: " + srl->serialize(item);

//        auto itemClone = item->cloneItem();
//        result += "CLONE CLASS NAME: " + itemClone->className() + "\n";
//        result += "CLONE TO MAP: " + srl->serialize(itemClone);

////TEST:        item->setField("euPrice", 999.99);
////TEST:        item->setField("usdPrice", QVariant());
//        result += "USD PRICE: " + QString::number(item->field("usdPrice").toDouble()) + "\n";
////TEST:        qDebug() << "EU PRICE:" << item->field("euPrice");


//        {
//            hi::ItemPtr item = hi::ItemPtr(new test::Currency());
//            qDebug() << "ENTER A CURRENCY CODE  (try USD to test exception): ";
//            QTextStream qtin(stdin);
//            QString code = qtin.readLine();
//            item->setField("code", code);

//            result += "YOUR CURRENCY CODE IS " + item.dynamicCast<test::Currency>()->code() + "\n";
//            result += "YOUR ITEM TO MAP: " + srl->serialize(item) + "\n";
//        }

        {
            hi::ItemPtr btc = hi::ItemPtr(new test::Bitcoin());
            btc->setField("usdPrice", 55100);
            btc->setField("code", QString("BTC"));
            result += "BTC ITEM TO MAP: " + srl->serialize(btc) + "\n";
        }


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
