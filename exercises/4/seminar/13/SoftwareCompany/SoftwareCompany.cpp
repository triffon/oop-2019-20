// SoftwareCompany.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Company.h"
#include "HR.h"

using namespace std;

int main() {
    /*Person p1("georgi", "todorov", 42);

    cout << p1;

    string ordersArr[] = { "order1", "order2" };
    Vector<string> orders(ordersArr, 2);
    Client c(p1, orders);
    cout << c;

    Employee e(p1);
    cout << e;*/

    /*Vector<int> v;
    for (int i = 0; i < 15; ++i) {
        v.append(i);
    }

    for (int i = 0; i < 15; ++i) {
        cout << v[i]<< " ";
    }*/

    Employee* employee1 = new Programmer(Employee(Person("jon", "su", 34), 999), "elizabeth");
    HR hr1 = HR(Employee(Person("Iva", "Hristova", 26), 999));
    hr1.addBuzzword("results-driven");
    Employee* employee2 = new HR(hr1);

    Company::sharedInstance.addEmployee(employee1);
    Company::sharedInstance.addEmployee(employee2);

    Company::sharedInstance.work();

    return 0;
}