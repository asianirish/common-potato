#ifndef HIERHIN_ESSENCE_H
#define HIERHIN_ESSENCE_H

#include "Item.h"

#include <QObject>

namespace hierhin {

class Essence : public QObject
{
    Q_OBJECT
public:
    Essence();

    virtual ~Essence() = default;

private:

signals:

};

} // namespace hierhin

#endif // HIERHIN_ESSENCE_H
