#ifndef ITERATOR_H
#define ITERATOR_H
template<typename T>
class Iterator{
public:
    virtual T getCurrent() = 0;
    virtual void next() = 0;
};
#endif