#ifndef STUDENT_H
#define STUDENT_H
#include "Faculty.h"

class Student
{
    Faculty f;
    int fNum;
    int x;
    public:
        Student(Faculty f = Faculty(),int fNum = 0,int x = 0);
        int getX();
        ~Student();
        int getfNum();
        const char * getFacultyName()const;
    protected:

    private:
};

#endif // STUDENT_H
