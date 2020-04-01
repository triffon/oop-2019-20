#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Time {
    int hour;
    int minute;

public:
    Time() {
        hour = 0;
        minute = 0;
    }

    Time(int hour, int minute) {
        this->hour = hour;
        this->minute = minute;
    }

    Time operator+(const Time& t) {
        Time time;
        time.hour = (this->hour + t.hour + (this->minute + t.minute) / 60 ) % 24;
        time.minute = (this->minute + t.minute) % 60;
        return time;
    }

    Time operator+(int hour) {
        Time time;
        time.hour = (t.hour + hour) % 24;
        time.minute = t.minute;
        return time;
    }

    Time& operator=(const Time& t) {
        this->hour = t.hour;
        this->minute = t.minute;
        return *this;
    }

    void print() {
        if (hour < 10) cout << "0";
        cout << hour << ":";
        if (minute < 10) cout << "0";
        cout << minute << endl;
    }

    friend Time operator+(int hour, const Time& t);
};

Time operator+(int hour, const Time& t) {
    Time time;
    time.hour = (t.hour + hour) % 24;
    time.minute = t.minute;
    return time;
}

int main() {
    Time t1(23, 45);
    Time t2(1, 23);
    Time t3;

    // Predefined operation +
    (t1+t2).print();

    // Predefined operations + and =
    t3 = t1 + t2;
    t3.print();

    // Predefined operation + with int
    Time t4 = t1 + 5;
    t1.print();
    t4.print();

    // Predefined operation + with int (friend function)
    Time t5 = 5 + t1;
    t1.print();
    t5.print();


    return 0;
}
