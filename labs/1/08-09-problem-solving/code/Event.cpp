#include <cstring>
#include <iostream>
#include "Event.hpp"

Event::Event(const char* name, time_t date, size_t seats, double price)
    : m_name(new char[strlen(name) + 1])
    , m_date(date)
    , m_totalSeats(seats)
    , m_takenSeats(0)
    , m_price(price)
{
    strcpy(m_name, name);
}


Event::Event(const Event& other)
{
    copy(other);
}


Event& Event::operator=(const Event& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}


Event::~Event()
{
    clear();
}


void Event::copy(const Event& other)
{
    m_name = new char[strlen(other.m_name) + 1];
    strcpy(m_name, other.m_name);
    m_date = other.m_date;
    m_totalSeats = other.m_totalSeats;
    m_takenSeats = other.m_takenSeats;
    m_price = other.m_price;
}


void Event::clear()
{
    delete[] m_name;
    m_name = nullptr;
}


bool Event::setName(const char* newName)
{
    if (newName) {
        char* newEvName = new (std::nothrow) char[strlen(newName) + 1];
        if (!newEvName)
            return false;

        delete[] m_name;
        m_name = newEvName;

        return true;
    }

    return false;
}


void Event::setDate(time_t newDate)
{
    if (newDate > time(nullptr)) {
        m_date = newDate;
    }
}


void Event::setTotalSeats(size_t newTotalSeats)
{
    if (newTotalSeats >= m_takenSeats) {
        m_totalSeats = newTotalSeats;
    }
}


void Event::setPrice(double newPrice)
{
    if (newPrice > 0) {
        m_price = newPrice;
    }
}
