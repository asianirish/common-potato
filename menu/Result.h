#ifndef MENU_RESULT_H
#define MENU_RESULT_H

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

private:
    QVariant _value;

    QString _taskId; //TODO: implement

    int _errorCode;
    QString _errorDescription;
    QVariantMap _errorContext;
};

} // namespace menu

#endif // MENU_RESULT_H
