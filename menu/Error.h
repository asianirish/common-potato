#ifndef MENU_ERROR_H
#define MENU_ERROR_H

#include <QString>
#include <QVariantMap>


namespace menu {

class Error
{
Q_GADGET
public:
    static const int NO_ERROR;

    enum class ERROR_TYPE{UNDEFINED, MENU, LAUNCHER, ARG_NUM, ARG_VAL, ARG_TYPE};

    enum ERROR_CODE {
        ERROR_NO_ERROR = 0,

        WRONG_TASK_ID = 100, //LAUNCHER

        ARG_NUM_LESS_THAN_MIN = 200, //ARG NUM
        ARG_NUM_LARGER_THAN_MAX = 201, //ARG NUM

        NOT_EQUAL_CONSTRAINT = 300, //ARG_VAL
        //TODO: other value constaint

        //TODO: type constraints

        //TODO: menu error codes

        USER_DEFINED = 65535
    };
    Q_ENUM(ERROR_CODE)

    Error();

    int code() const;
    void setCode(int code);

    QString description() const;
    void setDescription(const QString &description);

    QVariantMap context() const;
    void setContext(const QVariantMap &context);
    void addContext(const QString &key, const QVariant &value);

    void clear();

    operator bool() const;

    ERROR_TYPE type() const;
    void setType(const ERROR_TYPE &type);

private:
    int _code; //TODO: ERROR_CODE
    ERROR_TYPE _type;
    QString _description;
    QVariantMap _context;
};

} // namespace menu

Q_DECLARE_METATYPE(menu::Error)


#endif // MENU_ERROR_H
