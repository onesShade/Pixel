#ifndef LAYER_H
#define LAYER_H

#include <QPainter>
#include <QObject>
#include <QString>
#include <vector>

#include "object.h"

struct LayerInfo
{
    QString name;
    bool visible;
    bool locked;
};

class Layer : public QObject
{
    Q_OBJECT
public:
    explicit Layer(QObject* parent = nullptr);
    explicit Layer(const QString& name, QObject* parent = nullptr);

    void draw(QPainter* painter) const;
    void addObject(Object* object);

    void setName(const QString& name) { m_name = name; }
    QString getName() const { return m_name; }

    LayerInfo getInfo() const
    {
        return LayerInfo
        {
            m_name,
            m_visible,
            m_locked
        };
    }

private:
    bool m_visible;
    bool m_locked;
    QString m_name;
    std::vector<Object*> m_objects;
};

#endif // LAYER_H
