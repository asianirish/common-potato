#ifndef NN_PERCEPTRON_H
#define NN_PERCEPTRON_H

#include <hierhin/Essence.h>

using namespace hierhin;

namespace nn {

class Perceptron : public hierhin::Essence
{
    Q_OBJECT
public:
    Perceptron();

//    QMap<Role, ItemReq> childRequirements() const override;
};

} // namespace nn

#endif // NN_PERCEPTRON_H
