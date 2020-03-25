//
// Created by yasen on 2/29/20.
//

#ifndef STUDENTSANDTEACHERS_STUDENT_H
#define STUDENTSANDTEACHERS_STUDENT_H


class Student {
public:
    Student();
    Student(unsigned _facultyNumber, const char* _name, const char* _major, unsigned short _group);

public:
    unsigned getFacultyNumber() const;
    const char* getName() const;

    const char* getMajor() const;
    void setMajor(const char* newMajor);

    unsigned short getGroup() const;
    void setGroup(unsigned short newGroup);

public:
    void printInformation() const;
    void readFromConsole();

private:
    bool isValidFN(unsigned FN) const;
    bool isValidGroup(unsigned short _group) const;
    bool isValidMajor(const char* _major) const;
private:
    unsigned facultyNumber;
    char name[51];
    char major[33];
    unsigned short group;

private:

    static const unsigned short countMajors = 5;
    const char* majors[countMajors] = { "Informatics",
                                        "Computer Science",
                                        "Software Engineering",
                                        "Mathematics and Informatics",
                                        "Mathematics"
                                        };
};


#endif //STUDENTSANDTEACHERS_STUDENT_H
