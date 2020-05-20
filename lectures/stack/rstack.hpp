#ifndef __RSTACK_HPP
#define __RSTACK_HPP

#include "abstract_stack.hpp"

class ResizingStack : public AbstractStack<int> {
    int* a;
    int top; // индекс на последно включения елемент в стека
    unsigned capacity; // текущ капацитет на стека

    // проверка дали стекът си е стигнал капацитета
    bool full() const;

    // разширяване на стека
    void resize();

    // копиране на стека
    void copy(int* othera);
public:
    // създаване на празен стек 
    ResizingStack();

    // конструктор за копиране
    ResizingStack(ResizingStack const&);

    // операция за присвояване
    ResizingStack& operator=(ResizingStack const&);

    // унищожаване на стека
    ~ResizingStack();

    // проверка за празнота
    bool empty() const;

    // включване на елемент
    void push(int const& x);

    // изключване на елемент
    int pop();

    // поглеждане на последно включения елемент
    int peek() const;
};

#endif