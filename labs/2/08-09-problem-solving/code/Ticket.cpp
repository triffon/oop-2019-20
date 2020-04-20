#include <cstring>
#include "Ticket.hpp"
#include "System.hpp"

Ticket::Ticket(std::ifstream& in)
{
    in.read((char*) &m_timeBought, sizeof(m_timeBought));
    in.read((char*) &m_price, sizeof(m_price));

    size_t len;
    in.read((char*) &len, sizeof(len));
    char* evName = new char[len];
    in.read(evName, len);
    m_event = System::i().getEv(evName);
}


Ticket::Ticket(double price, const Event* eventPtr)
    : m_timeBought(time(nullptr))
    , m_price(price)
    , m_event(eventPtr)
{}


void Ticket::serialize(std::ofstream& out) const
{
    out.write((const char*) &m_timeBought, sizeof(m_timeBought));
    out.write((const char*) &m_price, sizeof(m_price));

    const char* evName = m_event->getName();
    size_t len = strlen(evName) + 1;
    out.write((const char*) &len, sizeof(len));
    out.write(evName, len);
}


std::ostream& operator<<(std::ostream& out, const Ticket& obj)
{
    return out << obj.m_event->getName() << " for $" << obj.m_price << " bought on " << ctime(&obj.m_timeBought);
}
