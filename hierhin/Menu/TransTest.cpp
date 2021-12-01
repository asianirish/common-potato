#include "TransTest.h"

#include <QDebug>

TransTest::TransTest()
{

}

QVariant TransTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    QString hi(QObject::tr("hi"));
    qDebug() << hi;
    double n;

    {
        n = 0;
        QString object(QObject::tr("%n object(s)", "", n));
        qDebug() << object;
    }
    {
        n = 1;
        QString object(QObject::tr("%n object(s)", "", n));
        qDebug() << object;
    }
    {
        n = 3.14;
        QString object(QObject::tr("%n object(s)", "", n));
        qDebug() << object;
    }
    {
        n = 50;
        QString object(QObject::tr("%n object(s)", "", n));
        qDebug() << object;
    }

    {
        n = 3.14;
        QString object(QObject::tr("pi is %1 of conventional units").arg(n));
        qDebug() << object;
    }

    QByteArray testEmailMsg("wrong email format");

    qDebug() << "1. email error msg:" << QObject::tr(testEmailMsg.data());
    qDebug() << "2. email error msg:" << QObject::tr("wrong email format");
    qDebug() << "3. email error msg:" << QByteArray("wrong email format");

    return "end of test";
}
