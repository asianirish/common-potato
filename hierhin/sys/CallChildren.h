#ifndef HIERHIN_SYS_CALLCHILDREN_H
#define HIERHIN_SYS_CALLCHILDREN_H

#include <NodeMethod.h>

namespace hierhin {
namespace sys {

class CallChildren : public NodeMethod
{
public:
    CallChildren();

private:
    menu::def::ActionDef actionDef() const override;
private:
    QVariant actNodeImpl(const QVariantList &args, Node *node) override;

    QMap<menu::TaskId, ItemPtr> _taskIdToNode;
    [[deprecated]] menu::TaskId _taskId; //TODO: delete
    QString _foldMethodName;
    QVariantList _childResults;

private slots:
    void onChildReady(const menu::Result &childResult);
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_CALLCHILDREN_H
