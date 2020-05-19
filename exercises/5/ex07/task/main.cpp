#include <iostream>

#include "employee.hpp"
#include "contract_employee.hpp"
#include "fulltime_employee.hpp"

using std::cout;
using std::endl;

int main() {
    ContractEmployee e1("Ivan", "Programirane", 15);
    ContractEmployee e2(e1);
    ContractEmployee e3;

    e1.setHours(20);
    e2.setHours(100);
    e3 = e2;

    e1.info();
    cout << " = " << e1.getWeeklyPayment() << endl;
    e2.info();
    cout << " = " << e2.getWeeklyPayment() << endl;
    e3.info();
    cout << " = " << e3.getWeeklyPayment() << endl;

    FulltimeEmployee e4("Pesho", "QA", 10);
    FulltimeEmployee e5(e4);
    FulltimeEmployee e6;

    e6 = e4;

    e4.info();
    cout << " = " << e4.getWeeklyPayment() << endl;
    e5.info();
    cout << " = " << e5.getWeeklyPayment() << endl;
    e6.info();
    cout << " = " << e6.getWeeklyPayment() << endl;

    return 0;
}