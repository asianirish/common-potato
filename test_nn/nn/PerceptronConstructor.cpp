#include "PerceptronConstructor.h"

#ifdef USE_CUTE_IMPL
#include <hierhin/cute/NodeImpl.h>
#else
#include <hierhin/direct/NodeImpl.h>
#endif


#include <util/gfunc.h>

#include "Neuron.h"
#include "Layer.h"
#include "Perceptron.h"
#include "Assoc.h"

#include <QDebug>

namespace nn {

#ifdef USE_CUTE_IMPL
using NodeImpl = cute::NodeImpl;
#else
using NodeImpl = direct::NodeHashImpl;
#endif

PerceptronConstructor::PerceptronConstructor()
{
    _prc = NodePtr(new NodeImpl());
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

NodePtr PerceptronConstructor::constructLayer(int index)
{
    auto lr = NodePtr(new NodeImpl());
    lr->setEssenceClassName(ESSENCE_CLASS(nn::Layer));
    int sz = _layerSizes.at(index);

    for (int i = 0; i < sz; i++) {
        auto nd = NodePtr(new NodeImpl());
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

    NodePtr prevLr;
    for (int i = 0; i < sz; i++) {
        qDebug() << "CONSTRUCT_LAYER" << i;
        auto lr = constructLayer(i);
        _prc->addChild(lr);
        if (prevLr) {
            linkLayers(prevLr, lr);
        }
        prevLr = lr;
    }
}

void PerceptronConstructor::linkLayers(hierhin::NodePtr first, hierhin::NodePtr second)
{
    auto refs = first->childRefs();

    int i = 0;
    for (auto &ref : refs) {
        qDebug() << "LINK_TO_REF" << i << ref;
        linkLayer(ref, second);
        i++;
    }
}

void PerceptronConstructor::linkLayer(hierhin::nav::ItemRef &targetRef, hierhin::NodePtr layer)
{
    auto ids = layer->idList();

    for (auto &id : ids) {
        auto source = layer->child(id);
        auto sourceNode = source.dynamicCast<Node>();

        if (sourceNode) {
            sourceNode->setLink(targetRef, true, Role(), ESSENCE_CLASS(nn::Assoc),
                                nn::Neuron::ASSOC_LINK_OWNER_ROLE)->setProperty("weight", dRand());

        }

    }
}



} // namespace nn
