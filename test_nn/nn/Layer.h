#ifndef NN_LAYER_H
#define NN_LAYER_H

#include <hierhin/LinkableEssence.h>

namespace nn {

using namespace hierhin;

class Layer : public hierhin::LinkableEssence
{
    Q_OBJECT
public:
    Layer();

};

} // namespace nn

#endif // NN_LAYER_H
