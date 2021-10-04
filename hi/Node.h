#ifndef HI_NODE_H
#define HI_NODE_H

#include "Item.h"

namespace hi {

class HILIB_EXPORT Node : public Item
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = nullptr);

private:

    void nodeToMap(QVariantMap &mp) const final;

signals:

};

} // namespace hi

#endif // HI_NODE_H
