#ifndef HIERHIN_EX_EMPTYCLASSNAMELIST_H
#define HIERHIN_EX_EMPTYCLASSNAMELIST_H

#include "ChildItemException.h"
#include "../type.h"

namespace hierhin {
namespace ex {

class EmptyClassNameList : public ChildItemException
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    EmptyClassNameList();

    QString cause() const override {
        return tr("empty class name list for role: '%1'").arg(role());
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_EMPTYCLASSNAMELIST_H
