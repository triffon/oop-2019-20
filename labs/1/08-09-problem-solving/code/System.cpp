#include "System.hpp"
#include <cstring>

System::System()
{}


System& System::i()
{
    static System sys;
    return sys;
}


System::~System()
{
    for (size_t i = 0; i < events.size(); i++)
        delete events[i];
}


void System::createAccount(const Account& acc)
{
    if (getAcc(acc.getNickname()) == nullptr)
        accs.push_back(acc);
}


void System::createEvent(const Event& event)
{
    if (getEv(event.getName()) == nullptr)
        events.push_back(new Event(event));
}


Pair<bool, Ticket> System::buyTicket(const char* eventName)
{
    Event* event = getEv(eventName);

    if (event == nullptr)
        return { false, {} };

    return { true, Ticket(event->getPrice(), event) };
}


Account* System::getAcc(const char* nickname)
{
    for (size_t i = 0; i < accs.size(); i++)
        if (strcmp(nickname, accs[i].getNickname()) == 0)
            return &accs[i];

    return nullptr;
}


Event* System::getEv(const char* name)
{
    for (size_t i = 0; i < events.size(); i++)
        if (strcmp(name, events[i]->getName()) == 0)
            return events[i];

    return nullptr;
}
