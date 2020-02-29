#include <iostream>
#include "Student.h"
#include "StudentList.h"
#include "Course.h"
#include "RetiredTeacher.h"

int main() {
    // Task 1
    Student s1(81500, "Svetlana Angelova", "Informatics", 7);
    Student s2(81501, "Zdravko Hvarlingov", "Mathematics", 7);
    Student s3(637135, "Jordan Georgiev", "Computer Science", 7);
    Student s4(73419, "Martin Indzov", "Informatics", 9);
    Student s5(69696, "Diana Elenkova", "Statistics", 7);

    s1.printInformation();
    s2.printInformation();
    s3.printInformation();
    s4.printInformation();
    s5.printInformation();
    std::cout << "-------------------------" << std::endl;
    // Task 2
    StudentList list(5);
    list.add(s1);
    list.add(s2);
    list.add(s3);
    list.add(s4);
    list.add(s5);

    list.print();
    std::cout << "-----------------------------" << std::endl;
    // Task 3
    Course OOP("OOP", 10);
    Student yasen(45460, "Yasen", "Informatics", 2);
    OOP.enrolStudent(yasen);

    Student students[] = {s1, s2, s3};
    OOP.enrolStudents(students, 3);
    OOP.printInformation();
    std::cout << "------------------------------" << std::endl;

    // Task 4
    RetiredTeacher tinko("Tinko Tinchev", 50);
    Course LP("Logichesko programirane", 200);
    Course EAI("EAI", 100);
    Course TM("Teoriya na mnojestvata", 50);

    tinko.add(LP);
    tinko.add(EAI);
    tinko.add(TM);


    return 0;
}