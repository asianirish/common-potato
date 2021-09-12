#include "SimpleObject.h"

SimpleObject::SimpleObject(QObject *parent) : QObject(parent)
{

}

QString SimpleObject::simpleName() const
{
    return _simpleName;
}

void SimpleObject::setSimpleName(const QString &simpleName)
{
    _simpleName = simpleName;
}
