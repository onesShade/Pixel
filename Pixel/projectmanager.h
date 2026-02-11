#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include "project.h"

class projectManager
{
public:
    projectManager();
private:
    std::vector<Project*> m_projects;
    Project* m_selected_project;
};

#endif // PROJECTMANAGER_H
