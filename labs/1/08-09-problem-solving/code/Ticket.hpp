#pragma once
#include "Event.hpp"

class Ticket
{
public:
    Ticket(double price = 0, const Event* eventPtr = nullptr);
    inline double getPrice() const { return m_price; }
    inline const char* getTimeBought() const { return ctime(&m_timeBought); }
    inline const Event* getEvent() const { return m_event; }

private:
    time_t m_timeBought;
    double m_price;
    const Event* m_event;
};
