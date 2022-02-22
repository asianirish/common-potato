#ifndef HIERHIN_EX_NOITEM_H
#define HIERHIN_EX_NOITEM_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class NoItem : public Exception
{
public:
    NoItem();

    QString cause() const override {
        return tr("there is no item");
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_NOITEM_H
