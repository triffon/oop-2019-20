#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

const int MAX_COMMAND_SIZE = 256;

/*
    exit                        -> abort execution
    echo <str>                  -> output <str> to stdout
    add <int_num_1> <int_num_2> -> output <int_num_1> + <int_num_2> to stdout
*/

struct CommandLine {
    char inp[MAX_COMMAND_SIZE];

    int p = 0;

    void extractString(char * str) {
        int i = 0;
        for (; inp[p] != 0 && inp[p] != ' ' && inp[p] != '\n'; ++p) {
            str[i++] = inp[p];
        }
        str[i] = 0;
        if (inp[p] != 0) {
            ++p;
        }
    }

    void extractInt(int & n) {
        n = 0;
        bool negative = inp[p] == '-';
        if (negative) {
            ++p;
        }
        for (; inp[p] != 0 && inp[p] >= '0' && inp[p] <= '9'; ++p) {
            n = n * 10 + (inp[p] - '0');
        }
        if (negative) {
            n = -n;
        }
        if (inp[p] != 0) {
            ++p;
        }
    }
};

int main() {
    while (true) {
        // read command line
        cout << "> ";
        CommandLine cmd;
        cin.getline(cmd.inp, MAX_COMMAND_SIZE);

        // extract command
        char command[MAX_COMMAND_SIZE];
        cmd.extractString(command);

        // process command
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "echo") == 0) {
            char param[MAX_COMMAND_SIZE];
            cmd.extractString(param);
            cout << param << endl;
        } else if (strcmp(command, "add") == 0) {
            int a, b;
            cmd.extractInt(a);
            cmd.extractInt(b);
            cout << a + b << endl;
        } else {
            cout << "?" << endl;
        }
    }

    return 0;
}