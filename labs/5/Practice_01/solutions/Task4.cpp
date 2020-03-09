#include <iostream>
#include <cstring>

#define MAX_STRING 128
#define MAX_NUMBER_PARTICIPANTS 1000
#define NUMBER_OF_MARATHONS 12

using std::cin;
using std::cout;
using std::endl;

struct Runner {
    char name[MAX_STRING];
    char family[MAX_STRING];
    double times[NUMBER_OF_MARATHONS];

    void read() {
        cout << "Name:" << endl;
        cin.ignore();
        cin.getline(name, MAX_STRING);

        cout << "Family:" << endl;
        cin.getline(family, MAX_STRING);

        for (int i = 0; i < NUMBER_OF_MARATHONS; i++) {
            cout << i + 1 << " marathon time:" << endl;
            cin >> times[i];
        }
    }

    double getPace() {
        double sum = 0.0;

        for (int j = 0; j < NUMBER_OF_MARATHONS; j++) {
            sum += times[j];
        }

        return sum / NUMBER_OF_MARATHONS;
    }

    int beatNtimes(Runner* other) {
        int number = 0;

        for (int j = 0; j < NUMBER_OF_MARATHONS; j++) {
            if (times[j] < other->times[j]) {
                number++;
            }
        }

        return number;
    }
};

void printSlowestRunner(Runner runnersList[MAX_NUMBER_PARTICIPANTS], int n) {
    int slowestRunnerIndex = 0;
    double slowestPace = runnersList[slowestRunnerIndex].getPace();

    for (int i = 1; i < n; i++) {
        if (slowestPace > runnersList[i].getPace()) {
            slowestPace = runnersList[i].getPace();
            slowestRunnerIndex = i;
        }
    }

    cout << "Slowest runner is " << runnersList[slowestRunnerIndex].name << " " << runnersList[slowestRunnerIndex].family << endl;
}

int main() {
    int n, indexA, indexB;
    Runner runnersList[MAX_NUMBER_PARTICIPANTS];

    cout << "Number of runners: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        runnersList[i].read();
    }

    printSlowestRunner(runnersList, n);

    cout << "Enter index of first runner: ";
    cin >> indexA;
    cout << "Enter index of second runner: ";
    cin >> indexB;
    cout << runnersList[indexA - 1].beatNtimes(&runnersList[indexB - 1]) << endl;

    return 0;
}
