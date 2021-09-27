#ifndef MENU_ERROR_H
#define MENU_ERROR_H

#include <QString>
#include <QVariantMap>


namespace menu {

class Error
{
public:
    static const int NO_ERROR;

    Error();

    int code() const;
    void setCode(int code);

    QString description() const;
    void setDescription(const QString &description);

    QVariantMap context() const;
    void setContext(const QVariantMap &context);

    void clear();

private:
    int _code;
    QString _description;
    QVariantMap _context;
};

} // namespace menu

Q_DECLARE_METATYPE(menu::Error)

#endif // MENU_ERROR_H
