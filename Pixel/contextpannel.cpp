#include "contextpannel.h"
#include <QDebug>
#include <QPushButton>

ContextPannel::ContextPannel(QWidget* parent)
{

    m_context_pannel_layout = new QHBoxLayout(parent);
    QPushButton* filler = new QPushButton("fifi", parent);

    m_context_pannel_layout->addWidget(filler,1);

}

const QHBoxLayout& ContextPannel::getLayout() const
{
    return *m_context_pannel_layout;
}
