#include "ItemVal.h"

#include <val/Email.h>
#include <val/Length.h>

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
    lengthVal->setMinLength(7);
    lengthVal->setMaxLength(12);

    QString lengthMsg = lengthVal->errorMessage();
    qDebug() << "LENGTH ERROR MSG1:" << lengthVal->errorMessage();

    qDebug() << "HI:" << Email::tr("hi");
    qDebug() << "HI:" << QObject::tr("hi");
    qDebug() << "HI:" << tr("hi");

    return emailMsg + "\n" + lengthMsg;
}
