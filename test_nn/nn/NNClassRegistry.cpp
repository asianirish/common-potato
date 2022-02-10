#include "NNClassRegistry.h"

#include <uniq/TimeQStringValue.h>

NNClassRegistry::NNClassRegistry()
{

}

void NNClassRegistry::registerAllClasses() const
{

    //TODO: or register in Console class
    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::TimeQStringValue)
}
