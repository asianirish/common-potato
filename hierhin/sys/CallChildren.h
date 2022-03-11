#ifndef HIERHIN_SYS_CALLCHILDREN_H
#define HIERHIN_SYS_CALLCHILDREN_H

#include <NodeMethod.h>

namespace hierhin {
namespace sys {

class CallChildren : public NodeMethod
{
public:
    CallChildren();

protected:
    bool isSync() const final;

private:
    menu::def::ActionDef actionDef() const override;
private:
    QVariant actNodeImpl(const QVariantList &args, Node *node, const menu::TaskId &taskId) override;

    QMap<menu::TaskId, ItemPtr> _taskIdToNode;
    menu::TaskId _taskId;
    QString _foldMethodName;

private slots:
    void onChildReady(const menu::Result &childResult);
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_CALLCHILDREN_H
