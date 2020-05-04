#include "Project.h"

Project::Project(string name, Client* client, Vector<Programmer*> team, TeamLead* teamLead):
	name(name), client(client), team(team), teamLead(teamLead) {}
