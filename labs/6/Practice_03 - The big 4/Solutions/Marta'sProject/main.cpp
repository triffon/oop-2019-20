#include <iostream>
#include "Martenitsa.h"
#include "MartenitsaContainer.h"
#include "MartenitsaGenerator.h"


int main() {
    /*
    // Task 1
    Martenitsa mart;
    mart.readFromConsole();
    mart.print();

    // Task 2

    bool more = true;
    MartenitsaContainer list;
    Martenitsa buff;
    while(more) {
        buff.readFromConsole();
        list.add(buff);

        std::cout << "Enter another martenitsa? [y/n]" << std::endl;
        char option;
        std::cin >> option;
        more = (option == 'y');
    }

    list.print();
    std::cout << "\n\n\n=================================";
    list.sort();
    list.print();
    */
    // Task 3
    MartenitsaGenerator mg(15, 10);
    mg.generateList(10);
    mg.list.print();

    return 0;
}
