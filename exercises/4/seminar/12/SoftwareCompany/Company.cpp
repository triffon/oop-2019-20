#include "Company.h"

Company::Company() {}

void Company::addClient(const Client& newClient) {
	clients.append(newClient);
}

void Company::addEmployee(const Employee& newEmployee) {
	// ??
}

void Company::addProject(const Project& newProject) {
	projects.append(newProject);
}

Project& Company::getProject(const char* name) {
	for (int i = 0; i < projects.getSize(); ++i) {
		if (projects[i].getName().compare(name) == 0) {
			return projects[i];
		}
	}
}

Client& Company::getClient(const char* name) {
	for (int i = 0; i < clients.getSize(); ++i) {
		if (clients[i].getName().compare(name) == 0) {
			return clients[i];
		}
	}
}

Employee& Company::getEmployee(const char* name) {
	//??
}
