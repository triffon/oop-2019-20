#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H


class SmartPointer
{
    int *ptr;  // Actual pointer
public:
   SmartPointer(int *p = nullptr);

   // Destructor
   ~SmartPointer();

   // Overloading dereferencing operator
   int& operator*();
};

#endif // SMARTPOINTER_H
