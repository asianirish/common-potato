#include "Activate.h"

#include <hierhin/Node.h>

namespace nn {

Activate::Activate()
{

}

menu::def::ActionDef Activate::actionDef() const
{
    menu::def::ActionDef def;
    def.setArgMaxNum(0);
    return def;
}

QVariant Activate::actNodeImpl(const QVariantList &args, hierhin::Node *node)
{
    Q_UNUSED(args);

    auto lnks = node->links();
    double sum = 0;

    for (const auto &lnk : qAsConst(lnks)) {
        auto targetRef = lnk->property(hierhin::Const::TARGET_PROP).value<hierhin::nav::ItemRef>();
        auto target = targetRef.ptr(lnk);
        double targetVal = target->property("value").toDouble();
        double weight = lnk->property("weight").toDouble();

        sum += targetVal * weight;
    }

    return activate(sum);
}

} // namespace nn
