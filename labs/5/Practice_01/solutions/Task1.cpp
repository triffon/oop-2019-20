#include <iostream>

#define MAX_STRING_LENGTH 64
#define EGN_LENGTH 10
#define NUMBER_OF_SUBJECTS 5
#define MAX_NUMBER_OF_STUDENTS 100

using std::cout;
using std::cin;
using std::endl;

struct Student {
    char name[MAX_STRING_LENGTH];
    char family[MAX_STRING_LENGTH];
    char egn[EGN_LENGTH];
    long faculty_number;
    double marks[NUMBER_OF_SUBJECTS];

    void read() {
        cout << "Name: "; cin >> name;
        cout << "Family: "; cin >> family;
        cout << "EGN: "; cin >> egn;
        cout << "Faculty number: "; cin >> faculty_number;
        for (int i = 0; i < NUMBER_OF_SUBJECTS; i++) {
            cout << "Mark [" << i + 1 << "]: ";
            cin >> marks[i];
        }
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Family: " << family << endl;
        cout << "EGN: " << egn << endl;
        cout << "Faculty number: " << faculty_number << endl;
        cout << "Marks: ";
        for (int i = 0; i < NUMBER_OF_SUBJECTS; i++) {
             cout << " " << marks[i];
        }
        cout << endl;
    }

    double getAverage() {
        double sum = 0;

        for (int i = 0; i < NUMBER_OF_SUBJECTS; i++) {
            sum += marks[i];
        }

        return sum / NUMBER_OF_SUBJECTS;
    }
};

void printMenu() {
    cout << "Choose option:\n";
    cout << "1 - Add student\n";
    cout << "2 - Print information for students born in March\n";
    cout << "3 - Print information for student with highest marks\n";
    cout << "0 - Exit\n";
}

void printMarch(Student *students, int currentNumberOfStudents) {
    int monthSecondDigitPosition = 3;

    for (int i = 0; i < currentNumberOfStudents; i++) {
        if (students[i].egn[monthSecondDigitPosition] == '3') {
            students[i].print();
        }
    }
}

void printHighest(Student *students, int currentNumberOfStudents) {
    double currentHighest = students[0].getAverage();
    int studentPositionWithHighest = 0;

    for (int i = 1; i < currentNumberOfStudents; i++) {
        double currentAverage = students[i].getAverage();
        if (currentAverage > currentHighest) {
            currentHighest = currentAverage;
            studentPositionWithHighest = i;
        }
    }

    students[studentPositionWithHighest].print();
}

int main() {
    int option, currentNumberOfStudents = 0;
    Student students[MAX_NUMBER_OF_STUDENTS];

    do {
        printMenu();

        cin >> option;

        switch(option) {
            case 1:
                if (currentNumberOfStudents < MAX_NUMBER_OF_STUDENTS) {
                    //students[currentNumberOfStudents] = new Student();
                    students[currentNumberOfStudents++].read();
                }
                break;

            case 2:
                printMarch(students, currentNumberOfStudents);
                break;

            case 3:
                printHighest(students, currentNumberOfStudents);
                break;
        }
    } while(option);

    return 0;
}
