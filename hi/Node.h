#ifndef HI_NODE_H
#define HI_NODE_H

#include "Item.h"

namespace hi {

class Node : public Item
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = nullptr);

signals:

};

} // namespace hi

#endif // HI_NODE_H
