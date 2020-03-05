struct faculty{
    char name[10];
};
class Student{
    faculty f;
    int fNum;
    char * name;
public:
    Student();
    Student(int _fNum,const char * _name);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();
    char * getName();
};
