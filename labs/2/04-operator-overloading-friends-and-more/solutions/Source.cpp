#include <iostream>
#include "Virus.h"
#include "Vector.h"
#include "Person.h"

int main()
{
    Person person("Ivan", 42);
    person.infect(Virus("Common cold", 2));
    std::cout << person.getViruses() << std::endl;

    Virus corona("Coronavirus", 7);
    person.infect(corona);

    std::cout << person.getViruses() << std::endl;

    Person person2(person);
    std::cout << person2.getName() << " has " << person2.getViruses() << std::endl;

    person.infect(corona);
    std::cout << person.getName() << " has " << person.getViruses() << std::endl;
    std::cout << person2.getName() << " has " << person2.getViruses() << std::endl;

    return 0;
}
