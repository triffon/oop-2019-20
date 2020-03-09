#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class ImmutableHoro {
    char name[32];
    char meter[32];
    char region[32];

public:
    ImmutableHoro(char name[], char meter[], char region[]) {
        strcpy(this->name,name);
        strcpy(this->meter,meter);
        strcpy(this->region,region);
    }

    const char* getName() {
        return name;
    }

    const char* getMeter() {
        return meter;
    }

    const char* getRegion() {
        return region;
    }
};

int main() {
    ImmutableHoro paydushko("Paydushko", "5/8", "Northern region");
    cout << paydushko.getName() << " (" << paydushko.getMeter() << ") - " << paydushko.getRegion() << endl;

    return 0;
}
