#include <iostream>

const int MAX_SUBJ_LEN = 16;
const int MAX_NAME_LEN = 64;
const int NUM_OF_GRADES = 3;
typedef float grade_t;

struct Grade {
    char subject[MAX_SUBJ_LEN];
    grade_t grade;
};

struct Student {
    char name[MAX_NAME_LEN];
    unsigned facultyNum;
    Grade grades[NUM_OF_GRADES];
    grade_t avgGrade;
};


void read(Grade& gr)
{
    std::cout << "Subject: ";
    std::cin >> gr.subject;
    std::cout << "Grade: ";
    std::cin >> gr.grade;
}


void read(Student& st)
{
    std::cout << "Name: ";
    std::cin >> st.name;
    std::cout << "FN: ";
    std::cin >> st.facultyNum;
    std::cout << "Enter " << NUM_OF_GRADES << " grades: " << std::endl;
    st.avgGrade = 0;
    for (int i = 0; i < NUM_OF_GRADES; i++) {
        read(st.grades[i]);
        st.avgGrade += st.grades[i].grade;
    }
    st.avgGrade /= NUM_OF_GRADES;
}


void print(const Grade& gr)
{
    std::cout << "Subject: " << gr.subject << ", Grade: " << gr.grade;
}


void print(const Student& st)
{
    std::cout 
        << "Name: " << st.name << ", FN: " << st.facultyNum
        << std::endl << "Grades: " << std::endl;

    for (int i = 0; i < NUM_OF_GRADES; i++) {
        print(st.grades[i]);
        std::cout << std::endl;
    }
    std::cout << "Average: " << st.avgGrade << std::endl;
}


void printSubjGrade(const Student* students, int size, grade_t gradeCheck)
{
    for (int i = 0; i < size; i++) {
        std::cout << students[i].name << " -> ";

        bool gradePrinted = false;
        for (int j = 0; j < NUM_OF_GRADES; j++) {
            if (students[i].grades[j].grade > gradeCheck) {
                std::cout << (gradePrinted ? ", ": "") << students[i].grades[j].subject << ' ';
                gradePrinted = true;
            }
        }

        if (!gradePrinted)
            std::cout << "No such subjects";

        std::cout << std::endl;
    }
}


void sort(Student* students, int size)
{
    for (int i = 0; i < size - 1; i++) {
        int currMaxInd = i;

        for (int j = i; j < size; j++)
            if (students[j].avgGrade > students[i].avgGrade)
                currMaxInd = j;

        if (currMaxInd != i)
            std::swap(students[i], students[currMaxInd]);
    }
}


int main()
{
    int numOfStudents;
    std::cout << "How many students?" << std::endl;
    std::cin >> numOfStudents;

    Student* arr = new (std::nothrow) Student[numOfStudents];
    if (!arr) {
        std::cerr << "Not enough memory!" << std::endl;
        return -1;
    }

    std::cout << "Write info about " << numOfStudents << " students:" << std::endl;

    for (int i = 0; i < numOfStudents; i++) {
        read(arr[i]);
        std::cout << std::endl;
    }

    /*
    std::cout << std::endl << std::endl << "Grade to check: ";
    
    grade_t grade;
    std::cin >> grade;
    std::cout << "Students' grade higher than that:" << std::endl;
    printSubjGrade(arr, numOfStudents, grade);
    */

    sort(arr, numOfStudents);

    std::cout << std::endl << "Students sorted by highest average grades: " << std::endl;
    for (int i = 0; i < numOfStudents; i++) {
        print(arr[i]);
        std::cout << std::endl;
    }

    delete[] arr;   // Don't forget to delete your memory

    return 0;
}

/*
Input:
    How many students?
    3
    Write info about 3 students:
    Name: Georgi
    FN: 45678
    Enter 3 grades:
    Subject: LA
    Grade: 5
    Subject: AA
    Grade: 4
    Subject: OOP
    Grade: 6

    Name: Petar
    FN: 45123
    Enter 3 grades:
    Subject: LA
    Grade: 3
    Subject: AA
    Grade: 2
    Subject: OOP
    Grade: 4

    Name: Todor
    FN: 45555
    Enter 3 grades:
    Subject: LA
    Grade: 5
    Subject: AA
    Grade: 5
    Subject: OOP
    Grade: 6

Output:
    Students sorted by highest average grades:
    Name: Todor, FN: 45555
    Grades:
    Subject: LA, Grade: 5
    Subject: AA, Grade: 5
    Subject: OOP, Grade: 6
    Average: 5.33333

    Name: Georgi, FN: 45678
    Grades:
    Subject: LA, Grade: 5
    Subject: AA, Grade: 4
    Subject: OOP, Grade: 6
    Average: 5

    Name: Petar, FN: 45123
    Grades:
    Subject: LA, Grade: 3
    Subject: AA, Grade: 2
    Subject: OOP, Grade: 4
    Average: 3
*/
