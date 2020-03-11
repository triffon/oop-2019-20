const int MAX_STACK = 100;
class Stack {
    int a[MAX_STACK];
    int top; // индекс на последно включения елемент в стека
public:
    // създаване на празен стек 
    Stack();

    // проверка за празнота
    bool empty() const;

    // включване на елемент
    void push(int x);

    // изключване на елемент
    int pop();

    // поглеждане на последно включения елемент
    int peek() const;
};