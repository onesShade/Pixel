#ifndef LAYERSPANNEL_H
#define LAYERSPANNEL_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QStyleOption>
#include <QPainter>

#include <vector>

#include "canvas.h"

class LayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LayerWidget(QWidget* parent = nullptr)
        : QWidget(parent)
    {
        m_layout = new QHBoxLayout(this);
        m_layout->setSpacing(3);

        m_btn_1 = new QPushButton("b1");
        m_btn_2 = new QPushButton("b2");
        m_btn_3 = new QPushButton("b3");
        m_layer_name = new QLabel("lol");

        m_layout->addStretch();
        m_layout->addWidget(m_btn_1);
        m_layout->addWidget(m_layer_name);
        m_layout->addWidget(m_btn_2);
        m_layout->addWidget(m_btn_3);
    };

    void setName(const QString& name) { m_layer_name->setText(name); }

protected:
    void paintEvent(QPaintEvent *event) override {
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }

private:
    QHBoxLayout* m_layout;
    QPushButton* m_btn_1;
    QPushButton* m_btn_2;
    QPushButton* m_btn_3;
    QLabel* m_layer_name;
};


class LayersPannel : public QWidget
{
Q_OBJECT
public:
    explicit LayersPannel(QWidget* parent = nullptr, Canvas* canvas = nullptr);

private:
    void updateLayers();

    Canvas* m_canvas_ptr;
    QVBoxLayout* m_main_layout;
    std::vector<LayerWidget*> m_layers;
};

#endif // LAYERSPANNEL_H
