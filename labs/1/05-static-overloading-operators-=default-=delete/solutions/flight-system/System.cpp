#include <iostream>
#include <cstring>
#include "System.h"

const int MAX_CMD_LEN = 8;
const int MAX_INPUT_LEN = 128;

System::System()
    : moneySet(false)
{
    double money;
    std::cout << "Set starting money: ";
    std::cin >> money;
    setStartingMoney(money);
}


System& System::i()
{
    static System instance;
    return instance;
}


int System::getIndexFromId(unsigned flightId) const
{
    for (int i = 0; i < allFlights.size(); ++i)
        if (allFlights[i].getId() == flightId)
            return i;

    return -1;
}


void System::setStartingMoney(double money)
{
    if (!moneySet) {
        this->money = money;
        this->moneySet = true;
        std::cout << "Program started with $" << money << std::endl;
    } else {
        std::cout << "Starting money already set!" << std::endl;
    }
}


void System::createFlight(const char* departure, const char* destination, double price)
{
    allFlights.push_back({departure, destination, price});
    std::cout << "Created flight with ID " << allFlights[allFlights.size() - 1].getId()
              << " from " << departure << " to " << destination << " for $" << price << std::endl;
}


void System::deleteFlight(unsigned flightId)
{
    int index = getIndexFromId(flightId);
    if (index != -1) {
        allFlights.erase(index);
        std::cout << "Deleted flight with ID " << flightId << std::endl;
    } else {
        std::cout << "No flight with id " << flightId << " found!" << std::endl;
    }
}


void System::searchFlight(const char* departure, const char* destination) const
{
    for (int i = 0; i < allFlights.size(); ++i) {
        if (strcmp(allFlights[i].getDeparture(), departure) == 0 &&
            strcmp(allFlights[i].getDestination(), destination) == 0)
        {
            std::cout << "Flight from " << departure << " to " << destination 
                      << " has ID " << allFlights[i].getId() << std::endl;
            return;
        }
    }

    std::cout << "No flight from " << departure << " to " << destination << " found!" << std::endl;
}


void System::signup(unsigned flightId)
{
    int index = getIndexFromId(flightId);
    if (index != -1) {
        if (money >= allFlights[index].getPrice()) {
            signedFlights.push_back(allFlights[index]);
            money -= allFlights[index].getPrice();
            std::cout << "You are signed up for flight width ID " << flightId << " " << allFlights[index] << std::endl;
        } else {
            std::cout << "You do not have enough money!" << std::endl;
        }
    } else {
        std::cout << "No flight with id " << flightId << " found!" << std::endl;
    }
}


void System::printMoney() const
{
    std::cout << "You have $" << money << std::endl;
}


void System::printAll() const
{
    std::cout << "Flights: " << allFlights << std::endl;
}


void System::printSigned() const
{
    std::cout << "You are signed up for " << signedFlights << std::endl;
}


void System::printHelp() const
{
    std::cout << " - List of commands - " << std::endl
              << "\tcreate <departure> <destination> <money> - Create flight." << std::endl
              << "\tdelete <ID> - delete flight with ID." << std::endl
              << "\tsearch <departure> <destination> - get flight ID." << std::endl
              << "\tsignup <ID> - sign up for flight with ID." << std::endl
              << "\tmoney - shows our money." << std::endl
              << "\tall - shows all flights." << std::endl
              << "\tsigned - shows all signed up flights." << std::endl
              << "\thelp - shows info about the commands." << std::endl
              << "\tbye - terminates the program." << std::endl;
}


System::~System()
{
    std::cout << "Have a nice day!" << std::endl;
}


void System::run()
{
    char input[MAX_CMD_LEN];
    char depart[MAX_INPUT_LEN];
    char dest[MAX_INPUT_LEN];
    for (;;) {
        std::cin >> input;
        if (strcmp(input, "create") == 0) {
            double price;
            std::cin >> depart;
            std::cin >> dest;
            std::cin >> price;
            createFlight(depart, dest, price);
        }
        else if (strcmp(input, "delete") == 0) {
            unsigned id;
            std::cin >> id;
            deleteFlight(id);
        }
        else if (strcmp(input, "search") == 0) {
            std::cin >> depart;
            std::cin >> dest;
            searchFlight(depart, dest);
        } 
        else if (strcmp(input, "signup") == 0) {
            unsigned id;
            std::cin >> id;
            signup(id);
        }
        else if (strcmp(input, "money") == 0) {
            printMoney();
        }
        else if (strcmp(input, "all") == 0) {
            printAll();
        }
        else if (strcmp(input, "signed") == 0) {
            printSigned();
        }
        else if (strcmp(input, "help") == 0) {
            printHelp();
        }
        else if (strcmp(input, "bye") == 0) {
            break;
        }
        else {
            std::cout << "Unknown command! Type 'help' for available commands." << std::endl;
        }
    }
}
