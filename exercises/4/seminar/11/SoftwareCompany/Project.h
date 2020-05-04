#pragma once
#include <iostream>
#include <string>
#include "Vector.h"
#include "TeamLead.h"
#include "Client.h"

using namespace std;

class TeamLead;

class Project {
public:
	Project(string name = "Project", Client* client = nullptr, Vector<Programmer*> team = Vector<Programmer*>(), TeamLead* teamLead = nullptr);
private:
	string name;
	Client* client;
	Vector<Programmer*> team;
	TeamLead* teamLead;
};

