#include <iostream>
#include <cstring>
#include "Problem2.h"
#include "Vector.h"

const int MAX_CMD_LEN = 4;

void problem2()
{
    Vector vec;

    char command[MAX_CMD_LEN];
    int arg;
    do {

        std::cin >> command;

        if (strcmp(command, "add") == 0) {
            std::cin >> arg;
            vec.push_back(arg);
        }
        else if (strcmp(command, "del") == 0) {
            std::cin >> arg;
            for (int i = 0; i < vec.size(); i++)
                if (vec.at(i) == arg)
                    vec.erase(i--);
        }
        else if (strcmp(command, "get") == 0) {
            std::cin >> arg;
            std::cout << vec.at(arg) << std::endl;
        }
        else if (strcmp(command, "fnd") == 0) {
            std::cin >> arg;
            int ind = -1;
            for (int i = 0; i < vec.size(); i++) {
                if (vec.at(i) == arg) {
                    ind = i;
                    break;
                }
            }
            std::cout << ind << std::endl;
        }
        else if (strcmp(command, "see") == 0) {
            for (int i = 0; i < vec.size(); i++)
                std::cout << vec.at(i) << " ";
            std::cout << std::endl;
        }

    } while (strcmp(command, "end") != 0);

    std::cout << "Bye!\n";

}
