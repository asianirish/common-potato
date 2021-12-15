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

ItemWeakPtr Path::go(Item *item) const
{
    for (auto step : _steps) {
        //TODO: implement
    }
}


} // namespace nav
} // namespace hierhin
