#ifndef MENU_RESULT_H
#define MENU_RESULT_H

#include "Error.h"

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

    int errorCode() const;
    void setErrorCode(int errorCode);

    QString errorDescription() const;
    void setErrorDescription(const QString &errorDescription);

    QVariantMap errorContext() const;
    void setErrorContext(const QVariantMap &errorContext);

    Result &operator =(const QVariant &value);

    operator QVariant();

    QString taskId() const;
    void setTaskId(const QString &taskId);

    Error error() const;
    void setError(const Error &error);

private:
    QVariant _value;

    QString _taskId; //TODO: implement

    Error _error;
};



} // namespace menu

Q_DECLARE_METATYPE(menu::Result)

#endif // MENU_RESULT_H
