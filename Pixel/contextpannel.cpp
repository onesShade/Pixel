#include "contextpannel.h"

ContextPannel::ContextPannel(QWidget* parent)
{
    m_context_pannel_layout = new QHBoxLayout(parent);
    m_context_pannel_layout->setContentsMargins(0, 0, 0, 0);

    m_menu_bar = new QMenuBar(parent);

    QMenu* file_menu = m_menu_bar->addMenu("&File");
    file_menu->addAction("&Create file or project");
    file_menu->addAction("&Open file or project");
    file_menu->addAction("&Save project");
    file_menu->addAction("&Save project as");
    file_menu->addAction("&Close project");
    file_menu->addAction("&Print");

    QMenu* edit_menu = m_menu_bar->addMenu("&Edit");
    edit_menu->addAction("&Undo");
    edit_menu->addAction("&Redo");
    edit_menu->addAction("&Copy");
    edit_menu->addAction("&Paste");
    edit_menu->addAction("&Search");

    QMenu* view_menu = m_menu_bar->addMenu("&View");
    view_menu->addAction("&Me cant see");

    QMenu* help_menu = m_menu_bar->addMenu("&Help");
    help_menu->addAction("&Sos me die");

    m_context_pannel_layout->addWidget(m_menu_bar,1);
}

const QHBoxLayout& ContextPannel::getLayout() const
{
    return *m_context_pannel_layout;
}
