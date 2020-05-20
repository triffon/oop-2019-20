#include <iostream>

using namespace std;

int main() {
    string expression;

    cin >> expression;

    int counter = 0;
    int n = expression.length();
    for (int i = 0; i < n; i++) {
        if (expression[i] == ')') {
            counter--;
        } else if (expression[i] == '(') {
            counter++;
        }

        if (counter < 0) {
            break;
        }
    }

    if (counter != 0) {
        cout << "Incorrect\n";
    } else {
        cout << "Correct\n";
    }

    return 0;
}
