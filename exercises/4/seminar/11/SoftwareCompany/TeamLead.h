#pragma once
#include "Programmer.h"
#include "Project.h"

class Project;

class TeamLead: public Programmer {
public:
	TeamLead(const Programmer& programmer, Project* project = nullptr);
private:
	Project* project;
};

