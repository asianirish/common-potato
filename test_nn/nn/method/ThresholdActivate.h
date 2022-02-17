#ifndef NN_THRESHOLDACTIVATE_H
#define NN_THRESHOLDACTIVATE_H

#include "Activate.h"

namespace nn {

class ThresholdActivate : public nn::Activate
{
public:
    ThresholdActivate();

private:
    double activate(double sum) override;
};

} // namespace nn

#endif // NN_THRESHOLDACTIVATE_H
