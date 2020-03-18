#ifndef __RSTACK_HPP
#define __RSTACK_HPP

class ResizingStack {
    int* a;
    int top; // индекс на последно включения елемент в стека
    unsigned capacity; // текущ капацитет на стека

    // проверка дали стекът си е стигнал капацитета
    bool full() const;

    // разширяване на стека
    void resize();
public:
    // създаване на празен стек 
    ResizingStack();

    // унищожаване на стека
    ~ResizingStack();

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