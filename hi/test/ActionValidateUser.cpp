#include "ActionValidateUser.h"
#include "User.h"

#include "hi/JsonSerializer.h"
#include "hi/ex/FieldException.h"

#include <QTextStream>
#include <QDebug>

namespace test {

ActionValidateUser::ActionValidateUser()
{

}

QVariant ActionValidateUser::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    try {
        hi::Serializer *srl = new hi::JsonSerializer();
        hi::ItemPtr item = hi::ItemPtr(new test::User());
        QTextStream qtin(stdin);

        qDebug() << "name: ";
        QString name = qtin.readLine();
        item->setField("name", name);

        qDebug() << "age: ";
        QString age = qtin.readLine();
        item->setField("age", age.toInt());

        qDebug() << "temperature: ";
        QString temp = qtin.readLine();
        item->setField("temperature", temp.toDouble());

        qDebug() << "email: ";
        QString email = qtin.readLine();
        item->setField("email", email);

        qDebug() << "phone: ";
        QString phone = qtin.readLine();
        item->setField("phone", phone);

        qDebug() << "language (2 symbol code): ";
        QString language = qtin.readLine();
        item->setField("language", language);

        return srl->serialize(item);

    }  catch (hi::ex::FieldException &e) {
        qDebug() << "error:" << e.cause();
        qDebug() << "field:" << e.fieldName();
    } catch (hi::ex::Exception &e) {
        qDebug() << "error:" << e.cause();
    }

    return QVariant();
}

} // namespace test
