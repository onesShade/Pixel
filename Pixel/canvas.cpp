#include "canvas.h"
#include <QDebug>

Canvas::Canvas(QObject* parent) : QWidget(qobject_cast<QWidget*>(parent))
{
    m_selected = nullptr;
}

void Canvas::addLayer(Layer* layer)
{
    layer->setParent(this);
    m_layers.push_back(layer);
}

void Canvas::draw(QPainter* painter) const
{
    for (const auto& layer : m_layers) {
        layer->draw(painter);
    }
}

std::vector<LayerInfo> Canvas::getLayersInfo() const
{
    std::vector<LayerInfo> res;
    for (const auto& l : m_layers)
    {
        res.push_back(l->getInfo());
    }
    return res;
}
