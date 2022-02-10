#include "NNClassRegistry.h"
#include "Neuron.h"
#include "Layer.h"
#include "Perceptron.h"

#include <uniq/TimeQStringValue.h>

NNClassRegistry::NNClassRegistry()
{

}

void NNClassRegistry::registerAllClasses() const
{

    //TODO: or register in Console class
    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::TimeQStringValue)


    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, nn::Neuron);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, nn::Layer);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, nn::Perceptron);
}
