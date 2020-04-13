#include <iostream>
#include <cstring>

#include "animal_type.hpp"
#include "animal.hpp"
#include "zoo.hpp"

const int MAX_COMMAND_SIZE = 32;
const int MAX_STRING_LENGTH = 256;

char command[MAX_COMMAND_SIZE];
char string[MAX_STRING_LENGTH];

Zoo zoo;

int main() {
    
    while (true) {
        // read command line
        std::cout << "> ";
        
        std::cin.getline(command, MAX_COMMAND_SIZE);

        // process command
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "load") == 0) {
            std::cout << "Enter filename: ";
            std::cin.getline(string, MAX_STRING_LENGTH);
            zoo.load(string);
        } else if (strcmp(command, "save") == 0) {
            std::cout << "Enter filename: ";
            std::cin.getline(string, MAX_STRING_LENGTH);
            zoo.save(string);
        } else if (strcmp(command, "price") == 0) {
            std::cout << "Current price: " << zoo.getPrice() << " BGN" << std::endl;
        } else if (strcmp(command, "setprice") == 0) {
            std::cout << "Enter new price: ";
            double price;
            std::cin >> price;
            std::cin.getline(string, MAX_STRING_LENGTH);
            zoo.setPrice(price);
        } else if (strcmp(command, "animals") == 0) {
            std::cout << zoo;
        } else if (strcmp(command, "add") == 0) {
            char typeName[MAX_STRING_LENGTH];
            double lifetime;
            int status;
            char animalName[MAX_STRING_LENGTH];
            double age;

            std::cout << "Enter animal type name: ";
            std::cin.getline(typeName, MAX_STRING_LENGTH);

            std::cout << "Enter animal type lifetime: ";
            std::cin >> lifetime;
            std::cin.getline(string, MAX_STRING_LENGTH);
            
            std::cout << "Animal type status (1 - safe, ";
            std::cout << "2 - endangered, ";
            std::cout << "3 - extinct): ";
            std::cin >> status;
            std::cin.getline(string, MAX_STRING_LENGTH);

            std::cout << "Enter animal name: ";
            std::cin.getline(animalName, MAX_STRING_LENGTH);

            std::cout << "Enter animal age: ";
            std::cin >> age;
            std::cin.getline(string, MAX_STRING_LENGTH);

            AnimalType at(typeName, lifetime, (status == 1 ? safe : (status == 2 ? endangered : extinct)));
            Animal a;
            a.setName(animalName);
            a.setAge(age);
            a.setType(at);

            zoo.push(a);
        } else {
            std::cout << "?" << std::endl;
        }
    }

    return 0;
}