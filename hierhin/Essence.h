#ifndef HIERHIN_ESSENCE_H
#define HIERHIN_ESSENCE_H

#include <QObject>

namespace hierhin {

class Item;

class Essence : public QObject
{
    Q_OBJECT
public:
    Essence();

    virtual ~Essence() = default;

    virtual void execute(Item *item) = 0;
private:

signals:

};

} // namespace hierhin

#endif // HIERHIN_ESSENCE_H
