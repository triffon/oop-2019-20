<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
![big four meme](assets/big_four.jpg)
- [Голямата четворка](#%D0%B3%D0%BE%D0%BB%D1%8F%D0%BC%D0%B0%D1%82%D0%B0-%D1%87%D0%B5%D1%82%D0%B2%D0%BE%D1%80%D0%BA%D0%B0)
- [Проблемът](#%D0%BF%D1%80%D0%BE%D0%B1%D0%BB%D0%B5%D0%BC%D1%8A%D1%82)
- [Какво се има предвид](#%D0%BA%D0%B0%D0%BA%D0%B2%D0%BE-%D1%81%D0%B5-%D0%B8%D0%BC%D0%B0-%D0%BF%D1%80%D0%B5%D0%B4%D0%B2%D0%B8%D0%B4)
- [Конструктори, деструктори и динамична памет](#%D0%BA%D0%BE%D0%BD%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D0%BE%D1%80%D0%B8-%D0%B4%D0%B5%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D0%BE%D1%80%D0%B8-%D0%B8-%D0%B4%D0%B8%D0%BD%D0%B0%D0%BC%D0%B8%D1%87%D0%BD%D0%B0-%D0%BF%D0%B0%D0%BC%D0%B5%D1%82)
- [Copy constructor](#copy-constructor)
- [Тhe Big Four imeplemented - Default constructor, Copy constructor, Operator=, Desctructor.](#%D1%82he-big-four-imeplemented---default-constructor-copy-constructor-operator-desctructor)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## Голямата четворка
Днес ще се занимаваме отново с класове, като този път ще полета, които ще се грижат за заделянето и освобождането на динамична памет. Ще разгледаме даден проблем, които не можем да решим с текущите си знания. След това ще покажем как можем да се справим с този проблем чрез използването на динамична памет. След това ще покажем какви проблеми възникват когато използваме динамична памет в нашите класове и как да решим един по един тези проблеми. Ще завършим с обобщение на това, което направим и за финал ще рефакторираме кода, така че да покажем колко лесно можем да постигнем същия ефект с много по-малко код чрез преизползване на функционалност.

## Проблемът
Вие сте софтуерен разработчик, който работи за банка. По принцип вашата банка се справя с всяка една транзакция в момента, в който тя бъде изпратена,но за съжаление вашите шефове са започнали да се притесняват покрай всичките разговори за новия "корона вирус" и искат вие да им помогнете да сложат предпазни мерки в системата, ако случайно нещо се случи и не могат да се обработят транзакциите. Вашият приятел Пеше се е погрижил и е сложил няколко реда код, които записват неуспешните транзакции във файл, вашата задача е напишете клас, които може да чете транзакциите от файла(конзолата за нас) и да позволява лесната работа с тях, тъй като Трифон ще трябва да напише цялата логика зад ръчното им обработване, след като вие му позволите да използва вашия клас.

Една транзакция се описва от **кода** на сметката, от която е произлязла, **кода на самата транзакция**, **сумата** която е изпратена или получена, **балансът** на сметката преди изпълняването на транзакцията и **описанието** на транзакцията, **което може да бъде произволно дълго**.
Кодът на сметката е текст с дължина 4, който включва само големи латински букви. Кодът на самата транзакция е отново текст, който е с дължина 2, но може да включва както и малки, така и големи латински букви. Сумата на самата транзакция е цяло цисло, което може да бъде отрицателно или положително, като можем да считаме че няма да надхвърли 2 000 000. Балансът на сметката също е цяло число, също можем да смятаме, че няма да надхвърли 2 000 000. Считаме една транзакция за невалидна, ако положителен балансът става отрицателен след изпълнението на транзакция. **Не знаете колко транзакции може да има във дадения файл**, може да са 3, но може и да са 300 000, трябва да се погрижите, че всички ще бъдат взети под внимание, независимо от броя им.

Вашият клас трябва да може да се създава чрез конструктор за подразбиране, както и друг конструктор, които да приема някаква стойност за начална големина. Трябва да можете да добавяте нови транзакции(валидирайте транзакцията преди добавянето), да триете транзакции по техния код, и да казвате дали дадена транзакция е вече във вашия клас спрямо подаден код на транзакция. Трябва също да можете да показвате информация за всички транзакции в конзолата - техните кодове и балансът след изпълнението им. Също трябва да предоставяте функционалност, която може да покаже на конзолата колко еднакви транзакции има ваш обект спрямо друг обект от същия клас. Две транзакции са еднакви когато кодът на сметката и кодът на транзакцията съвпадат.


## Какво се има предвид
Нека започнем от данните върху, които ще работим, те са добре описани в самото условие. Една транзакция има няколко полета, които я описват, първоначалната ни мисъл може да е "нека янаправим структура", това не би имало толкова много смисъл, тъй като има доста логика, която е обвързана с една транзакция. Имаме няколко полета, които имат нужда от валидация, както и поле, което е неограничена дължина, това означава, че ще имаме указател, който работи с динамична памет. Нека се абстрахираме от огромния проблем пред нас и да се фокусираме върху това да направим една транзакция затворена система. Нека разгледаме следния клас. От условието можем да заключим, че една транзакция би имала следните полета.
```c++
class Transaction {
    char* m_description;
    char m_accountCode[9];
    char m_code[5];
    int  m_amount;
    int  m_balance;
};
```

## Конструктори, деструктори и динамична памет
Нека се опитаме да направим един **конструктор**, чрез който да инициализираме всички полета на структурата. Тъй като едно полетата ни използва динамична памет, първо трябва да заделим достатъчно място за него. Естествено алокирането на динамична памет ни задължава да я деалокираме, затова трябва да добавим и **деструктор**.
```c++
Transaction(const char* accountCode, const char* code, const char* description, int amount, int balance)
    {
        m_description = new char[strlen(description) + 1];

        strcpy(m_description, description);
        strcpy(m_accountCode, accountCode);
        strcpy(m_code, code);
        m_amount = amount;
        m_balance = balance;
    }

~Transaction()
    {
        delete[] m_description;
    }
```
Вече можем да използваме този клас по следния начин
```c++
    Transaction transaction = Transaction("ABC", "QQ", "Transaction description", -1200, 99999);
```
Нека да добавим и **конструктор по подразбиране**, който да слага **default** стойности на всички полета
```c++
Transaction()
    {
        m_description = new char[1];

        strcpy(m_description, "");
        strcpy(m_accountCode, "");
        strcpy(m_code, "");
        m_amount = 0;
        m_balance = 0;
    }
```

Ако се загледаме в двата **конструктора**, можем да видим, че те са много подобни и всичката логика се повтаря, единствените разлики са стойностите, които се присвояват, нека направим един `private` метод `init`, който да приема параметри, чиито стойности ще бъдат копирани в полетата на нашия клас. След като изнесем логиката в този отделен метод с цел да избегнем повтаряне на кода, нашият клас започва да изгледа така. Доста чисто и спретнато!
```c++
class Transaction {
private:
    char* m_description;
    char m_accountCode[9];
    char m_code[5];
    int  m_amount;
    int  m_balance;

    void init(const char* accountCode, const char* code, const char* description, int amount, int balance)
    {
        m_description = new char[strlen(description) + 1];

        strcpy(m_description, description);
        strcpy(m_accountCode, accountCode);
        strcpy(m_code, code);
        m_amount = amount;
        m_balance = balance;
    }
public:
    Transaction()
    {
        init("", "", "", 0, 0);
    }

    Transaction(const char* accountCode, const char* code, const char* description, int amount, int balance)
    {
        init(accountCode, code, description, amount, balance);
    }

    ~Transaction()
    {
        delete[] m_description;
    }
};
```
Вече можем да създаваме транзакции по два начина:
```c++
int main()
{
    Transaction emptyTransaction;
    Transaction transaction = Transaction("ABCD", "QQ", "Transaction description", -1200, 99999);
}
```
За съжаление в момента имаме проблем - можем да създаваме невалидни транзакции. Трябва да валидираме параметрите, които подаваме и в случай, че те са невалидни, да сложим стойностите по подразбиране за всяко едно такова поле.
За тази цел отиваме в `copy` метода и правим `private set` метод, който ще валидира подадената стойност преди да я запише в полето. В последствие можем да направим методите публични, ако има нужда от тях. Правим тази промяна в `copy` тъй като тя става единичното място в нашия клас, където се променят полетата(поне засега). Нека първо разгледаме какви валидации има нужда да направим:
 * Да проверим дали `m_accountCode` трябва да е с дължина 4 и да включва само големи латински букви.
 * Да проверим дали `m_code` трябва да е с дължина 2 и да включва малки и големи латински букви.
 * Да проверим дали балансът става отрицателен след изпълнение на транзакцията.

Тъй като валидацията дали транзакцията е валидна включва едновременно балансът и сумата, ще добавим и един публичен метод, чрез който може да се изпълна логиката зад валидацията. Целта на този метод е само да носи информация, не искаме да губим информация като сложим стойности 0 на `m_amount` или `m_balance`. Тъй като класът започна да става по-голям правим разделение на `.hpp` и `.cpp` файлове. Файловете вече изглеждат така:
```c++
// Transaction.hpp
#pragma once

#include <iostream>

class Transaction {
private:
    // static variables live for the duration of the program i.e. they are like global variables but they are encapsulated in the class, so that's ok. This is how things were done in C++98.
    static const int ACCOUNT_CODE_LENGTH = 8;
    static const int CODE_LENGTH = 4;

    char* m_description;
    char m_accountCode[ACCOUNT_CODE_LENGTH + 1];
    char m_code[CODE_LENGTH + 1];
    int  m_amount;
    int  m_balance;

    void init(const char* accountCode, const char* code, const char* description, int amount, int balance);
    void setAccountCode(const char* accountCode);
    void setCode(const char* code);
public:
    Transaction();
    Transaction(const char* accountCode, const char* code, const char* description, int amount, int balance);
    ~Transaction();

    bool isValid();
};
```

```c++
// Transaction.cpp
#include "Transaction.hpp"

Transaction::Transaction()
{
    init("", "", "", 0, 0);
}

Transaction::Transaction(const char* accountCode, const char* code, const char* description, int amount, int balance)
{
    init(accountCode, code, description, amount, balance);
}

Transaction::~Transaction()
{
    delete[] m_description;
}

void Transaction::init(const char* accountCode, const char* code, const char* description, int amount, int balance)
{
    //Changes here
    m_description = new char[strlen(description) + 1];

    setAccountCode(accountCode);
    setCode(code);

    strcpy(m_description, description);
    m_amount = amount;
    m_balance = balance;
}

void Transaction::setAccountCode(const char* accountCode)
{
    size_t length = strlen(accountCode);
    if (length != ACCOUNT_CODE_LENGTH)
    {
        strcpy(m_accountCode, "");
    }

    for (size_t i = 0; i < length; i++)
    {
        if (accountCode[i] < 'A' || accountCode[i] > 'Z')
        {
            strcpy(m_accountCode, "");
        }
    }

    strcpy(m_accountCode, accountCode);
}

void Transaction::setCode(const char* code)
{
    size_t length = strlen(code);
    if (length != CODE_LENGTH)
    {
        strcpy(m_code, "");
    }

    for (size_t i = 0; i < length; i++)
    {
        if (!((code[i] >= 'A' && code[i] <= 'Z') ||
            (code[i] >= 'a' && code[i] <= 'z')))
        {
            strcpy(m_code, "");
        }
    }

    strcpy(m_code, code);
}

bool Transaction::isValid()
{
    if (m_balance >= 0 && m_balance + m_amount < 0)
    {
        return false;
    }

    return true;
}
```

Добавихме двата метода, които валидират и ги използвахме в `init()`, по този начин винаги ще проверяваме дали кодовете, които се подават са валидни, ако не са няма да използваме невалидните стойности.

За съжаление в момента човекът, който би използвал нашия клас не може да направи много неща с него, единственото нещо е да провери дали транзакцията е валидна, нека добавим два метода - `void setDescription(const char * description)` и `void print()`. След това си поиграем малко с транзакциите и видим резултата. Ето промените по `Transaction`, добавихме двете декларации на методите в `.hpp` файла и съответно техните дефиниции в `.cpp` файла.
```c++
// Transaction.hpp
public:
    void setDescription(const char* description);
    void print();
```

```c++
// Transaction.cpp
void Transaction::setDescription(const char* description)
{
    delete[] m_description;
    m_description = new char[strlen(description) + 1];
    strcpy(m_description, description);
}

void Transaction::print()
{
    const char* valid = isValid() ? "valid." : "invalid.";

    std::cout << m_accountCode << ", " << m_code << ", " << m_description << ", amount: " << m_amount
        << ", balance: " << m_balance << ", " << valid << std::endl;
}
```
Ето примерно използване на `print()`.

```c++
int main()
{
    Transaction transaction = Transaction("ABCD", "QQ", "Transaction description", -1200, 99999);
    transaction.print(); // ABCD, QQ, Transaction description, amount: -1200, balance: 99999, valid.
}

## Оператор=
```
Сега нека видим един прост случай- нека да създадем транзакция, която е празна(със семантиката на result) - транзакция, която тепърва ще бъде попълвана и след това присвоим някаква стойност на нея.
```c++
int main()
{
    Transaction emptyTransaction;
    Transaction transaction = Transaction("ABCD", "QQ", "Transaction description", -1200, 99999);

    emptyTransaction = transaction;
    transaction.setDescription("Money in the bank");

    emptyTransaction.print; //  ABCD, QQ, ▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌g, amount: -1200, balance: 99999, valid.
    transaction.print; // ABCD, QQ, Money in the bank, amount: -1200, balance: 99999, valid.
}
```
Резултатът е това, последван от `.dll` грешка.Защо се появява тази грешка? Първо се инициализира празната транзакция чрез извикването на `init()`, нейните полета са `""` и `0`.
После се попълват всички стойности втората транзакция, която отново е валидна. Проблемът се появява от `emptyTransaction = transaction;`.
Какво прави `operator=`? Както можем да предположим `operator=` взема стойността на всяко поле от едната транзакция и я записва в полетата на другата транзакция. Но защо това би създало проблеми?
Отговорът на този въпрос се крие в типа на полетата и по-точно в полета, които са **указатели**. Тъй като указателите просто пазят адрес като стойност, това което се случва е, че презаписва адреса.
Резултатът от това действие е, че има 2 полета от два различни обекта, които сокач към едно и също място в `heap` паметта. Тоест, когато стане промяна в `description` на един от тези два обекта, промяната се отразява и в двата обекта.
Това стана особено лошо в случая когато единия проект бъде унищожен преди дргуия, тъй като той сам изтрива заделената памет чрез деструктора си. Можем да видим, че `setDescription()` изтрива паметта, която е заделена за стойността на полето `description`.
Това изтрива паметта, която и двата обекта използват за `description` като след това `transaction` заделя нова памет и записва новата стойност, но `emptyTransaction` остава в невалидно състояние.
** В програмирането този проблем е известен като `deep versus shallow copy`. Неговото решение е специално да се грижим при използване на `operator=` да правим дълбоко(deep) копие на обектите.
За тази цел в `.hpp` файла добавяме нов публичен метод `operator=`. Присвояването на стойности има някои тънкости, за които трябва да се погрижим, нека първо видим как изглежда финалния вариант на `operator=`, а след това стигнем до него стъпка по стъпка като адресираме всеки един от проблеми и пренаписваме решението, така че да ги адресираме.
```c++
    Transaction& operator=(const Transaction& other);
```
Почти всичко тук е ново за нас - връщаме референция към обект от тип `Transaction`, името на метода е има думата `operator` в него, а типа на параметъра е `const Transaction&`. Нека ги адресираме по-сложност:
1. `operator=`  - както можем да имаме различни функции, с различни имена, така можем да претоварваме(overloading) и оператори, можем да **overload-нем** оператори като използваме `operator` и знака на самия оператор, например - operator+, operator==, operator=, etc.
2. `const Transaction& other` - `other` e просто името на параметъра, използването на `other` е нещо като конвенция, която няма нужда да спазваме, използваме го, защото подадения параметър е от същия тип. Нека помислим какво точно означа `const Transaction&`. Ще стигнем до там постъпково като помислим над всички типове, които можем да сложим
    1. `Transaction& operator=(Transaction other)` - Aко типа беше просто `Transaction` при извикването на този метод, езика щеше да прави копие на обекта `other`, това не е добра идея, защото някои обекти може да са много тежки, например обект, който има масив с 1 000 000 елемента.
    2. `Transaction& operator=(Transaction& other)` - Решаваме проблема с копирането като използваме `Transaction&` сега метода използва референция към обекта, тоест подава се адресът на `other` така единственото нещо, което се копира е стойността на адреса и всичко е бързо, проблемът с това е, че можем да променяме `other`, а целта на този оператор не е такава.
    3. `Transaction& operator=(const Transaction& other)` - Решаваме горния проблем като използваме `const Transaction&` - референция към `const Transaction`, тъй като самия смисъл на `const` е да не можем да променяме стойността на `other` вече се предпазваме от ненужни действия като успешно си спестяваме копирането при подаването. Тъй като преминаването от `Transaction` към `const Transaction` е просто -
        C++ и Visual Studio не ни позволяват да бъркаме в паметта на `other`, нищо друго не се променя.
3. Return type на самия метод е `Transaction&` - това е така, поради една единствена причина, искаме нашият клас да може да участва в многократно използване на оператор =, нека видим пример с `int`

```c++
int x = 5;
int y = 10;
int z = 15;

x = y = z; // Same as below

// y = z;
// x = y;

std::cout << x << std::endl; // 15
std::cout << y << std::endl; // 15
std::cout << z << std::endl; // 15
```
Резултатът от следния ред `x = y = z` е както закоментираните два реда -  взема се стойноста на `z` и тя се записва в паметта на `y`, след това същото се повтаря за `y` и `x`.
Какво обаче ще стане когато имаме следния код?

```c++
int x = 5;
int y = 10;
int z = 15;

(x = y) = z; // Same as below

// x = y;
// x = z;

std::cout << x << std::endl; // 15
std::cout << y << std::endl; // 10
std::cout << z << std::endl; // 15
```

Скобите имат най-голяма сила на действие измежду всички оператори, това означа, че първо ще се изпълни кодът в скобите, но какво всъщност връща `(x = y)`? Tова което се случва е, че не просто се взема стойноста на `y` и се слага като стойност на `x`, но и също се връща референция към `x` - `int&`, за да може `x` да участва в следващо използване на оператор=, тоест декларацията на `operator=` за `int` изглежда така `int& operator=(...)`. Тъй като не съм сигурен за параметрите, ще ги оставим празни, важното е, че ако беше `int operator=(...)`, това което щеше да се върне като стойност от `(x = y)` щеше да е просто някаква стойност - `10`, тоест в последствие изпълнението би изглеждало така `(x = y) = z` --> `10 = z`, което не прави смисъл. Вместо това чрез използването на референция имаме `(x = y) = z` --> `x = z`.
По същатата причина, нашия оператор връща `Transaction&`. В крайна сметка кодът на `operator=` изглежда по следния начин:
```c++
Transaction& Transaction::operator=(const Transaction& other)
{
    if (this != &other)
    {
        // Deallocate all dynamic memory.
        delete[] m_description;

        // Allocate new memory and copy all fields.
        m_description = new char[strlen(other.m_description) + 1];

        strcpy(m_accountCode, other.m_accountCode);
        strcpy(m_code, other.m_code);
        strcpy(m_description, other.m_description);
        m_amount = other.m_amount;
        m_balance = other.m_balance;
    }

    return *this;
}
```
Тук отново има няколко неща, на които трябва да обърнем внимание, нека започнем с кода в `if-statement-а`, който имаме, той прави 2 неща. След това ще обясним как връщаме `Transaction&`, накрая ще завършим с обяснение какъв е този магически `if` и защо е там.
1. Дълбоко копиране(Deep copy)
    1. Освобождава всичката динамична памет - Ако имахме повече указатели към `heap` щяхме да имаме повече `delete` и `delete[]`.
    2. Копира полетата от `other` - нищо чудно, идеята е да се присвоят стойностите, след като се погрижим да не използват една и съща памет, можем директно да ги копираме, можем да забележим също, че директно можем да използваме `private` полетата на `other`, тъй като е от същия клас.
2. Връщане на референция към обекта - Всеки клас има специална ключова дума `this` - указател към паметта, където живее самия обект - не класа, а самия обект - нещото което създаваме в `main()`. Тъй като искаме да върнем точно същия обект, който е участвал в изпълнението на `operator=` се възползваме от този указател, единственото трикче е, че ако искаме да използваме стойността, тоест какво сочи този указател, вместо къде, трябва да дереференцираме - добавимя `*` пред `this`, за да вземем стойността. Ако вместо това върнем само `this`, ще стигнем до заключението, че няма да стане тъй, като трябва типа, който връща оператор= да е `Transaction*` - адрес на обект от тип `Transaction`.
3. `if(this != &other)` - Този ред решава един много краен случай и това е случаят, в който присвояваме един обект на себе си, тоест `transaction = transaction`, ако не се погрижим за този случай, ще се изпълни `delete[] m_description`, паметта ще се изтрие и след това ще бъде направен опит за достъп до нея чрез `other`, който всъщност съвпада изцяло с `*this`.

Вече можем да изпълним следния код и да видим, че всичко работи както трябва.
```c++
int main()
{
    Transaction emptyTransaction;
    Transaction transaction = Transaction("ABCD", "QQ", "Transaction description", -1200, 99999);

    emptyTransaction = transaction;
    transaction.setDescription("Money in the bank");

    emptyTransaction.print(); // ABCD, QQ, Transaction description, amount: -1200, balance: 99999, valid.
    transaction.print(); // ABCD, QQ, Money in the bank, amount: -1200, balance: 99999, valid.
}
```
## Copy constructor
Остана да решим един единствен проблем, нека видим как се поражда той. В горната `main()` функция можем да видим, че първо създаваме `emptyTransaction`, а след това присвояваме стойност на нея. Какво става, когато директно декларираме и инициализираме обекта на един и същи ред?
```c++
int main()
{
    Transaction transaction = Transaction("ABCD", "QQ", "Transaction description", -1200, 99999);

    Transaction copyTransaction = transaction;
    transaction.setDescription("Money in the bank");

    copyTransaction.print(); // ABCD, QQ, ▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌, amount: -1200, balance: 99999, valid.
    transaction.print(); // ABCD, QQ, Money in the bank, amount: -1200, balance: 99999, valid.
}
```

Отново имаме проблем, но какъв е той? Нали вече предефинирахме оператор= и той би трябвало да се оправи с плиткото копиране? Нека сложим по един `cout в конструкторите, деструктора и оператор=`.
```c++
Constructor called.
ABCD, QQ, ▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌i, amount: -1200, balance: 99999, valid.
ABCD, QQ, Money in the bank, amount: -1200, balance: 99999, valid.
Destructor called.
```

В началото се извиква конструктор за `transaction`, и накрая се извиква един деструктор, но има 2 създадени обекта и за единия от тях използваме =?
Това, което се случва всъщност е, че не се извиква оператор=, а се извиква **copy constructor**, за `copyTransaction`.

Copy constructor е конструктор, които приема параметър обект от същия тип, проблема при него е същия както при оператор= - плитко копиране. Нека решим проблема като добавим последната част на **голямата четворта** - **default constructor, copy constructor, operator=, destructor**.
Истината е, че Copy constructor-a е просто опростен оператор= или по-скоро можем да си мислим така за него в началото, докато придобием интуиция. Нека добавим декларацията и дефиницията му в нашия клас.
```c++
private:
    void copyFrom(const Transaction& other);
    void del();
public:
    Transaction(const Transaction& other);
```
За да осъзнаем какво се случва точно, добавяме два метода - `del()`, който трие динамичната памет и `copyFrom(const Transaction& other)`, който копира всички полета от `other`. Вече нашия copy constructor и оператор= изгледат по следния начин:
```c++
Transaction::Transaction(const Transaction& other)
{
    // Allocate new memory and copy all fields.
    copyFrom(other);
}

Transaction& Transaction::operator=(const Transaction& other)
{
    std::cout << "operator= called." << std::endl;
    if (this != &other)
    {
        // Deallocate all dynamic memory.
        del();

        // Allocate new memory and copy all fields.
        copyFrom(other);
    }

    return *this;
}

void Transaction::del()
{
    delete[] m_description;
}

void Transaction::copyFrom(const Transaction& other)
{
    m_description = new char[strlen(other.m_description) + 1];

    strcpy(m_accountCode, other.m_accountCode);
    strcpy(m_code, other.m_code);
    strcpy(m_description, other.m_description);
    m_amount = other.m_amount;
    m_balance = other.m_balance;
}

Transaction::~Transaction()
{
    std::cout << "Destructor called." << std::endl;
    del();
}
```
Тъй като копираме стойности от друг обект от същия тип няма нужда да ги валидираме, поне в този случай, може да се наложи валидация в друг случай.
Нека рефакторираме малко класа, добавим `getters` и видим финалния продукт.

## Тhe Big Four imeplemented - Default constructor, Copy constructor, Operator=, Destructor.
```c++
// Transaction.hpp
#pragma once
#pragma warning(disable:4996)

#include <iostream>

class Transaction {
private:
    // Static const variables to remove magic numbers from the code.
    static const int ACCOUNT_CODE_LENGTH = 8;
    static const int CODE_LENGTH = 4;

    // The private fields of the Transaction class.
    char* m_description;
    char m_accountCode[ACCOUNT_CODE_LENGTH + 1];
    char m_code[CODE_LENGTH + 1];
    int  m_amount;
    int  m_balance;

    // Methods which reduce code duplication.
    void init(const char* accountCode, const char* code, const char* description, int amount, int balance); // Used in the default and the parameter constructors.
    void copyFrom(const Transaction& other); // Used in the copy constructor and operator=.
    void del(); // Used in operator= and destructor.

    // Private setters, which validate the codes.
    void setAccountCode(const char* accountCode);
    void setCode(const char* code);
public:
    // Useful constructor for our case.
    Transaction(const char* accountCode, const char* code, const char* description, int amount, int balance);

    // The Big Four.
    Transaction();
    Transaction(const Transaction& other);
    Transaction& operator=(const Transaction& other);
    ~Transaction();

    // Getters, we use const char * to make sure the memory can't be altered.
    const char* getDescription() const;
    const char* getAccountCode() const;
    const char* getCode() const;
    int getBalance() const;
    int getAmount() const;

    // Public setter. The other information for the transaction cannot be changed because it is essential. This description can be changed because I needed it for the example, sorry :<
    void setDescription(const char* description);

    // Useful public methods.
    void print();
    bool isValid();
};
```

```c++
// Transaction.cpp
#include "Transaction.hpp"

// Default constructor. Creates an object with "default" fields.
Transaction::Transaction()
{
    init("", "", "", 0, 0);
    std::cout << "Default constructor called." << std::endl;
}

// Constructor with parameters - doesn't really have a name in programming. Creates an object with the passed values, does validation beforehand.
Transaction::Transaction(const char* accountCode, const char* code, const char* description, int amount, int balance)
{
    init(accountCode, code, description, amount, balance);
    std::cout << "Constructor called." << std::endl;
}

// Copy constructor. Creates a new object with the exact same values as another already existing object.
Transaction::Transaction(const Transaction& other)
{
    // Allocate new memory and copy all fields.
    copyFrom(other);
}

// Operator=. Copies the values from an object of the same class. Both object must already exist in order for operator= to be called.
Transaction& Transaction::operator=(const Transaction& other)
{
    std::cout << "operator= called." << std::endl;
    if (this != &other)
    {
        // Deallocate all dynamic memory.
        del();

        // Allocate new memory and copy all fields.
        copyFrom(other);
    }

    return *this;
}

// Desctructor. Deallocates all the dynamic memory used in the class. Called on object destruction i.e. when the object gets out of scope.
Transaction::~Transaction()
{
    std::cout << "Destructor called." << std::endl;
    del();
}

// Initializes the fields with the passed parameters, does validation, used to remove code duplication.
void Transaction::init(const char* accountCode, const char* code, const char* description, int amount, int balance)
{
    m_description = new char[strlen(description) + 1];

    setAccountCode(accountCode);
    setCode(code);

    strcpy(m_description, description);
    m_amount = amount;
    m_balance = balance;
}

// Copies the values from an object of the same class, used to remove code duplication.
// Can use the init() method, it is debatable, depending on the use case. I've chosen not to do in in order to showcase its usage.
void Transaction::copyFrom(const Transaction& other)
{
    m_description = new char[strlen(other.m_description) + 1];

    strcpy(m_accountCode, other.m_accountCode);
    strcpy(m_code, other.m_code);
    strcpy(m_description, other.m_description);
    m_amount = other.m_amount;
    m_balance = other.m_balance;
}

// Probably not very useful oneliner, makes more sense if there is more than one field which handles dynamic memory, nonetheless I've showncased it since it gives good intuition.
void Transaction::del()
{
    delete[] m_description;
}

// Private setter, does validation. Sets default value of "" if the validation fails.
// This decision is yours, you can choose to not change the current value, either way, you have to show through comment or something else that,
// the user of your class must know what will happen if invalid value is passed to a setter.
void Transaction::setAccountCode(const char* accountCode)
{
    size_t length = strlen(accountCode);
    if (length != ACCOUNT_CODE_LENGTH)
    {
        strcpy(m_accountCode, "");
    }

    for (size_t i = 0; i < length; i++)
    {
        if (accountCode[i] < 'A' || accountCode[i] > 'Z')
        {
            strcpy(m_accountCode, "");
        }
    }

    strcpy(m_accountCode, accountCode);
}

// Same as above, sets the code of the transaction.
void Transaction::setCode(const char* code)
{
    size_t length = strlen(code);
    if (length != CODE_LENGTH)
    {
        strcpy(m_code, "");
    }

    for (size_t i = 0; i < length; i++)
    {
        if (!((code[i] >= 'A' && code[i] <= 'Z') ||
            (code[i] >= 'a' && code[i] <= 'z')))
        {
            strcpy(m_code, "");
        }
    }

    strcpy(m_code, code);
}

// Public setter to set a new description, description has no upper limit of characters.
void Transaction::setDescription(const char* description)
{
    delete[] m_description;
    m_description = new char[strlen(description) + 1];
    strcpy(m_description, description);
}

// Getters, nothing really to say here, except don't forget the const modifiers.
const char* Transaction::getDescription() const
{
    return m_description;
}

const char* Transaction::getAccountCode() const
{
    return m_accountCode;
}

const char* Transaction::getCode() const
{
    return m_code;
}

int Transaction::getBalance() const
{
    return m_balance;
}

int Transaction::getAmount() const
{
    return m_amount;
}

// Checks if the transaction is valid. A transaction is invalid if the balance is positive before making the transaction and after that it becomes negative.
// In all other cases the transaction is valid.
bool Transaction::isValid()
{
    if (m_balance >= 0 && m_balance + m_amount < 0)
    {
        return false;
    }

    return true;
}

// Print function  which uses the isValid() method and ternary operator to show information in the console about the transaction.
void Transaction::print()
{
    const char* valid = isValid() ? "valid." : "invalid.";

    std::cout << m_accountCode << ", " << m_code << ", " << m_description << ", amount: " << m_amount
        << ", balance: " << m_balance << ", " << valid << std::endl;
}

```

