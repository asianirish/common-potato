#include "PerceptronConstructor.h"

#include <hierhin/cute/NodeImpl.h>

#include <util/gfunc.h>

#include "Neuron.h"
#include "Layer.h"
#include "Perceptron.h"
#include "Assoc.h"

namespace nn {

PerceptronConstructor::PerceptronConstructor()
{
    _prc = NodePtr(new cute::NodeImpl());
    _prc->setEssenceClassName(ESSENCE_CLASS(nn::Perceptron));
}

NodePtr PerceptronConstructor::construct()
{
    constructLayers();
    return _prc;
}

QVector<int> PerceptronConstructor::layerSizes() const
{
    return _layerSizes;
}

void PerceptronConstructor::setLayerSizes(const QVector<int> &layerSizes)
{
    _layerSizes = layerSizes;
}

double PerceptronConstructor::dRand() const
{
    return potato_util::dRand(-1., 1.);
}

NodePtr PerceptronConstructor::layer(int index)
{
    auto lr = NodePtr(new cute::NodeImpl());
    lr->setEssenceClassName(ESSENCE_CLASS(nn::Layer));
    int sz = _layerSizes.at(index);

    for (int i = 0; i < sz; i++) {
        auto nd = NodePtr(new cute::NodeImpl());
        nd->setEssenceClassName(ESSENCE_CLASS(nn::Neuron));
        nd->setProperty("value", dRand());
        //TODO: set nd links (?)
        lr->addChild(nd);
    }

    return lr;
}

void PerceptronConstructor::constructLayers()
{
    int sz = _layerSizes.size();

    for (int i = 0; i < sz; i++) {
        auto lr = layer(i);
        _prc->addChild(lr);
    }

    //TODO: set links (here?)
}



} // namespace nn
