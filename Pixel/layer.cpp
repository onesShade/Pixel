#include "layer.h"

#include <QDebug>

Layer::Layer(QObject* parent)
    : QObject(parent)
    , m_visible(true)
    , m_locked(false)
{
}

Layer::Layer(const QString& name, QObject* parent)
    : QObject(parent)
    , m_visible(true)
    , m_locked(false)
    , m_name(name)
{
}

Layer::~Layer()
{
    qDebug() << "deleting layer";
    for (Object* i : m_objects)
        delete i;
}

void Layer::addObject(Object* object)
{
    object->setParent(this);
    m_objects.push_back(object);
}

void Layer::draw(QPainter* painter) const
{
    if (!m_visible)
        return;

    for (const auto& obj : m_objects) {
        obj->draw(painter);
    }
}

LayerInfo Layer::getInfo() const
{
    return LayerInfo
        {
            m_name,
            m_visible,
            m_locked
        };
}
