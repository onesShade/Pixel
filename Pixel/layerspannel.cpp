#include "layerspannel.h"

#include <QDebug>

LayersPannel::LayersPannel(QWidget *parent, Canvas* canvas)
    : QWidget(parent)
    , m_canvas_ptr(canvas)
{
    m_main_layout = new QVBoxLayout(this);
    updateLayers();
}

void LayersPannel::updateLayers()
{
    if (!m_canvas_ptr) {
        qDebug() << "err no canvas given";
    }

    std::vector<LayerInfo> info = m_canvas_ptr->getLayersInfo();


    qDebug() << "layers count: " << info.size();
    for (const LayerInfo& li : info)
    {
        LayerWidget* lw = new LayerWidget(this);

        lw->setName(li.name);
        m_layers.push_back(lw);
        m_main_layout->addWidget(lw);
    }
}
