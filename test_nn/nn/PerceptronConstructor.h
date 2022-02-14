#ifndef NN_PERCEPTRONCONSTRUCTOR_H
#define NN_PERCEPTRONCONSTRUCTOR_H

#include <QVector>

#include <hierhin/type.h>

namespace nn {

class PerceptronConstructor
{
public:
    PerceptronConstructor();

    hierhin::NodePtr construct();

    QVector<int> layerSizes() const;
    void setLayerSizes(const QVector<int> &layerSizes);

private:
    QVector<int> _layerSizes;
    hierhin::NodePtr _prc;

    double dRand() const;
    hierhin::NodePtr constructLayer(int index);
    void constructLayers();
    void linkLayers(hierhin::NodePtr first, hierhin::NodePtr second);
};

} // namespace nn

#endif // NN_PERCEPTRONCONSTRUCTOR_H
