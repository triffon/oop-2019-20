#ifndef FACULTY_H
#define FACULTY_H


class Faculty
{
    char name[10]="";
    public:
        Faculty();
        Faculty(char * name);
        Faculty(const Faculty& other);
        Faculty& operator=(const Faculty& other);
        ~Faculty();
        const char * getName()const;
    protected:

    private:
};

#endif // FACULTY_H
