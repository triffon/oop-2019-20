#include <iostream>
#include "Vector.hpp"
#include "Event.hpp"
#include "Ticket.hpp"
#include "System.hpp"

int main()
{
    const time_t MINUTE = 60;
    const time_t HOUR = 60 * MINUTE;
    const time_t DAY = 24 * HOUR;
    Event event("A Great Event", time(nullptr) + 4 * DAY, 380, 59.99);

    System::i().createEvent(event);

    Pair<bool, Ticket> result = System::i().buyTicket("A Great Event");

    if (result.first) {
        std::cout << "$" << result.second.getPrice()
                  << " for " << result.second.getEvent()->getName()
                  << ", bought on " << result.second.getTimeBought();
    } else {
        std::cout << "Event not found!";
    }

    return 0;
}
