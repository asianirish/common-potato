#ifndef NN_ACTIVATE_H
#define NN_ACTIVATE_H

#include <hierhin/NodeMethod.h>

namespace nn {

//parent class for all activation Functions
class Activate : public hierhin::NodeMethod
{
public:
    Activate();

private:
    menu::def::ActionDef actionDef() const override;
    QVariant actNodeImpl(const QVariantList &args, hierhin::Node *node) final;

    virtual double activate(double sum) = 0;
};

} // namespace nn

#endif // NN_ACTIVATE_H
