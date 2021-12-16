#include "Path.h"

namespace hierhin {
namespace nav {

Path::Path()
{

}

const QList<Step> &Path::steps() const
{
    return _steps;
}

void Path::setSteps(const QList<Step> &newSteps)
{
    _steps = newSteps;
}

void Path::addStep(const Step &newStep)
{
    _steps.append(newStep);
}

ItemPtr Path::go(ItemPtr item) const
{
    ItemPtr curItem = item;
    for (const auto &step : _steps) {
        curItem = step.go(curItem);

        if (!curItem) {
            return {};
        }
    }

    return curItem;
}

QStringList Path::toStringList() const
{
    QStringList lst;

    for (auto &str : lst) {
        Step step(str);
        lst.append(step);
    }

    return lst;
}


} // namespace nav
} // namespace hierhin
