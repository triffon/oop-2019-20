#pragma once
#include "Account.hpp"
#include "Event.hpp"
#include "Pair.hpp"
#include "Ticket.hpp"
#include "Vector.hpp"

class System
{
public:
    enum Order {
        PRICE_ASC,
        PRICE_DESC,
        MOST_RECENT,
        LEAST_RECENT
    };

    System(const System& other) = delete;
    System& operator=(const System& other) = delete;
    ~System();

    static System& i();

    bool createAccount(const Account& acc);
    bool createEvent(const Event& event);
    bool buyTicket(const char* accName, const char* eventName, size_t count = 1);
    void displayEvents(Order order = MOST_RECENT);
    void run();

    bool serialize() const;
    bool deserialize();
    Event* getEv(const char* name) const;

private:
    System();
    Account* getAcc(const char* nickname);
    void displayHelp() const;

    Vector<Event*> events;
    Vector<Account> accs;
};
