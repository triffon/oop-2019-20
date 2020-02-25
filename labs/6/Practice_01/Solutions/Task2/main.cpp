#include <iostream>
#include <cstring>
#include <cfloat>
#include "Product.h"


int main() {
    Product p1, p2;
    init(p1, "A screw driver - screws you right over", 999, 9.50 );
    init(p2, "Sturdy hammer - breaks skulls", 1001, 22.99 );

    printProduct(p1);
    printProduct(p2);

    Product array[5];
    for (int i = 0; i < 5; ++i) {
        init(array[i], "", 0, 0.0 );
    }

    std::cout << std::endl;

    for (int i = 0; i < 5; ++i) {
        printProduct(array[i]);
    }

    std::cout << std::endl;

    unsigned serialNumber = 1 << 10;
    init(array[0], "Khan Kubrat's bundle of sticks", serialNumber, 100000 );
    serialNumber <<= 1;
    init(array[1], "Eye socket", serialNumber, 920.00 );
    serialNumber <<= 1;
    init(array[2], "Used pen", serialNumber, 0.18 );
    serialNumber <<= 1;
    init(array[3], "Laceless shoe", serialNumber, 8.49 );
    serialNumber <<= 1;
    init(array[4], "FMI Diploma", serialNumber, DBL_MAX );

    for (int i = 0; i < 5; ++i) {
        printProduct(array[i]);
    }
    std::cout << std::endl;

    Product replicas[5];
    char buff[BUFF_SIZE] = {0, };
    for (int j = 0; j < 5; ++j) {
        strcpy(buff, array[j].description);
        strcat(buff, "-replica");
        init(replicas[j], buff, array[j].serialNumber, array[j].cost/4 );
        memset(buff, 0, BUFF_SIZE );
    }

    for (int k = 0; k < 5; ++k) {
        printProduct(replicas[k]);
    }


    return 0;
}