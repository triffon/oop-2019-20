#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<class T>
class DynamicArray
{
    T * arr;
    int size;
    int max;
    public:
        DynamicArray();
        T& operator[](int index);
        void append(T element);
        //void insertAt(int position, int element);
        void removeAt(int position);
        int getSize();
        ~DynamicArray();

    protected:

    private:
        void increase();
        void decrease();
        void checkForValidIndex(int index);
};
/// Why am I doing this include here? Am I mad?
/// Because templates are blueprints for creating classes/functions
/// You can't compile a template class directly
/// You can only compile classes created from it with specific template parameters
/// thus you need to either explicitly instantiate all of these classes
/// or include the implementation in the header so everywhere you make such classes
/// you have access to the full blueprint
/// More info here:
/// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
#include "DynamicArray.tpp"

#endif // DYNAMICARRAY_H
