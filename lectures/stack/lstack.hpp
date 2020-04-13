#ifndef __LSTACK_HPP
#define __LSTACK_HPP

struct StackElement {
    int data;
    StackElement* next;
};

class LinkedStack {
    StackElement* top; // указател към двойната кутия, която е на върха на стека

    void copy(LinkedStack const&);

    void erase();
public:
    // създаване на празен стек 
    LinkedStack();

    // унищожаване на стек
    ~LinkedStack();

    // конструктор за копиране
    LinkedStack(LinkedStack const&);

    // операция за присвояване
    LinkedStack& operator=(LinkedStack const&);

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