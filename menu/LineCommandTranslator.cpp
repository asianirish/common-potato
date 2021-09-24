#include "LineCommandTranslator.h"

namespace menu {

LineCommandTranslator::LineCommandTranslator()
{

}

CommandInfo LineCommandTranslator::translate(const QString &commandString) const
{
    auto lst = commandString.split(" ");
    QString cmd = lst.takeFirst();
    QVariantList args;
//    QVector<QVariant> vargs;

//depricated:    qCopy(lst.begin(), lst.end(), args.begin());
    std::copy(lst.begin(), lst.end(), args.begin());

    return CommandInfo(cmd, args);

}

} // namespace menu
