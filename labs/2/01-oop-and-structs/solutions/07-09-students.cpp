#include <iostream>

const int MAX_NAME_LEN = 64;

struct Student {
    char name[MAX_NAME_LEN];
    unsigned facultyNum;
};


void read(Student& st)
{
    std::cin >> st.name >> st.facultyNum;
}


void print(const Student& st)
{
    std::cout << "Name: " << st.name << ", FN: " << st.facultyNum;
}


int main()
{
    // const int CONST = 5;     // For storing just 5 students
    // Student arr[CONST];

    int numOfStudents;
    std::cout << "How many students?" << std::endl;
    std::cin >> numOfStudents;

    Student* arr = new (std::nothrow) Student[numOfStudents];
    if (!arr) {
        std::cerr << "Not enough memory!" << std::endl;
        return -1;
    }

    std::cout << "Write info about " << numOfStudents << " students (name and fn):" << std::endl;

    for (int i = 0; i < numOfStudents; i++)
        read(arr[i]);

    std::cout << std::endl;

    for (int i = 0; i < numOfStudents; i++) {
        print(arr[i]);
        std::cout << std::endl;
    }

    delete[] arr;   // Don't forget to delete your memory

    return 0;
}

/*
 * Sample input:
 * 3
 * Georgi 12345
 * Petar 65432
 * Todor 98765
 * 
 * Sample output:
 * Name: Georgi, FN: 12345
 * Name: Petar, FN: 65432
 * Name: Todor, FN: 98765
 * 
 */
