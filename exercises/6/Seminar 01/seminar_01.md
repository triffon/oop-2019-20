<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Поглед върху Обектното-ориентирано програмиране](#%D0%BF%D0%BE%D0%B3%D0%BB%D0%B5%D0%B4-%D0%B2%D1%8A%D1%80%D1%85%D1%83-%D0%BE%D0%B1%D0%B5%D0%BA%D1%82%D0%BD%D0%BE%D1%82%D0%BE-%D0%BE%D1%80%D0%B8%D0%B5%D0%BD%D1%82%D0%B8%D1%80%D0%B0%D0%BD%D0%BE-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%B8%D1%80%D0%B0%D0%BD%D0%B5)
  - [Какво е "програмна парадигма"?](#%D0%BA%D0%B0%D0%BA%D0%B2%D0%BE-%D0%B5-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BD%D0%B0-%D0%BF%D0%B0%D1%80%D0%B0%D0%B4%D0%B8%D0%B3%D0%BC%D0%B0)
  - [Процедурно програмиране](#%D0%BF%D1%80%D0%BE%D1%86%D0%B5%D0%B4%D1%83%D1%80%D0%BD%D0%BE-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%B8%D1%80%D0%B0%D0%BD%D0%B5)
  - [Обектно-ориентирано програмине](#%D0%BE%D0%B1%D0%B5%D0%BA%D1%82%D0%BD%D0%BE-%D0%BE%D1%80%D0%B8%D0%B5%D0%BD%D1%82%D0%B8%D1%80%D0%B0%D0%BD%D0%BE-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%B8%D0%BD%D0%B5)
- [Принципи в Обектното-ориентирано програмиране](#%D0%BF%D1%80%D0%B8%D0%BD%D1%86%D0%B8%D0%BF%D0%B8-%D0%B2-%D0%BE%D0%B1%D0%B5%D0%BA%D1%82%D0%BD%D0%BE%D1%82%D0%BE-%D0%BE%D1%80%D0%B8%D0%B5%D0%BD%D1%82%D0%B8%D1%80%D0%B0%D0%BD%D0%BE-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%B8%D1%80%D0%B0%D0%BD%D0%B5)
  - [Енкапсулация](#%D0%B5%D0%BD%D0%BA%D0%B0%D0%BF%D1%81%D1%83%D0%BB%D0%B0%D1%86%D0%B8%D1%8F)
  - [Абстракция](#%D0%B0%D0%B1%D1%81%D1%82%D1%80%D0%B0%D0%BA%D1%86%D0%B8%D1%8F)
  - [Наследяване](#%D0%BD%D0%B0%D1%81%D0%BB%D0%B5%D0%B4%D1%8F%D0%B2%D0%B0%D0%BD%D0%B5)
  - [Полиморфизъм](#%D0%BF%D0%BE%D0%BB%D0%B8%D0%BC%D0%BE%D1%80%D1%84%D0%B8%D0%B7%D1%8A%D0%BC)
- [Header files](#header-files)
- [Структури (Structures)](#%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B8-structures)
  - [Примерна задача със и без структура](#%D0%BF%D1%80%D0%B8%D0%BC%D0%B5%D1%80%D0%BD%D0%B0-%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-%D1%81%D1%8A%D1%81-%D0%B8-%D0%B1%D0%B5%D0%B7-%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B0)
  - [Какво е структура](#%D0%BA%D0%B0%D0%BA%D0%B2%D0%BE-%D0%B5-%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B0)
  - [Как дефинираме структура](#%D0%BA%D0%B0%D0%BA-%D0%B4%D0%B5%D1%84%D0%B8%D0%BD%D0%B8%D1%80%D0%B0%D0%BC%D0%B5-%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B0)
  - [Как използваме структура](#%D0%BA%D0%B0%D0%BA-%D0%B8%D0%B7%D0%BF%D0%BE%D0%BB%D0%B7%D0%B2%D0%B0%D0%BC%D0%B5-%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B0)
    - [Инициализация на променлива](#%D0%B8%D0%BD%D0%B8%D1%86%D0%B8%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F-%D0%BD%D0%B0-%D0%BF%D1%80%D0%BE%D0%BC%D0%B5%D0%BD%D0%BB%D0%B8%D0%B2%D0%B0)
    - [Структури и функции](#%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B8-%D0%B8-%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%B8)
    - [Оператор точка](#%D0%BE%D0%BF%D0%B5%D1%80%D0%B0%D1%82%D0%BE%D1%80-%D1%82%D0%BE%D1%87%D0%BA%D0%B0)
    - [Влагане на структури](#%D0%B2%D0%BB%D0%B0%D0%B3%D0%B0%D0%BD%D0%B5-%D0%BD%D0%B0-%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B8)
    - [Масиви от структури](#%D0%BC%D0%B0%D1%81%D0%B8%D0%B2%D0%B8-%D0%BE%D1%82-%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B8)
  - [Указатели към структури](#%D1%83%D0%BA%D0%B0%D0%B7%D0%B0%D1%82%D0%B5%D0%BB%D0%B8-%D0%BA%D1%8A%D0%BC-%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B8)
      - [Оператор ->](#%D0%BE%D0%BF%D0%B5%D1%80%D0%B0%D1%82%D0%BE%D1%80--)
  - [Задачи за упражнение](#%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8-%D0%B7%D0%B0-%D1%83%D0%BF%D1%80%D0%B0%D0%B6%D0%BD%D0%B5%D0%BD%D0%B8%D0%B5)
    - [Задача 1](#%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-1)
    - [Задача 2](#%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-2)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Поглед върху Обектното-ориентирано програмиране

## Какво е "програмна парадигма"?

Думата [парадигма](https://bg.wikipedia.org/wiki/%D0%9F%D0%B0%D1%80%D0%B0%D0%B4%D0%B8%D0%B3%D0%BC%D0%B0) означава **модел на мислене**.
Програмна парадигма е моделът на мислене, който използваме при решаването на даден проблем чрез код. В курса **Увод в програмирането** използвахме  програмната парадигма **Процедурно програмиране**. Този семестър ще разгледаме друга такава парадигма - **Обектно-ориентирано програмиране**.

---

## Процедурно програмиране

Когато използваме процедурно програмиране, ние разбиваме програмите си на **променливи, структури и функции**, които използваме за да решим дадения проблем. Функциите работят върху променливите и структурите като ги променят или правят някакви изчисление чрез тях. Те описват как да стигнем от точка **А** до точка **Б**, в следствие на което нашата програма става описание на решението, например - прочети 6 числа от конзолата, провери дали образуват равностранен триъгълник, покажи "Да" или "Не" в конзолата.

---

## Обектно-ориентирано програмине

За разлика от **процедурното програмине**, **обектно-ориентираното програмиране(ООП)**, се основава на идеята за **обекти**, които обединяват **функциите** и **данните**, върху които работят тези **функции** в едно. Пример за познат обект е  `std::cin`, който съдържа познатия **метод** `std::cin.getline()`. Начинът на мислене при решаването на проблеми вече е различен, започваме да мислим **какви обекти са ни нужни и какви са взаимодействията между тях**.
> Когато говорим за обекти, използваме **метод** вместо **функция**.

> **Функция**, която вече е обвързана с дадени данни, тоест вече е част от обект се нарича **метод**.

---

# Принципи в Обектното-ориентирано програмиране

ООП има 4 основни принципа върху, които полага основите си. Те са енкапсулация, абстракция, наследяване, полимормизъм.

## Енкапсулация
Енкапсулацията отговаря за обединяването на данните и функциите, които работят върху тях в един обект. Използва се също за скриване на вътрешното състояние на обекта. Например, не знаем какво има в `std::cin`, нито какви са стойностите на нещата вътре в него. Все пак това не ни спира да използваме функционалността, която този обект ни предоставя.

---

## Абстракция
Абстракцията е принципът, който се грижи за сложността на кода, използваме **абстракция**, за да прикрием ненужни детайли на този, които използва обектите, които сме създали. Например, `std::cin.getline()` е абстракция, скрили сме ненужните детайли зад извикването на една функция. Това е и една от причините, заради които използваме функции в процедурното програмиране - скриваме сложността.

> На практика скриването на имплементацията идва от комбинацията между **принципа за абстракция** и **принципа за енкапсулация**. Тъй като те съществуват само на теория, C++ ни дава пособия, които да използваме, за да постигнем техния ефект. За момента няма да задълбаваме в езика, а само ще дадем пример в реалния живот. Една съвременна кафе машина може да прави кафе с едно натискане на бутон. Всичко, което се случва след натискането на бутона не ни интересува - това е **абстракция**, имаме възможността да използваме някаква функционалност(натискането на бутона), използваме я и не се интересуваме от това как това се изпълнява. **Енкапсулацията** има две части, _първата_ е че всичко, което е нужно за направата на кафе е в кафе машината, _втората_ е свързана със скриването - кафе машината има **кутия**, която ни спира да видим какво става вътре, по същия начин C++ ще ни предостави пособия, с които можем да направим части от нашите обекти да са в **кутията**, а други да могат да се натискат.

---

## Наследяване
Наследяването дава възможността да се "наследяват" свойствата на дадени обекти от нови такива.
> Например, има голям шанс детето на две черни котки, да е черно котенце.

---

## Полиморфизъм
Полиморфизмът ни дава възможността да извършваме различни действия спрямо ситуацията, в която сме. Този принцип стъпва върху принципа на наследяването в програмирането.

---

Една доста добра асоциация на ООП с реалния живот. Ще започва да прави смисъл повече и повече с прогреса на курса.
>God is an OOPS programmer

>God is omnipotent, merciful, forgiving, almighty and a bunch of other things, but at heart he was an OOP programmer, and he created the concept. Let us understand how this guy created humans, after his initial forays with algae and bacteria.

>**Class**: He first created a class called Human. Added some attributes and functions. Attributes such as eyes, ears, brain, legs. Functions such as walk, talk, think, sleep etc.

>**Inheritance** : He next created 2 sub classes - Man and Woman. They inherited the attributes and functions of class human. However he added some attributes and functions specific to these classes. For the man and the woman class, he added attributes specific to their anatomy. Like a special Adam's apple for the man, the breasts for the woman and a few other specific ones. He added functions specific to these classes, for instance he gave the function "GiveBirthToNewHuman" to the woman class. It was a complex function intended to spawn new objects and he did a great job there.

>**Polymorphism** : God gave both classes some polymorphic capabilities wherein they could act differently based on the input given. For instance, the function "ConsumeThroughMouth" could behave differently based on the type of input given. If food was given, the function has extra logic to use the teeth to grind it. It milk or water was given, the function used the lips in a pout shape instead of using the teeth. So different use of attributes. So God patented this fancy sounding term and further also brought in a new associated term called function overloading as he was overloading multiple capabilites onto the function "ConsumeThroughMouth"

>**Abstraction** : God thought it would be good if not many details and only what was necessary was given to the external world. For instance the woman and the man can talk. The internal details of how the neural network in the brain processed the signals received and in turns sends a signal to produce a sound is not exposed to the recepient or the outside world. Hence the paradigm of abstraction.

>**Encapsulation**: God's idea of combining the data and functions together to make it a working unit. God patented it with a fancy name "Encapsulation" for that, since he was on a roll with the names already - polymorphism, abstraction and what not!

>**Object**: Finally, it was time to have some fun, and create some instances of the classes made. And viola, God created Adam, Eve, Chunnu, Munnu, Raveena, Sunny, Mari, Salman, John, Samuel, Anoushka, Rama and many many more. And that's how this OOPS programmer created Human Life.

# Header files
[Този клип](https://www.youtube.com/watch?v=9RJTQmK0YPI) обяснява това, което разказа Яската. Можем да научим доста за C++ от канала на [The Cherno](https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb).

---

# Структури (Structures)

## Примерна задача със и без структура
Нека първо видим пример как да изглежда дадено решение на задача със и без структура. Задачата е следната:

**Напишете програма, която смята разстояние между две точки в тримерното пространство подадени от конзолата и изписва резултата.**

Решение със знанията, които имаме до сега:
```c++
#include <iostream>

double distance3d(double x1, double y1, double z1, double x2, double y2, double z2)
{
    double distance = sqrt((x1 - x2) * (x1 - x2) +
        (y1 - y2) * (y1 - y2) +
        (z1 - z2) * (z1 - z2));

    return distance;
}

int main() {
    double x1, y1, z1, x2, y2, z2;

    std::cout << "Enter points coordinates: " << std::endl;
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    double distance = distance3d(x1, y1, z1, x2, y2, z2);

    std::cout << "The distance is " << distance << std::endl;
}
```

Решение чрез структура:
```c++
#include <iostream>

struct Point3D {
    double x;
    double y;
    double z;
};

// Function now takes only 2 parameters instead of 6.
double distance3d(Point3D p, Point3D q)
{
    double distance = sqrt((p.x - q.x) * (p.x - q.x) +
        (p.y - q.y) * (p.y - q.y) +
        (p.z - q.z) * (p.z - q.z));

    return distance;
}

int main() {
    Point3D p, q;

    std::cout << "Enter points coordinates: " << std::endl;
    std::cin >> p.x >> p.y >> p.z >> q.x >> q.y >> q.z;

    double distance = distance3d(p, q);

    std::cout << "The distance is " << distance << std::endl;
}
```
Кодът, който пишем вече използва наш тип, който представя **точка в тримерното пространство** - `Point3D`. Това ни дава по-добро ниво на абстракция, кодът който пишем е по-прецизен и носи повече информация когато го четем. Вече работим с "точки", а не просто с летящи `double` стойности. Този пример е разбираем и в двата случая, но при по-сложни структури, например **адрес**, който включва град, квартал, блок, апартамент, етаж, стая и т.н. разликата става пределно ясна. Нека сега разгледаме по-формално какво се случи при това пренаписване на решението с използването на структура.

---

## Какво е структура
Структура е специален тип данни, който ние дефинираме. Структурата действа като "обвивка" на дадени данни, които логически принадлежат заедно, както точката в тримерното пространство или адресът.

![struct image](assets/struct.png)

Тъй като не можах да намеря адекватна снимка в интернет, направих тази, нямах стрелка, затова използвах лопата, колко иронично.

Структурата(синия правоъгълник) става обвивка за трите прости променливи, тъй като вече "външният" свят не знае за тяхното съществуване, а само за съществуването на структурата `Point3D`, тяхното използване става по-различно - само чрез самата структура, повече за това по-надолу.

---

## Как дефинираме структура
Дефинирането на структура става със запазената ключова дума `struct`.

```c++
struct Point2D{
    double x;
    double y;
};
```
След `struct` следва **името** на структурата, последвани от къдрави скоби `{}`, като след затварящата кръдвата скоба **винаги** трябва да има точка и запетая `;`.
Между къдравите скоби описваме типовете и имената на променливите(данните), за които искаме структурата да е обвивка.

## Как използваме структура


Структурата е просто тип. Директно можем да правим променливи от този тип, можем да дефинираме функции, които приемат параметри от този тип. Достъпът до стойностите на структурата е малко различен, използва **оператор точка**.

### Инициализация на променлива
Структурите са просто нов тип, които ние сме дефинирали, няма нищо ново при инициализацията на променливи от такъв тип.
```c++
Point2D point;
```

---
### Структури и функции
Отново, използваме ги както използваме останалите типове, няма нищо различно при използването им във функции
```c++
Point2D initDefaultPoint()
{
    Point2D point;
    point.x = 0;
    point.y = 0;

    return point;
}

double distance2D(Point2D first, Point2D second)
{
    ...
}
```

---

### Оператор точка

**Тук се появява първата разлика между изпозлването на променливите както знаем и променливи, които са от тип, които ние сме дефинирали**.

Вече не работим директно със двете променливи `x` и `y`, а със структурата, ако искаме да ги достъпим, например да им дадем стойност `0`, трябва да използваме оператор **.**(оператор точка):
```c++
point.x = 0;
point.y = 0;
```
Семантиката на този оператор има значение на **`member of`**, тоест чрез него можем да достъпим променливите, които нашата структура "обвива". До сега използването на променливата беше еднозначно, всяка променлива имаше **име** и **една стойност**, която съответства на това име. При структурите това се променя, имаме едно име `point` и две стойности, които можем да достъпим - `p.x` и `p.y`.

---
### Влагане на структури
Типовете на данните в самата структура може сами по себе си да са структури:
```c++
struct Point3D {
  Point2D point2d;
  double z;
};
```
**Това е лош пример, не го правим, с обучителна цел е.**

Нещо, за което трябва да внимаваме е, че при влагане на структури, операторът точка трябва да се използва за всяка структура:
```c++
Point3D point;
point.point2d.x = 5;
point.point2d.y = 5;
point.z = 5;
```

---

### Масиви от структури
При използването на масиви със структури няма нищо различна, комбинираме новите си знания за структури със знанията си за масиви.

Примерен код, които **създава масив от точки в двумерното пространство, прочита ги от конзолата и показва коя е точката най-близко де центъра**. Използваме динамична памет, за да си я припомним.
```c++
#include <iostream>

// Structures.
struct Point2D {
    double x;
    double y;
};

// Functions.
double distance2d(Point2D p, Point2D q)
{
    double distance = sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));

    return distance;
}

Point2D getClosestPointToTheCenter(Point2D* points, size_t size)
{
    // Creates a point with x = 0 and y = 0.
    // Same usage as with arrays: int numbers[] = { 1, 2, 3, 4 };
    Point2D center = { 0, 0 };

    // Initialize the closest point to be the first one by default.
    Point2D closest = points[0];
    double minDistance = distance2d(center, closest);

    double currentDistance;
    for (size_t i = 0; i < size; i++)
    {
        currentDistance = distance2d(center, points[i]);

        if (currentDistance < minDistance)
        {
            closest = points[i];
            minDistance = currentDistance;
        }
    }

    return closest;
}

void fillArray(Point2D* points, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> points[i].x >> points[i].y;
    }
}

int main()
{
    size_t size;
    std::cin >> size;

    Point2D* points = new(std::nothrow) Point2D[size];

    if (points == nullptr)
    {
        return 1;
    }

    fillArray(points, size);
    Point2D closest = getClosestPointToTheCenter(points, size);

    std::cout << "Closest point is (" << closest.x << ", " << closest.y << ")." << std::endl;

    delete[] points;

    return 0;
}

```

## Указатели към структури
Нека разгледаме пример с указател към структура. Важното тук е да не забравя разликата, че **можем да работим с указатели без да работим с динамична памет**.

**Нека създадем структура и указател към нея и видим как се работи със полетата на структурата чрез указателя.**
> Полета наричаме променливите в дадена структура, в случая с точка в двумерното пространство, без структура бихме имали 2 променливи `x` и `y`, a когато имаме структура, имаме една променлива
`point` с две полета в нея - `х` и `y`, които достъпваме чрез нея и оператор точка - `point.x`, `point.y`.

```c++
int main()
{
    Point2D point = { 0, 0 };
    Point2D* pointer = &point;

    std::cout << "Value of field 'x' is: " << point.x << std::endl;
    std::cout << "Value of field 'x' is: " << (*pointer).x << std::endl;

    return 0;
}
```
Тъй като работим с указатели, трябва първо да **дереференцираме** и след това да вземем стойността на `x`. За наш късмет това е толкова често срещане сред програмистите, които използват C++, че е добавено в езика с друг синтаксис за по-лесно използваме.

#### Оператор ->

```c++
int main()
{
    Point2D point = { 0, 0 };
    Point2D* pointer = &point;

    std::cout << "Value of field 'x' is: " << point.x << std::endl;
    std::cout << "Value of field 'x' is: " << (*pointer).x << std::endl;
    std::cout << "Value of field 'x' is: " << pointer->x << std::endl;

    return 0;
}
```
Няма никаква разлика между `(*pointer).x` и `pointer->x`, означават напълно едно и също нещо. Оператор стрелкичка е добавен в езика за наше удобство, **използваме го само когато има искаме да достъпи поле на наша структура чрез указател към нея**.

---
## Задачи за упражнение

### Задача 1
Напишете програма, която чете от конзолата точки в двумерното пространство, които описват правоъгълник и намерете периметъра и лицето на прочетения правоъгълник. Вие отговаря за структурата и представянето на обектите във вашата програма. Моделирайте решението по свой избор, но използвайте структури и функции, които използват тези структури.

---
### Задача 2
Съставете структура, която представя **комплексно число**, използвайте тази структура, за да напишете програма, която събира и умножава комплексни числа.

---
