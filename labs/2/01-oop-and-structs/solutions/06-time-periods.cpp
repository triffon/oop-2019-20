#include <iostream>

const unsigned SECONDS_IN_A_MINUTE = 60;
const unsigned SECONDS_IN_AN_HOUR = 60 * SECONDS_IN_A_MINUTE;

struct TimePeriod {
    unsigned hours;
    unsigned minutes;
    unsigned seconds;
};


void print(TimePeriod time)
{
    std::cout << time.hours << ':' << time.minutes << ':' << time.seconds;
}


TimePeriod timePeriodDifference(TimePeriod time1, TimePeriod time2)
{
    unsigned secs1 = time1.seconds +
                        time1.minutes * SECONDS_IN_A_MINUTE +
                        time1.hours * SECONDS_IN_AN_HOUR;

    unsigned secs2 = time2.seconds + 
                        time2.minutes * SECONDS_IN_A_MINUTE +
                        time2.hours * SECONDS_IN_AN_HOUR;

    unsigned resultSecs = abs(secs1 - secs2);

    TimePeriod result;
    result.hours = resultSecs / SECONDS_IN_AN_HOUR;
    resultSecs %= SECONDS_IN_AN_HOUR;

    result.minutes = resultSecs / SECONDS_IN_A_MINUTE;
    resultSecs %= SECONDS_IN_A_MINUTE;

    result.seconds = resultSecs;

    return result;
}


int main()
{
    TimePeriod t1 = { 2, 30, 15 }, t2 = { 3, 15, 45 };
    TimePeriod res = timePeriodDifference(t1, t2);

    std::cout << "The difference between ";
    print(t1);
    std::cout << " and ";
    print(t2);
    std::cout << " is ";
    print(res);

    return 0;
}
