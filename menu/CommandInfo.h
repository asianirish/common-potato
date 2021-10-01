#ifndef MENU_COMMANDINFO_H
#define MENU_COMMANDINFO_H

#include <QString>
#include <QVariantList>
#include <QVariantMap>

namespace menu {

class CommandInfo
{
public:
    CommandInfo();

    CommandInfo(const QString &name, const QVariantList &args);

    QString name() const;
    void setName(const QString &name);

    QVariantList args() const;
    void setArgs(const QVariantList &args);

    QVariantMap namedArgs() const;
    void setNamedArgs(const QVariantMap &namedArgs);

private:
    QString _name;
    QVariantList _args;
    QVariantMap _namedArgs;
};

} // namespace menu

#endif // MENU_COMMANDINFO_H
