#include <iostream>

const unsigned INCHES_IN_A_FOOT = 12;

struct Distance {
    unsigned feet;
    unsigned inches;
};


void print(Distance dist)
{
    std::cout << dist.feet << '\'' << dist.inches << '"';
}


Distance addDistances(Distance dist1, Distance dist2)
{
    Distance result;
    result.feet = dist1.feet + dist2.feet;
    result.inches = dist1.inches + dist2.inches;

    if (result.inches >= INCHES_IN_A_FOOT) {
        result.inches -= INCHES_IN_A_FOOT;
        result.feet++;
    }

    return result;
}


int main()
{
    Distance dist1 = { 4, 9 }, dist2 = { 2, 7 };
    Distance result = addDistances(dist1, dist2);

    print(dist1);
    std::cout << " + ";
    print(dist2);
    std::cout << " = ";
    print(result);

    return 0;
}
