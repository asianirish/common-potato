#ifndef MENU_RESULT_H
#define MENU_RESULT_H

#include "Error.h"

#include "type.h"

#include <QVariant>
#include <QString>
#include <QMap>

namespace menu {

class Result
{
public:
    static const int SUCCESSFUL_RESULT;

    Result();

    Result(const QVariant &value);

    QVariant value() const;
    void setValue(const QVariant &value);

    Error::CODE errorCode() const;
    void setErrorCode(Error::CODE errorCode);

    QString errorDescription() const;
    void setErrorDescription(const QString &errorDescription); //TODO: rename?

    QVariantMap errorContext() const;
    void setErrorContext(const QVariantMap &errorContext);

    Result &operator =(const QVariant &value);

    operator QVariant();

    TaskId taskId() const;
    void setTaskId(const TaskId &taskId);

    Error error() const;
    void setError(const Error &error);

private:
    QVariant _value;

    TaskId _taskId; //TODO: TaskId class (?)

    Error _error;
};



} // namespace menu

Q_DECLARE_METATYPE(menu::Result)

#endif // MENU_RESULT_H
