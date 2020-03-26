#include "Time.h"
#include <iostream>

int main()
{
    Time t1(5, 29);
    Time t2(5, 30);


    std::cout << (t2 <= t1) << std::endl;

    std::cout << t2.getHours() << " " << t2.getMinutes() << std::endl;

}