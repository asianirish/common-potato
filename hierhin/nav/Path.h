#ifndef HIERHIN_NAV_PATH_H
#define HIERHIN_NAV_PATH_H

#include "Step.h"

#include <QList>

namespace hierhin {
namespace nav {

class Path
{
public:
    Path();
    Path(const QStringList &lst);
    Path(const QString &pathStr);

    const QList<Step> &steps() const;
    void setSteps(const QList<Step> &newSteps);
    void addStep(const Step &newStep);

    ItemPtr go(ItemPtr item) const;

    QStringList toStringList() const;

    void fromStringList(const QStringList &lst);

    QString toString() const;

    void fromString(const QString &pathStr);

    operator QString() const;

private:
    QList<Step> _steps;
};

} // namespace nav
} // namespace hierhin

#endif // HIERHIN_NAV_PATH_H
