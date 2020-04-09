#pragma once
#include "Account.hpp"
#include "Event.hpp"
#include "Pair.hpp"
#include "Ticket.hpp"
#include "Vector.hpp"

class System
{
public:
    System(const System& other) = delete;
    System& operator=(const System& other) = delete;
    ~System();

    static System& i();

    void createAccount(const Account& acc);
    void createEvent(const Event& event);

    Pair<bool, Ticket> buyTicket(const char* eventName);

private:
    Account* getAcc(const char* nickname);
    Event* getEv(const char* name);
    System();

    Vector<Account> accs;
    Vector<Event*> events;
};
