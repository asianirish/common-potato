#include "ItemVal.h"

#include <val/Email.h>
#include <val/Length.h>
#include <val/List.h>
#include <val/Phone.h>
#include <val/NotEqualTo.h>

#include <QDebug>

using namespace val;

ItemVal::ItemVal()
{

}

QVariant ItemVal::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);
    Email *emailVal = new Email();

    QString emailMsg = emailVal->errorMessage();
    qDebug() << "EMAIL ERROR MSG:" << emailMsg;

    Length *lengthVal = new Length();

    QString lengthMsg = lengthVal->errorMessage();
    qDebug() << "LENGTH ERROR MSG:" << lengthVal->errorMessage();

    lengthVal->setMinLength(7);
    lengthVal->setMaxLength(12);

    lengthMsg = lengthVal->errorMessage();
    qDebug() << "LENGTH ERROR MSG1:" << lengthVal->errorMessage();

    List *listVal = new List();
    listVal->addValue(12);
    listVal->addValue(13);
    listVal->addValue(31);
    listVal->addValue(7);

    QString listMsg = listVal->errorMessage();
    qDebug() << "LIST ERROR MSG" << listMsg;

    Phone *phoneVal = new Phone();
    QString phoneMsg = phoneVal->errorMessage();

    qDebug() << "PHONE ERROR MSG" << phoneMsg;

    NotEqualTo *notEqualToVal = new NotEqualTo();
    notEqualToVal->setValue(234);
    QString notEqualToMsg = notEqualToVal->errorMessage();

    qDebug() << "NOT EQUAL TO MSG" << notEqualToMsg;

    qDebug() << "HI:" << Email::tr("hi");
    qDebug() << "HI:" << QObject::tr("hi");
    qDebug() << "HI:" << tr("hi");

    return emailMsg + "\n" + lengthMsg + "\n" + listMsg;
}
