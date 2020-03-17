# Семинар 2, Група 5

### 1. Дефиниране и използване на структури

Дефиниране на структури:

```cpp
struct point {
    double x, y;
};
```
```cpp
struct book {
     char name[41], author[31];
     int year;
     double price; 
};
```

Възможно е влагане на структури в дефиницията:

```cpp
struct xx {
    int a, b, c;
};
struct pom {
    int a;
    double b;
    char c;
    xx d;
};
```

**Не е допустима** рекурсивна дефиниция:
```cpp
struct zz {
    zz id;
};
```

Допустимо е, чрез указател:
```cpp
struct zz {
    zz * id;
};
```
Деклариране на структури:
```cpp
// декларация
struct list; 

// декларация + дефиниция
struct link {
    link * pred;
    link * succ;
    list * member;
};

// декларация + дефиниция
struct list {
    link * head;
}
```
Декларация и инициализация на променливи:
```cpp
point p1, p2 = {5.2, -2};
pom z1 = {1, 2.1, 'c', {1, 2, 3}}; 
```

Дефиниране на променлива от тип структура без име:
```cpp
struct {
    int x;
    double y;
} p, q = {-2, -1.6};
```
Достъпване до полетата на променлива от тип структура:
```cpp
p.x = 10;
q.x;
```
Присвояване на стойност:
```cpp
p = q;
```

### 2. Указатели към структури
```cpp
struct point {
    double x, y;
};
point a1, a2;
point * p = &a1;
p = &a2;
```
Достъп до полетата, чрез указател:
```cpp
p->x = 10;
p->y = 12;
```

### 3. Абстракция със структури данни

Целта е програмата да работи с "абстрактни данни". Такива данни са определени от множество функции: **конструктори**, **селектори** и **предикати**.

**Задача 1:** Да се напише програма, която реализира операциите събиране, изваждане, умножение и деление на рационални числа. Нека всяко рационално число да се състои от цели числа, които са съответно числител и знаменател.
Примерно решение: task1_solution.cpp.

### 4. От структури към класове
**Дефиниция:** Виртуален тип данни, за който се изисква информационно скриване на реализацията на типа, а също пакетиране на данните и операциите в едно цяло се нарича **абстрактен**.
Структурата от решението на Задача 1 не може да се разглежда като абстрактен тип данни рационално число.
В езика C++ се допуска полетата на структури да са функции:
```cpp
#include <iostream>
#include <cmath>

struct point {
    double x, y;
    double distanceTo(point & p) {
        return hypot(p.x - x, p.y - y);
    }
};

int main() {
    point p1 = {1, 2};
    point p2;
    p2.x = 10;
    p2.y = 2;
    std::cout << p1.distanceTo(p2) << std::endl;
    return 0;
}
```
Това позволява обединяването на представянето на типа данни с неговите основни операции.
Функциите могат да се дефинират и извън дефиницията на структурата по следния начин:
```cpp
#include <iostream>
#include <cmath>

struct point {
    double x, y;
    double distanceTo(point &);
};

double point::distanceTo(point & p) {
    return hypot(p.x - x, p.y - y);
}

int main() {
    point p1 = {1, 2};
    point p2;
    p2.x = 10;
    p2.y = 2;
    std::cout << p1.distanceTo(p2) << std::endl;
    return 0;
}
```
В езика C++ е възможно да се специфицира и достъпа до определени данни на структурите, чрез етикетите **public** и **private**. Ако са пропуснати се приема, че всичко е **public**. Специфицираните като **private** са достъпни само вътрешно в структурата.

Пример:
```cpp
#include <iostream>
#include <cmath>

struct point {
    private:
        double x, y;
    public:
        void makePoint(double, double);
        double distanceTo(point &);
};

// конструктор
void point::makePoint(double _x, double _y) {
    x = _x;
    y = _y;
}

double point::distanceTo(point & p) {
    return hypot(p.x - x, p.y - y);
}

int main() {
    // x и y са private => point p1 = {1, 2};
    
    point p1, p2;

    // x и y са private => p2.x = 10; е невалиден израз

    // инициализация, чрез конструктор
    p1.makePoint(1, 2);
    p2.makePoint(10, 2);
    
    std::cout << p1.distanceTo(p2) << std::endl;
    
    return 0;
}
```

**Задача 2:** Да се преработи програмата от Задача 1, така че да се дефинира абстрактен тип за рационално число.
Примерно решение: task2_solution.cpp.
