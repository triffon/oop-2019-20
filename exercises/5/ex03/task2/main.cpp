#include <iostream>
#include <cstring>
#include "company.hpp"
#include "array.hpp"

using std::cout;
using std::endl;

double calculateTotalCapital(Array & arr) {
  double totalCapital = 0;
  for(int i = 0; i < arr.size(); i++) {
    totalCapital += arr.get(i).getCapital();
  }
  return totalCapital;
}

void printHigherThanAverage(Array & arrC) {
  double avgCapital = calculateTotalCapital(arrC) / arrC.size();
  for(int i = 0; i < arrC.size(); i++) {
    if(avgCapital < arrC.get(i).getCapital()) {
      arrC.get(i).print();
      cout << endl;
    }
  }
}

int main() {
  Company c1("Apple", 1987, 2500, 12321);
  Company c2("Amazon", 1998, 3500, 12121);
  Company c3("Google", 1969, 5875, 62345);

  Array arrC;
  arrC.push(c1);
  arrC.push(c2);
  arrC.push(c3);

  double totalCapital = 0;
  for(int i = 0; i < arrC.size(); i++) {
    totalCapital += arrC.get(i).getCapital();
  }

  // изкарвам тези фирми с капитал над средния за масива директно в main() - работи
  double avgCapital = totalCapital / arrC.size();
  for(int i = 0; i < arrC.size(); i++) {
    if(avgCapital < arrC.get(i).getCapital()) {
      arrC.get(i).print();
      cout << endl;
    }
  }

  // същото изкарване чрез функция - затрива имената
  printHigherThanAverage(arrC);

  return 0;
}
