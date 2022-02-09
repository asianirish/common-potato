#ifndef NN_NEURON_H
#define NN_NEURON_H

#include <hierhin/LinkableEssence.h>

namespace nn {

class Neuron : public hierhin::LinkableEssence
{
    Q_OBJECT
public:
    Neuron();
};

} // namespace nn

#endif // NN_NEURON_H
