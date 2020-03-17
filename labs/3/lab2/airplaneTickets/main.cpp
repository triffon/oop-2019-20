#include <iostream>

#include "lab2/task2/AirplaneTicket.h"

void fillTicketSchedule(int quantity,
                        AirplaneTicket *flightSchedule)
{
    for(int i = 0; i < quantity; i++)
    {
        flightSchedule[i].fillTicketInformation();
    }
}

void printTicketScheduleByStartingPoint(int quantity,
                                        AirplaneTicket *flightSchedule,
                                        const char* startingPoint)
{
    for(int i = 0; i < quantity; i++){
        if(strcmp(flightSchedule[i].getStartingPoint(), startingPoint) == 0)
        {
            flightSchedule[i].printTicket();
        }
    }
}

void printTicketScheduleByDestAndDate(int quantity,
                                      AirplaneTicket *flightSchedule,
                                      const char* destination,
                                      const char* date){
    for(int i = 0; i < quantity; i++){
        if(strcmp(flightSchedule[i].getStartingPoint(), destination) == 0 &&
           strcmp(flightSchedule[i].getDate(), date) == 0)
        {
            flightSchedule[i].printTicket();
        }
    }
}

void printArrivalsByDate(int quantity,
                         AirplaneTicket *flightSchedule,
                         const char* date)
{
    int count = 0;
    for(int i = 0; i < quantity; i++)
    {
        if(strcmp(flightSchedule[i].getStartingPoint(), date) == 0)
        {
            count += 1;
        }
    }
    std::cout << count;
}

bool compareFlights(const AirplaneTicket* first, const AirplaneTicket* second)
{
    return (strcmp(first->getStartingPoint(), second->getStartingPoint())== 0 &&
           strcmp(first->getDestination(), second->getDestination()) == 0 &&
           strcmp(first->getDate(), second->getDate()) == 0);
}

bool isNotPrinted(int differentFlightTickets,
                      const AirplaneTicket* currentFlight,
                      const AirplaneTicket* alreadyPrinted)
{
    for(int i = 0; i < differentFlightTickets; i++)
    {
        if(compareFlights(currentFlight, &alreadyPrinted[i]))
        {
            return 0;
        }
    }
    return 1;
}

int calculateAveragePrice(int quantity,
                          const AirplaneTicket* currentFlight,
                          const AirplaneTicket* flightSchedule)
{
    double sum = 0;
    int sameFlight = 0;
    for(int i = 0; i < quantity; i++)
    {
        if(compareFlights(currentFlight, &flightSchedule[i]))
        {
            sum += flightSchedule[i].getPrice();
            sameFlight++;
        }
    }
    return sum / sameFlight;
}

void printAveragePriceForFlight(int quantity,
                                AirplaneTicket *flightSchedule)
{
    AirplaneTicket alreadyPrinted[50];
    int differentFlightTickets = 0;
    for(int uncheckedFlights = 0; uncheckedFlights < quantity; uncheckedFlights++){
        if(isNotPrinted(differentFlightTickets, &flightSchedule[uncheckedFlights], alreadyPrinted))
        {
            std::cout << "For flight: " <<
            flightSchedule[uncheckedFlights].getStartingPoint() << ", " <<
            flightSchedule[uncheckedFlights].getDestination() << ", " <<
            flightSchedule[uncheckedFlights].getDate() << " the average price is: " <<
            calculateAveragePrice(quantity, &flightSchedule[uncheckedFlights], flightSchedule)
            <<std::endl;
            alreadyPrinted[differentFlightTickets] = flightSchedule[uncheckedFlights];
            uncheckedFlights++;
        }
    }
}

int countChildren(int quantity,
                  const AirplaneTicket* currentFlight,
                  const AirplaneTicket* flightSchedule)
{
    int count = 0;
    for(int i = 0; i < quantity; i++)
    {
        if(compareFlights(currentFlight, &flightSchedule[i]) &&
           flightSchedule[i].getHolderAge() <= 12)
        {
            count++;
        }
    }
    return count;
}

void printNumberOfChildren(int quantity,
                           AirplaneTicket* flightSchedule)
{
    AirplaneTicket alreadyCounted[50];
    int differentFlightTickets = 0;
    for(int uncheckedFlights = 0; uncheckedFlights < quantity; uncheckedFlights++){
        if(isNotPrinted(differentFlightTickets, &flightSchedule[uncheckedFlights], alreadyCounted))
        {
            std::cout << "For flight: " <<
                      flightSchedule[uncheckedFlights].getStartingPoint() << ", " <<
                      flightSchedule[uncheckedFlights].getDestination() << ", " <<
                      flightSchedule[uncheckedFlights].getDate() << " the number of children is: " <<
                      countChildren(quantity, &flightSchedule[uncheckedFlights], flightSchedule)
                      <<std::endl;
            alreadyCounted[differentFlightTickets] = flightSchedule[uncheckedFlights];
            differentFlightTickets++;
        }
    }
}

int countPeopleByFirstNameAndDate(int quantity,
                                   const AirplaneTicket* flightSchedule,
                                   const char* firstName,
                                   const char* date)
{
    int count = 0;
    for(int i = 0; i < quantity; i++)
    {
        if(strcmp(flightSchedule[i].getDate(), date) == 0 &&
           strcmp(flightSchedule[i].getHolderFirstName(), firstName) == 0)
        {
            count++;
        }
    }
    return count;
}

int main() {
    int quantity;
    std::cout << "Enter the number of tickets you would like to fill in: ";
    std::cin >> quantity;
    AirplaneTicket flightSchedule[50];

    fillTicketSchedule(quantity, flightSchedule);

    printTicketScheduleByStartingPoint(quantity, flightSchedule, "Paris");

    printTicketScheduleByDestAndDate(quantity, flightSchedule, "Milano", "09/05/2020");

    printArrivalsByDate(quantity, flightSchedule,"09/05/2020");

    printAveragePriceForFlight(quantity, flightSchedule);

    Person passenger;
    passenger.setFirstName("Georgi");
    passenger.setSurname("Georgiev");
    passenger.setFamilyName("Georgiev");
    passenger.setAge(3);


    flightSchedule[1].changePerson(passenger);

    printNumberOfChildren(quantity, flightSchedule);

    std::cout << countPeopleByFirstNameAndDate(quantity, flightSchedule, "Antonio", "09/05/2020");

    return 0;
}
