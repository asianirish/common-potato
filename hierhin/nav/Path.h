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
    Path(const QList<Step> &steps);

    const QList<Step> &steps() const;
    void setSteps(const QList<Step> &newSteps);
    void addStep(const Step &newStep);

    ItemPtr go(ItemPtr item);
    ConstItemPtr go(ConstItemPtr item) const;

    QStringList toStringList() const;

    void fromStringList(const QStringList &lst);

    QString toString() const;

    void fromString(const QString &pathStr);

    operator QString() const;

    operator bool() const;

    bool operator ==(const Path &other) const;

private:
    QList<Step> _steps;
};

} // namespace nav
} // namespace hierhin

#endif // HIERHIN_NAV_PATH_H
