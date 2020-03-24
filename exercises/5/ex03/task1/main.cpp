#include <iostream>
#include <cstring>
#include "person.hpp"
#include "person_array.hpp"

Person p1;

int main() {
    char * nameIvan = new char[5];
    strcpy(nameIvan, "Ivan");

    //Person p1;
    p1.setName(nameIvan);

    std::cout << p1.getName() << std::endl;

    nameIvan[0] = 'i';
    std::cout << p1.getName() << std::endl;

    delete nameIvan;
    std::cout << p1.getName() << std::endl;

    p1.setName("ivan");
    std::cout << p1.getName() << std::endl;

    Person p2("Gosho", 25, 1.75, 85);

    std::cout << p2.getName() << ' ' << p2.getAge() << ' ' << p2.getHeight() << ' ' << p2.getWeight() << std::endl;

    std::cout << p2 << std::endl;

    const char * name = p2.getName();

    std::cout << name << std::endl;

    //name[0] = 'g';
    std::cout << name << std::endl;
    std::cout << p2 << std::endl;

    std::cout << p2 << ", BMI: " << p2.getBMI() << std::endl;

    PersonArray pa;
    pa.push(p1);
    pa.push(p2);
    pa.push(p1);
    std::cout << p1 << std::endl << pa.get(1) << std::endl;

    int ma[] = {1, 2, 3};
    std::cout << ma[0] << ' ' << ma[11] << std::endl;

    Person p3(p2);
    Person p4;
    p4 = p2;
    p3.setName("Gosho 3");
    p4.setName("Gosho 4");
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;

    for (int i = 0; i < pa.size(); ++i) {
        std::cout << pa.get(i) << std::endl;
    }

    // б.
    int maxAge = 0;
    for (int i = 0; i < pa.size(); ++i) {
        if (maxAge < pa.get(i).getAge()) {
            maxAge = pa.get(i).getAge();
        }
    }
    std::cout << "max age is: " << maxAge << std::endl;
    for (int i = 0; i < pa.size(); ++i) {
        if (maxAge == pa.get(i).getAge()) {
            std::cout << pa.get(i) << std::endl;
        }
    }

    // в.
    double sumWeights = 0;
    for (int i = 0; i < pa.size(); ++i) {
        sumWeights += pa.get(i).getWeight();
    }

    double averageWeight = sumWeights / pa.size();
    std::cout << "average weight is: " << averageWeight << std::endl;
    for (int i = 0; i < pa.size(); ++i) {
        if (averageWeight > pa.get(i).getWeight()) {
            std::cout << pa.get(i) << std::endl;
        }
    }

    return 0;
}