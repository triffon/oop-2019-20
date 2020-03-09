#include <iostream>
#include <stdlib.h>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

class Pace {
    int minutes;
    double seconds;

public:
    Pace() {
        minutes = 6;
        seconds = 0;
    }

    Pace(double speed) {
        double time = 60 / speed;
        minutes = (int) time;
        seconds = (time - minutes) * 60;
    }

    Pace(int minutes, int seconds) {
        this->minutes = minutes;
        this->seconds = seconds;
    }

    double getSpeed() {
        return 60 / (minutes + seconds / 60);
    }

    char* getTempo() {
        static char result[32] = "";
        memset(result, 0, sizeof result);
        char buffer[32];

        itoa (minutes, buffer, 10);
        strcat(result, buffer);
        strcat(result, "'");

        itoa ((int) seconds, buffer, 10);
        strcat(result, buffer);
        strcat(result, "\"");

        return result;
    }

};

int main() {
    Pace p1;
    cout << "Default speed was " << p1.getSpeed() << "km/h (" << p1.getTempo() << ")\n";

    double speed;
    cout << "Enter speed:" << endl;
    cin >> speed;
    Pace p2(speed);
    cout << "Entered speed was " << p2.getSpeed() << "km/h (" << p2.getTempo() << ")\n";

    int minutes, seconds;
    cout << "Enter tempo:" << endl;
    cin >> minutes >> seconds;
    Pace p3(minutes, seconds);
    cout << "Entered speed was " << p3.getSpeed() << "km/h (" << p3.getTempo() << ")\n";

    return 0;
}
