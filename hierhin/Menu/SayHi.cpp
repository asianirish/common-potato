#include "SayHi.h"

#include <QString>
#include <QDebug>

SayHi::SayHi() : _hiType(HI)
{

}

QVariant SayHi::simplyAct(const QVariantList &args)
{

    QString name = args.size() ? args.at(0).toString() : "anonymous";

    switch(_hiType) {
        case HI:
        qDebug() << "Hi," << name;
        break;

    case HELLO:
    qDebug() << "Hello," << name;
    break;

    case GOOD_DAY:
    qDebug() << "Good day," << name;
    break;

    }

    return true;
}

SayHi::HI_TYPE SayHi::hiType() const
{
    return _hiType;
}

void SayHi::setHiType(HI_TYPE newHiType)
{
    _hiType = newHiType;
}
