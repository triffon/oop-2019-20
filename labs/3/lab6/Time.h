#ifndef TIME_HEADER_INCLUDED
#define TIME_HEADER_INCLUDED

class Time
{
private:
    unsigned hours;
    unsigned minutes;
public:
    Time();
    Time(int hours, int minutes = 0);
    Time(const Time& other);
    Time& operator=(const Time& other);

    Time operator*(int mult) const;
    bool operator<(const Time& other) const;
    bool operator==(const Time& other) const;
    bool operator<=(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator>=(const Time& other) const;

    unsigned getHours() const;
    unsigned getMinutes() const;

    operator bool() const;
    operator int() const;
};

#endif