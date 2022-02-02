#ifndef MENU_ERROR_H
#define MENU_ERROR_H

#include <QString>
#include <QVariantMap>


namespace menu {

class Error
{
Q_GADGET
public:
    static const int NO_USER_ERROR;

    enum CODE {
        NO_ERROR = 0,

        WRONG_TASK_ID = 100, //LAUNCHER

        ARG_NUM_MUST_BE_LESS_THAN = 200, //ARG NUM
        ARG_NUM_MUST_BE_GREATER_THAN = 201, //ARG NUM

        NOT_EQUAL_CONSTRAINT = 300, //ARG_VAL
        //TODO: other value constaint

        //TODO: type constraints

        //menu error codes
        NO_SUCH_ACTION_CLASS = 500, //MENU

        USER_DEFINED = 65535
    };
    Q_ENUM(CODE)

    Error();

    CODE code() const;
    void setCode(CODE code);

    QString description() const;
    void setDescription(const QString &description);

    QVariantMap context() const;
    void setContext(const QVariantMap &context);
    void addContext(const QString &key, const QVariant &value);

    void clear();

    operator bool() const;

private:
    CODE _code;
    QString _description;
    QVariantMap _context;
};

} // namespace menu

Q_DECLARE_METATYPE(menu::Error)


#endif // MENU_ERROR_H
