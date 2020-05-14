#ifndef DYNAMICARRAYITERATOR_H
#define DYNAMICARRAYITERATOR_H
#include "Iterator.h"
#include <assert.h>
template<class T>
class DynamicArrayIterator : public Iterator<T>{
public:
    T* base;
    int position; 
    int size;
    void next(){
        position++;
    }
    T getCurrent(){
        assert(position<size);
        return base[position];
    }
};

#endif /* DYNAMICARRAYITERATOR_H */
