#ifndef MENU_ERROR_H
#define MENU_ERROR_H

#include <QString>
#include <QVariantMap>


namespace menu {

class Error
{
public:
    static const int NO_ERROR;

    enum class ERROR_TYPE{UNDEFINED, MENU, ARG_NUM, ARG_VAL};

    Error();

    int code() const;
    void setCode(int code);

    QString description() const;
    void setDescription(const QString &description);

    QVariantMap context() const;
    void setContext(const QVariantMap &context);

    void clear();

    operator bool() const;

    ERROR_TYPE type() const;
    void setType(const ERROR_TYPE &type);

private:
    int _code;
    ERROR_TYPE _type;
    QString _description;
    QVariantMap _context;
};

} // namespace menu

Q_DECLARE_METATYPE(menu::Error)

#endif // MENU_ERROR_H
