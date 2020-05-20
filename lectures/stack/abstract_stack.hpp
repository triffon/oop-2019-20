#ifndef __ABSTRACT_STACK_HPP
#define __ABSTRACT_STACK_HPP

template <typename T>
class AbstractStack {
public:
    // проверка за празнота
    virtual bool empty() const = 0;

    // включване на елемент
    virtual void push(T const& x) = 0;

    // изключване на елемент
    virtual T pop() = 0;

    // поглеждане на последно включения елемент
    virtual T peek() const = 0;

    // виртуален деструктор
    virtual ~AbstractStack() {}
};

#endif