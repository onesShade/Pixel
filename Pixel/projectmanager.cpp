#include "projectmanager.h"

#include <QDebug>

ProjectManager::ProjectManager()
    : m_selected_project(nullptr)
{
}

void ProjectManager::createProject()
{
    Project* project = new Project();
    m_projects.push_back(project);
    if(m_projects.size() == 1)
    {
        m_selected_project = project;
    }
}

Canvas* ProjectManager::GetCurrentCanvas()
{
    if(!m_selected_project) {
        qDebug() << "err: trying to use NULL project";
        return nullptr;
    }
    return m_selected_project->GetCanvas();
}
