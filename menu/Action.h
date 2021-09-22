#ifndef MENU_ACTION_H
#define MENU_ACTION_H

#include <uniq/Value.h>

#include <QObject>
#include <QVariantList>

#include "Result.h"

namespace menu {

class Action : public QObject
{
    Q_OBJECT
public:
    static const QString DEFAULT_UNIQ_VALUE_CLASS_NAME;
    explicit Action(QObject *parent = nullptr);

    virtual Result act(const QVariantList &args) = 0;

    virtual const char *alias() const = 0;

    static uniq::Value<QString> *taskIdGen();

    static QString taskIdGenClassName();
    static void setTaskIdGenClassName(const QString &uniqValueClassName);

signals:
    void ready(const QVariant &result);

private:
    static uniq::Value<QString> *_taskIdGen;
    static QString _taskIdGenClassName;

    static uniq::Value<QString> *createTaskIdGen();
};

} // namespace menu

#endif // MENU_ACTION_H
