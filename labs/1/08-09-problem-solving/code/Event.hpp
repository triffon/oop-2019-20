#pragma once
#include <ctime>
#include <fstream>
#include <iostream>

class Event
{
public:
    Event(std::ifstream& in);
    Event(const char* name = "untitled", time_t date = {}, size_t seats = 0, double price = 0);
    Event(const Event& other);
    Event& operator=(const Event& other);
    ~Event();

    bool setName(const char* newName);
    void setDate(time_t newDate);
    void setTotalSeats(size_t newTotalSeats);
    void setPrice(double newPrice);
    inline const char* getName() const { return m_name; }
    inline time_t getDate() const { return m_date; }
    inline const char* getDateString() const { return ctime(&m_date); }
    inline size_t getFreeSeats() const { return m_totalSeats - m_takenSeats; }
    inline size_t getTotalSeats() const { return m_totalSeats; }
    inline size_t getTakenSeats() const { return m_takenSeats; }
    inline double getPrice() const { return m_price; }

    void serialize(std::ofstream& out) const;

private:
    void copy(const Event& other);
    void clear();

    char*  m_name;
    time_t m_date;
    size_t m_totalSeats;
    size_t m_takenSeats;
    double m_price;
};

std::ostream& operator<<(std::ostream& out, const Event& obj);
