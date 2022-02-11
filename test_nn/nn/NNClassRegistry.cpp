#include "NNClassRegistry.h"
#include "Neuron.h"
#include "Layer.h"
#include "Perceptron.h"
#include "Assoc.h"

#include <uniq/TimeQStringValue.h>

NNClassRegistry::NNClassRegistry()
{

}

void NNClassRegistry::registerAllClasses() const
{
    qRegisterMetaType<hierhin::nav::ItemRef>();
    QMetaType::registerConverter<hierhin::nav::ItemRef, QString>(&hierhin::nav::ItemRef::toString);
    QMetaType::registerConverter<QString, hierhin::nav::ItemRef>(hierhin::nav::stringToItemRef);

    //TODO: or register in Console class
    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::TimeQStringValue)

    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, nn::Neuron);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, nn::Layer);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, nn::Perceptron);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, nn::Assoc);
}
