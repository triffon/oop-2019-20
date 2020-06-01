#include "Project.h"

Project::Project(string name, Client* client, Vector<Programmer*> team, TeamLead* teamLead):
	name(name), client(client), team(team), teamLead(teamLead) {}

const string& Project::getName() const {
	return name;
}

void Project::setClient(Client& client) {
	this->client = &client;
}

void Project::addProgrammer(Programmer& programmer) {
	team.append(&programmer);
}

void Project::setTeamLead(TeamLead& teamLead) {
	this->teamLead = &teamLead;
}
