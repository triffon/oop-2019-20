#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>

class Student
{
    friend std::istream& operator>>(std::istream&,Student&);
    friend std::ostream& operator<<(std::ostream&,Student&);
    public:
        Student(const char * name=nullptr);

        void setFacultyNumber(int facultyNumber);
        int getFacultyNumber()const;

        void setName(const char * name);
        const char * getName()const;

        //virtual ~Student();

    protected:

    private:
        char name[16];
        int facultyNumber;
};

#endif // STUDENT_H
