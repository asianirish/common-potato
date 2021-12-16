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
    for (const auto &step : _steps) {
        //TODO: implement
    }
}


} // namespace nav
} // namespace hierhin
