#include "SetLanguage.h"

#include <QCoreApplication>


namespace menu {
namespace util {

SetLanguage::SetLanguage()
{

}

QVariant SetLanguage::simplyAct(const QVariantList &args)
{
    //delete translators from the app (if any)
    for (auto &translator : _translators) {
        QCoreApplication::removeTranslator(translator.data());
    }

    //empty translator list
    _translators.clear();

    if (args.size() == 2) {
        QStringList files = args.at(0).toStringList();
        QString language = args.at(1).toString();

        for (auto &file : files) {
            QSharedPointer<QTranslator> translator = QSharedPointer<QTranslator>(new QTranslator);

            QString transFile = file + "_" + language;
            if (!translator->load(transFile)) {
                return false;
            }

            _translators.append(translator);
            QCoreApplication::installTranslator(translator.data());
        }
    } else if (args.size() == 1) {
        QString language = args.at(0).toString();

        for (auto &file : _files) {
            QSharedPointer<QTranslator> translator = QSharedPointer<QTranslator>(new QTranslator);

            QString transFile = file + "_" + language;
            if (!translator->load(transFile)) {
                return false;
            }

            _translators.append(translator);
            QCoreApplication::installTranslator(translator.data());
        }
    } else if (args.size() == 0) {
        return false;
    }

    return true;
}

def::ActionDef SetLanguage::actionDef() const
{
    return def::ActionDef();
}

QStringList SetLanguage::files() const
{
    return _files;
}

void SetLanguage::setFiles(const QStringList &files)
{
    _files = files;
}


} // namespace util
} // namespace menu
