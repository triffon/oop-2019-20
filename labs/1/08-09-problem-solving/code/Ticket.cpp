#include "Ticket.hpp"

Ticket::Ticket(double price, const Event* eventPtr)
    : m_timeBought(time(nullptr))
    , m_price(price)
    , m_event(eventPtr)
{}
