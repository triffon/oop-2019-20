#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


class DynamicArray
{
    int * arr;
    int size;
    int max;
    public:
        DynamicArray();
        int& operator[](int index);
        void append(int element);
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

#endif // DYNAMICARRAY_H
