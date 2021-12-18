#include "Path.h"

namespace hierhin {
namespace nav {

Path::Path() : Path(QStringList())
{

}

Path::Path(const QStringList &lst)
{
    fromStringList(lst);
}

Path::Path(const QString &pathStr)
{
    fromString(pathStr);
}

Path::Path(const QList<Step> &steps) : _steps(steps)
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

    for (auto &step : _steps) {
        lst.append(step);
    }

    return lst;
}

void Path::fromStringList(const QStringList &lst)
{
    _steps.clear();

    for (auto &str : lst) {
        Step step(str);
        _steps.append(step);
    }
}

QString Path::toString() const
{
    if (_steps.isEmpty()) {
        return QString();
    }

    QStringList lst = toStringList();
    QString retStr;

    int i = 0;

    foreach (const QString &str, lst) {
        if (i) {
            retStr += "/";
        }
        retStr += str;
        i++;
    }

    return retStr;
}

void Path::fromString(const QString &pathStr)
{
    QStringList lst = pathStr.split("/");
    fromStringList(lst);
}

Path::operator QString() const
{
    return toString();
}


} // namespace nav
} // namespace hierhin
