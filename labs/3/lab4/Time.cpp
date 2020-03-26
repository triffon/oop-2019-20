#include "Time.h"

Time::Time()
    : hours(0), minutes(0)
{}

Time::Time(int hours, int minutes)
{
    if (hours < 0 || minutes < 0)
    {
        this->hours = 0;
        this->minutes = 0;
    }
    else
    {
        if (minutes > 59)
        {
            hours += (minutes / 60);
            minutes = minutes % 60;
        }
        this->hours = hours;
        this->minutes = minutes;
    } 
}

Time::Time(const Time& other)
{
    this->hours = other.hours;
    this->minutes = other.minutes;
}

Time& Time::operator=(const Time& other)
{
    if (this != &other)
    {
        this->hours = other.hours;
        this->minutes = other.minutes;
    }
    return *this;
}

unsigned Time::getMinutes() const
{
    return minutes;
}

unsigned Time::getHours() const
{
    return hours;
}

Time Time::operator*(int mult) const
{
    return Time(this->hours * mult, this->minutes * mult);
}

Time::operator bool() const
{
    return this->minutes != 0 && this->hours != 0;
}

Time::operator int() const
{
    return this->minutes + this->hours * 60;
}

bool Time::operator<(const Time& other) const
{
    return ((int)*this) < ((int)other);
}

bool Time::operator==(const Time& other) const
{
    return ((int)*this) == (int)other;
}

bool Time::operator<=(const Time& other) const
{
    return *this < other || *this == other; 
}

bool Time::operator>(const Time& other) const
{
    return !(*this <= other);
}

bool Time::operator>=(const Time& other) const
{
    return !(*this < other);
}