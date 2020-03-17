//
// Created by tony on 27.02.20 г..
//

#include "AirplaneTicket.h"

void AirplaneTicket::fillTicketInformation()
{
    char firstName[20];
    char surname[20];
    char familyName[20];
    int egn, age;
    std::cout << "Enter starting point: ";
    std::cin >> startingPoint;
    std::cout << "Enter destination: ";
    std::cin >> destination;
    std::cout << "Enter date: ";
    std::cin >> date;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter flight seat: ";
    std::cin >> flightSeat;
    std::cout << "Enter duration: ";
    std::cin >> duration;
    std::cout << "Enter business class: ";
    std::cin >> businessClass;
    std::cout << "Enter holder's first name: ";
    std::cin >> firstName;
    std::cout << "Enter holder's surname: ";
    std::cin >> surname;
    std::cout << "Enter holder's family name: ";
    std::cin >> familyName;
    std::cout << "Enter holder's egn: ";
    std::cin >> egn;
    std::cout << "Enter holder's age: ";
    std::cin >> age;
    holder.setFirstName(firstName);
    holder.setSurname(surname);
    holder.setFamilyName(familyName);
    holder.setEgn(egn);
    holder.setAge(age);
}

void AirplaneTicket::changeDate(const char *date,
                                double price,
                                bool businessClass)
{
    strcpy(this->date, date);
    this->price = price;
    this->businessClass = businessClass;
}

void AirplaneTicket::printTicket() const
{
    std::cout << "The starting point is: " << startingPoint << std::endl;
    std::cout << "The final destination is: " << destination << std::endl;
    std::cout << "The date of the flight is: " << date << std::endl;
    std::cout << "The price is: " << price << std::endl;
    std::cout << "The flight seat is: " << flightSeat << std::endl;
    std::cout << "The duration of the flight is: " << duration << std::endl;
    if(businessClass){
        std::cout << "The ticket is for business class."<<std::endl;
    } else {
        std::cout << "The ticket is for economy class." << std::endl;
    }
    std::cout << "The name of the holder is: " <<
    holder.getFirstName() << " " <<
    holder.getSurname() << " " <<
    holder.getFamilyName() << " " << std::endl;
    std::cout << "The age of th holder is: " << holder.getAge() << std::endl;
    std::cout << "The egn of th holder is: " << holder.getEgn() << std::endl;

}



const char *AirplaneTicket::getStartingPoint() const
{
    return startingPoint;
}

const char *AirplaneTicket::getDestination() const
{
    return destination;
}

double AirplaneTicket::getPrice() const
{
    return price;
}

int AirplaneTicket::getFlightSeat() const
{
    return flightSeat;
}

int AirplaneTicket::getDuration() const
{
    return duration;
}

int AirplaneTicket::getHolderAge() const {
    return holder.getAge();
}

bool AirplaneTicket::getBusinessClass() const
{
    return businessClass;
}

const char *AirplaneTicket::getDate() const
{
    return date;
}

const char *AirplaneTicket::getHolderFirstName() const
{
    return holder.getFirstName();
}

const char *AirplaneTicket::getHolderSurname() const
{
    return holder.getSurname();
}

const char *AirplaneTicket::getHolderFamilyName() const
{
    return holder.getFamilyName();
}

void AirplaneTicket::changePerson(const Person &second)
{
    holder.setFirstName(second.getFirstName());
    holder.setSurname(second.getSurname());
    holder.setFamilyName(second.getFamilyName());
    holder.setEgn(second.getEgn());
    holder.setAge(second.getAge());
}
