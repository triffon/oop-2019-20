#include <iostream>
#include <stdlib.h>
#include <cstring>

#define NEW_YORK_OFFSET -5
#define LONDON_OFFSET 0
#define SOFIA_OFFSET +2
#define MOSCOW_OFFSET +3
#define HOURS_A_DAY 24

using std::cout;
using std::endl;

class Time {
    int utcHour, utcMinute;

    char* getTimeString(int hour, int minute) {
        static char result[32] = "";
        memset(result, 0, sizeof result);
        char buffer[32];

        itoa (hour, buffer, 10);
        strcat(result, buffer);
        strcat(result, ":");

        itoa (minute, buffer, 10);
        strcat(result, buffer);

        return result;
    }

public:
    Time() {
        utcHour = 0;
        utcMinute = 0;
    }

    void newyorkTime(int hour, int minute) {
        utcHour = (hour + HOURS_A_DAY - NEW_YORK_OFFSET) % HOURS_A_DAY;
        utcMinute = minute;
    }

    void londonTime(int hour, int minute) {
        utcHour = (hour + HOURS_A_DAY - LONDON_OFFSET) % HOURS_A_DAY;
        utcMinute = minute;
    }

    void sofiaTime(int hour, int minute) {
        utcHour = (hour + HOURS_A_DAY - SOFIA_OFFSET) % HOURS_A_DAY;
        utcMinute = minute;
    }

    void moscowTime(int hour, int minute) {
        utcHour = (hour + HOURS_A_DAY - MOSCOW_OFFSET) % HOURS_A_DAY;
        utcMinute = minute;
    }

    char* getNewYorkTime() {
        int hour = (utcHour + HOURS_A_DAY + NEW_YORK_OFFSET) % HOURS_A_DAY;
        return getTimeString(hour, utcMinute);
    }

    char* getLondonTime() {
        int hour = (utcHour + HOURS_A_DAY + LONDON_OFFSET) % HOURS_A_DAY;
        return getTimeString(hour, utcMinute);
    }

    char* getSofiaTime() {
        int hour = (utcHour + HOURS_A_DAY + SOFIA_OFFSET) % HOURS_A_DAY;
        return getTimeString(hour, utcMinute);
    }

    char* getMoscowTime() {
        int hour = (utcHour + HOURS_A_DAY + MOSCOW_OFFSET) % HOURS_A_DAY;
        return getTimeString(hour, utcMinute);
    }
};

int main() {
    Time time;

    time.londonTime(21, 45);
    cout << time.getMoscowTime() << endl;

    time.newyorkTime(21, 45);
    cout << time.getSofiaTime() << endl;

    time.sofiaTime(21, 45);
    cout << time.getLondonTime() << endl;

    time.moscowTime(21, 45);
    cout << time.getNewYorkTime() << endl;
}
