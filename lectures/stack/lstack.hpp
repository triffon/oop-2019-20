#ifndef __LSTACK_HPP
#define __LSTACK_HPP

struct StackElement {
    int data;
    StackElement* next;
};

class LinkedStack {
    StackElement* top; // указател към двойната кутия, която е на върха на стека
public:
    // създаване на празен стек 
    LinkedStack();

    // унищожаване на стек
    ~LinkedStack();

    // проверка за празнота
    bool empty() const;

    // включване на елемент
    void push(int x);

    // изключване на елемент
    int pop();

    // поглеждане на последно включения елемент
    int peek() const;
};

#endif