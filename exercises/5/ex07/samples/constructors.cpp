#include <iostream>

class Base {

public:
    Base() {
        std::cout << "Base()" << std::endl;
        a1 = -1;
        a2 = -2;
    }
    Base(int _a1, int _a2) {
        std::cout << "Base(int, int)" << std::endl;
        a1 = _a1;
        a2 = _a2;
    }
    ~Base() {
        std::cout << "~Base()" << std::endl;
    }
    void print() const {
        std::cout << "Base.print(): a1 = " << a1 << " a2 = " << a2 << std::endl; 
    }

protected:
    int a1;

private:
    int a2;

};

class Der : public Base {

public:
    Der() : Base(-1, -2) {
        std::cout << "Der()" << std::endl;
        a3 = -3;
        a4 = -4;
    }
    Der(int _a3, int _a4) : Base() {
        std::cout << "Der(int, int)" << std::endl;
        a3 = _a3;
        a4 = _a4;
    }
    ~Der() {
        std::cout << "~Der()" << std::endl;
    }
    void print() const {
        std::cout << "Der.print(): a1 = " << a1 << " a3 = " << a3 << " a4 = " << a4 << std::endl; 
    }

protected:
    int a3;
    int a4;

};

class Der2 : public Der {

public:
    Der2() : Der(-1, -2) {
        std::cout << "Der2()" << std::endl;
        a3 = -3;
        a4 = -4;
    }
    ~Der2() {
        std::cout << "~Der2()" << std::endl;
    }
};

int main() {
    //Base b1(1, 2);
    //b1.print();

    //Der d1;
    //d1.print();
    
    //Der d2(7, 8);
    //d2.print();

    Der2 d2;
    return 0;
}