#ifndef UTIL_ACTION_H
#define UTIL_ACTION_H

#include <QObject>
#include <QVariantList>

namespace util {

class Action : public QObject
{
    Q_OBJECT
public:
    explicit Action(QObject *parent = nullptr);

    virtual void act(const QVariantList &args) = 0;

    virtual const char *alias() const = 0;

signals:
    void ready(const QVariant &result);

};

} // namespace util

#endif // UTIL_ACTION_H
