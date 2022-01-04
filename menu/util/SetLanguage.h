#ifndef MENU_UTIL_SETLANGUAGE_H
#define MENU_UTIL_SETLANGUAGE_H

#include "menu/SimpleAction.h"

#include <QTranslator>

namespace menu {
namespace util {

class SetLanguage : public SimpleAction
{
public:
    SetLanguage();

    ~SetLanguage();

    QStringList files() const;
    void setFiles(const QStringList &files);

protected:
    QVariant simplyAct(const QVariantList &args) final;

private:
    def::ActionDef actionDef() const final;

    QStringList _files;
    static QList<QSharedPointer<QTranslator>> _translators;

};

} // namespace util
} // namespace menu

#endif // MENU_UTIL_SETLANGUAGE_H
