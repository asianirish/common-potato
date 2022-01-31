#ifndef HIERHIN_EX_EMPTYPROPERTYNAME_H
#define HIERHIN_EX_EMPTYPROPERTYNAME_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class EmptyPropertyName : public Exception
{
public:
    EmptyPropertyName();

    virtual QString cause() const {
        return tr("empty property name");
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_EMPTYPROPERTYNAME_H
