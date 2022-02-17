#include "ThresholdActivate.h"

namespace nn {

ThresholdActivate::ThresholdActivate()
{

}

double ThresholdActivate::activate(double sum)
{
    if (sum >= 0) {
        return 1;
    }

    return -1; //TODO: params
}

} // namespace nn
