#include "Company.h"

Company::Company() {}

Company::~Company() {
	for (int i = 0; i < employees.getSize(); ++i) {
		delete employees[i];
	}
}

Company Company::sharedInstance;

void Company::addClient(const Client& newClient) {
	clients.append(newClient);
}

void Company::addEmployee(Employee* newEmployee) {
	employees.append(newEmployee);
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

	throw 1;
}

Client& Company::getClient(const char* name) {
	for (int i = 0; i < clients.getSize(); ++i) {
		if (clients[i].getName().compare(name) == 0) {
			return clients[i];
		}
	}

	throw 1;
}

Employee& Company::getEmployee(const char* name) {
	for (int i = 0; i < employees.getSize(); ++i) {
		if (employees[i]->getName().compare(name) == 0) {
			return *(employees[i]);
		}
	}

	throw 1;
}

void Company::work() {
	for (int i = 0; i < employees.getSize(); ++i) {
		employees[i]->work();
	}
}
