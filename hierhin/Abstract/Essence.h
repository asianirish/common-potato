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

    explicit Essence(Item *item, QObject *parent = nullptr);

    Item *item() const;
    void setItem(Item *item);

private:
    Item *_item;
signals:

};

} // namespace hierhin

#endif // HIERHIN_ESSENCE_H
