#include "ItemVal.h"

#include <val/Email.h>

#include <QDebug>

ItemVal::ItemVal()
{

}

QVariant ItemVal::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);
    val::Email *emailVal = new val::Email();
    QByteArray emailMsg = emailVal->errorMessage().toLatin1();
    qDebug() << "EMAIL ERROR MSG:" << QObject::tr(emailMsg.data());

    return emailMsg;
}
