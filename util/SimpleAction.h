#ifndef UTIL_SIMPLEACTION_H
#define UTIL_SIMPLEACTION_H

#include "Action.h"

namespace util {

class SimpleAction : public Action
{
public:
    SimpleAction();

    void act(const QVariantList &args) final;

protected:
    virtual QVariant simplyAct(const QVariantList &args) = 0;
};

} // namespace util

#endif // UTIL_SIMPLEACTION_H
