class ArrayStack{
    int arr[100];
    int current; ///point to the first free index in the array
public:
    ArrayStack();
    void push(int element);
    void pop();
    int peek();
    bool empty();
};