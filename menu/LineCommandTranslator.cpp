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
    QVector<QVariant> vargs(lst.size());

//depricated:    qCopy(lst.begin(), lst.end(), vargs.begin());
    std::copy(lst.begin(), lst.end(), vargs.begin());

    args = vargs.toList();

    return CommandInfo(cmd, args);

}

} // namespace menu
