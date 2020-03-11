#include <iostream>
#include <cassert>
#include "stack.hpp"
#include "rstack.hpp"
#include "lstack.hpp"

char toDigit(unsigned digit) {
    if (digit < 10)
        return '0' + digit;
    else
        return 'A' + (digit - 10);
}

void printInK(unsigned n, unsigned k) {
    if (n == 0) {
      std::cout << 0;
    } else {
        Stack s;
        while (n > 0) {
            s.push(n % k);  // добавяме поредния остатък в стека
            n /= k;
        }
        while (!s.empty())
            std::cout << toDigit(s.pop());
    }
}

void testConvertToK() {
    unsigned n;
    std::cout << "Моля, въведете n: ";
    std::cin >> n;
    std::cout << "Моля, въведете бройна система: ";
    unsigned k;
    std::cin >> k;
    assert(k >= 2); // !!!
    std::cout << n << "(10) = ";
    printInK(n, k);
    std::cout << "(" << k << ")" << std::endl;
    // 42(10) = 101010(2)
}

bool isOpenParenthesis(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isCloseParenthesis(char c) {
    return c == ')' || c == ']' || c == '}';
}

bool matchParentheses(char open, char close) {
    return open == '(' && close == ')' || open == '[' && close == ']' || open == '{' && close == '}';
}

bool checkParentheses(char const* s) {
    LinkedStack stack;
    while (*s) {
        if (isOpenParenthesis(*s))
            stack.push(*s);
        else if (isCloseParenthesis(*s))
                // трябва да проверим дали за затварящата скоба *s на върха на стека има съответстваща
                // отваряща скоба
                // assert(isOpenParenthesis(stack.peek()));
                if (stack.empty() || !matchParentheses(stack.pop(), *s))
                    return false;
        s++;
    }
    return stack.empty(); // ако стекът е непразен, значи имаме незатворена отваряща скоба
}

void testCheckParentheses() {
    char s[100] = "";
    std::cout << "Въведете низ: ";
    std::cin.getline(s, 100);
    std::cout << "В низа скобите ";
    if (!checkParentheses(s))
        std::cout << "НЕ ";
    std::cout << "са коректно поставени" << std::endl;
}

void testCheckParenthesesAuto() {
    assert(checkParentheses("(2+3)") == true);
    assert(checkParentheses("(2+3-[5/4])") == true);
    assert(checkParentheses("(2+3") == false);
    assert(checkParentheses("([{([{([{([{([{([{([{([{([{([{([{3}])}])}])}])}])}])}])}])}])}])}])") == true);
    assert(checkParentheses("(2+[3-4)]") == false);
    assert(checkParentheses("(2+[3-4)]") == false);
    assert(checkParentheses("([{([{([{([{([{([{([{([{([{([{([{3}])}])}])}])}])]})}])}])}])}])}])") == false);
    assert(checkParentheses("") == true);
    assert(checkParentheses(")(") == false);
    assert(checkParentheses("(2+[3-4])}+5-6") == false);
    assert(checkParentheses(")))))))((((") == false);
    assert(checkParentheses(")") == false);
    assert(checkParentheses("((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((x))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))") == true);
    // ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    // ))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
    std::cout << "Тестовете минават успешно" << std::endl;
}

int main() {
    // testConvertToK();
    // testCheckParentheses();
    testCheckParenthesesAuto();
    return 0;
}