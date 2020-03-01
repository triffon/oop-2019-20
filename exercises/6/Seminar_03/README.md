<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
![big four meme](assets/big_four.jpg)

- [Голямата четворка - Конструктор по подразбиране, Копи конструктор, оператор равно и деструктор](#%D0%B3%D0%BE%D0%BB%D1%8F%D0%BC%D0%B0%D1%82%D0%B0-%D1%87%D0%B5%D1%82%D0%B2%D0%BE%D1%80%D0%BA%D0%B0---%D0%BA%D0%BE%D0%BD%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D0%BE%D1%80-%D0%BF%D0%BE-%D0%BF%D0%BE%D0%B4%D1%80%D0%B0%D0%B7%D0%B1%D0%B8%D1%80%D0%B0%D0%BD%D0%B5-%D0%BA%D0%BE%D0%BF%D0%B8-%D0%BA%D0%BE%D0%BD%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D0%BE%D1%80-%D0%BE%D0%BF%D0%B5%D1%80%D0%B0%D1%82%D0%BE%D1%80-%D1%80%D0%B0%D0%B2%D0%BD%D0%BE-%D0%B8-%D0%B4%D0%B5%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D0%BE%D1%80)
- [Проблемът](#%D0%BF%D1%80%D0%BE%D0%B1%D0%BB%D0%B5%D0%BC%D1%8A%D1%82)
- [Какво се има предвид](#%D0%BA%D0%B0%D0%BA%D0%B2%D0%BE-%D1%81%D0%B5-%D0%B8%D0%BC%D0%B0-%D0%BF%D1%80%D0%B5%D0%B4%D0%B2%D0%B8%D0%B4)
- [Голяма четворка I - Конструктор по подразбиране (Default constructor)](#%D0%B3%D0%BE%D0%BB%D1%8F%D0%BC%D0%B0-%D1%87%D0%B5%D1%82%D0%B2%D0%BE%D1%80%D0%BA%D0%B0-i---%D0%BA%D0%BE%D0%BD%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D0%BE%D1%80-%D0%BF%D0%BE-%D0%BF%D0%BE%D0%B4%D1%80%D0%B0%D0%B7%D0%B1%D0%B8%D1%80%D0%B0%D0%BD%D0%B5-default-constructor)
  - [`Transaction` Default Constructor](#transaction-default-constructor)
  - [`Transaction` Constructor](#transaction-constructor)
  - [`private void init()` - премахване на дупликация на кода](#private-void-init---%D0%BF%D1%80%D0%B5%D0%BC%D0%B0%D1%85%D0%B2%D0%B0%D0%BD%D0%B5-%D0%BD%D0%B0-%D0%B4%D1%83%D0%BF%D0%BB%D0%B8%D0%BA%D0%B0%D1%86%D0%B8%D1%8F-%D0%BD%D0%B0-%D0%BA%D0%BE%D0%B4%D0%B0)
- [Голяма четворка II - Деструктор (Destructor)](#%D0%B3%D0%BE%D0%BB%D1%8F%D0%BC%D0%B0-%D1%87%D0%B5%D1%82%D0%B2%D0%BE%D1%80%D0%BA%D0%B0-ii---%D0%B4%D0%B5%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D0%BE%D1%80-destructor)
- [Обобщение до тук](#%D0%BE%D0%B1%D0%BE%D0%B1%D1%89%D0%B5%D0%BD%D0%B8%D0%B5-%D0%B4%D0%BE-%D1%82%D1%83%D0%BA)
- [Валидация в `private` setter методи](#%D0%B2%D0%B0%D0%BB%D0%B8%D0%B4%D0%B0%D1%86%D0%B8%D1%8F-%D0%B2-private-setter-%D0%BC%D0%B5%D1%82%D0%BE%D0%B4%D0%B8)
- [Голяма четворка III - Оператор= (Operator=)](#%D0%B3%D0%BE%D0%BB%D1%8F%D0%BC%D0%B0-%D1%87%D0%B5%D1%82%D0%B2%D0%BE%D1%80%D0%BA%D0%B0-iii---%D0%BE%D0%BF%D0%B5%D1%80%D0%B0%D1%82%D0%BE%D1%80-operator)
  - [Deep Copy vs Shallow Copy](#deep-copy-vs-shallow-copy)
  - [(x = y) = z Problem](#x--y--z-problem)
  - [`Transaction operator=` - имплементация](#transaction-operator---%D0%B8%D0%BC%D0%BF%D0%BB%D0%B5%D0%BC%D0%B5%D0%BD%D1%82%D0%B0%D1%86%D0%B8%D1%8F)
  - [Успешно използване на `operator=`](#%D1%83%D1%81%D0%BF%D0%B5%D1%88%D0%BD%D0%BE-%D0%B8%D0%B7%D0%BF%D0%BE%D0%BB%D0%B7%D0%B2%D0%B0%D0%BD%D0%B5-%D0%BD%D0%B0-operator)
- [Голяма четворка IV - Copy constructor](#%D0%B3%D0%BE%D0%BB%D1%8F%D0%BC%D0%B0-%D1%87%D0%B5%D1%82%D0%B2%D0%BE%D1%80%D0%BA%D0%B0-iv---copy-constructor)
- [Тhe Big Four implemented - Default constructor, Copy constructor, Operator=, Destructor.](#%D1%82he-big-four-implemented---default-constructor-copy-constructor-operator-destructor)
- [The rule of three](#the-rule-of-three)
- [Обобщение](#%D0%BE%D0%B1%D0%BE%D0%B1%D1%89%D0%B5%D0%BD%D0%B8%D0%B5)
- [Въпроси](#%D0%B2%D1%8A%D0%BF%D1%80%D0%BE%D1%81%D0%B8)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## Голямата четворка - Конструктор по подразбиране, Копи конструктор, оператор равно и деструктор
Днес ще се занимаваме отново с класове, като този път ще използваме полета, които ще се грижат за заделянето и освобождането на динамична памет. Ще разгледаме даден проблем, които не можем да решим с текущите си знания. След това ще покажем как можем да се справим с този проблем чрез използването на динамична памет. След това ще покажем какви проблеми възникват когато използваме динамична памет в нашите класове и как да ги решим. Ще завършим с обобщение на всичкия материал и ще покажем как изглежда клас, който има голяма четворка.

## Проблемът
Вие сте софтуерен разработчик, който работи за банка. По принцип вашата банка се справя с всяка една транзакция на момента, в който тя бъде изпратена,но за съжаление вашите шефове са започнали да се притесняват покрай всичките новини за вируси и искат вие да им помогнете да сложат предпазни мерки в системата. 

Вашият приятел Пеше се е погрижил и е сложил няколко реда код, които записват неуспешните транзакции във файл. Вашата задача е напишете клас, които може да чете транзакциите от файла(конзолата за нас) и да позволява лесната работа с тях, тъй като Трифон ще трябва да напише цялата логика зад ръчното им обработване, след като вие му позволите да използва вашия клас.

Една транзакция се описва от **кода** на сметката, от която е произлязла, **кода на самата транзакция**, **сумата** която е изпратена или получена, **балансът** на сметката преди изпълняването на транзакцията и **описанието** на транзакцията, **което може да бъде произволно дълго**. Описанието е вътрешно поле, което програмистите използват, затова можем да го променяме.
Кодът на сметката е текст с дължина 4, който включва само големи латински букви. Кодът на самата транзакция е отново текст, който е с дължина 2, но може да включва както и малки, така и големи латински букви. Сумата на самата транзакция е цяло цисло, което може да бъде отрицателно или положително, като можем да считаме че няма да надхвърли 2 000 000. Балансът на сметката също е цяло число, също можем да смятаме, че няма да надхвърли 2 000 000. Считаме една транзакция за невалидна, ако балансът става от положителен - отрицателен, след изпълнението на транзакция. **Не знаете колко транзакции може да има във дадения файл**, може да са 3, но може и да са 300 000, трябва да се погрижите, че всички ще бъдат взети под внимание, независимо от броя им.

Вашият клас трябва да може да се създава чрез конструктор за подразбиране, както и друг конструктор, които да приема някаква стойност за начална големина. Трябва да можете да добавяте нови транзакции(валидирайте транзакцията преди добавянето), да триете транзакции по техния код, и да казвате дали дадена транзакция е вече във вашия клас спрямо подаден код на транзакция. Трябва също да можете да показвате информация за всички транзакции в конзолата - техните кодове и балансът след изпълнението им. Също трябва да предоставяте функционалност, която може да покаже на конзолата колко еднакви транзакции има ваш обект спрямо друг обект от същия клас. Две транзакции са еднакви когато кодът на сметката и кодът на транзакцията съвпадат.


## Какво се има предвид
Първата ни задача е да разбием условието и да разберем какво точно се изисква от нас.

Първото нещо, което можем да заключим е, че  ще четем транзакции от конзолата, като има подробно описание какво точно можем да очакваме за тези транзакции. Също важно парче информация е, че не знаем техния брой. Можем да разбием задачата на 2 класа - `Transaction`(комплексните данни, с които ще работим) и `TransactionManager` - класът, който държи логиката зад тяхното управление - добавяне, премахване, показване и т.н.

**Този семинар ще се съсредоточим само върху `Transaction`, тъй има достатъчно неща, които трябва да се свършат с него, макар и да не изглежда така на пръв поглед.**

**Въпрос: Защо `Transaction` е клас?** Дали нещо да е структура или клас и изцяло наше решение, моята аргументация е, че има доста логика покрай самата транзакция - валидация на кода на сметката, валидация на кода на самата транзакция, проверка за валидност спрямо баланса и сумата и за финал описание на транзакцията - поле с необозначена големина, това означава, че ще трябва да използваме динамична памет за неговата стойност. Друг добър аргумент е самата идея на една транзакция, тук вече се отделяме от самото програмиране и започваме да мислим в домейна на проблема, който решаваме, искаме ли да можем да променяме нещо по тези транзакции? Те вече са записани, нужната информация е там, остава само да се обработят, нашата задача е да направим тази обработка по-лесна, не да променяме неща по тях. С тези мисли стигнах до заключението, че да направя `Transaction` клас е добра идея. 

От условието можем да заключим, че една транзакция би имала следните полета. 
```c++
class Transaction {
    char* m_description; // Описанието, неограничена дължина, трябва да използваме динамична памет.
    char m_accountCode[9]; // Кодът на самата сметка, дължина 8 + 1 за терминираща 0.
    char m_code[5]; // Кодът на самата транзакция, дължина 4 + 1.
    int  m_amount; // Колко пари са преведени чрез транзакцията, може да е положително или отрицателно спрямо дали се тегли или внася.
    int  m_balance; // Парите в сметката преди изпълнението на транзакцията.
};
```
Може да забележим, че съм използвал `m_` префикс към всички полета, това е с идеята да различим полетата(член-данни) от параметрите. Идеята на `m_` e "member", може да използвате тази конвенция, ако я смятате за полезна, аз лично го намирам за по-чисто отколкото използването на `_` пред имената на параметрите, тъй като съществува друга конвенция, която гласи, че всички полета, които започват с `_` са с `private` достъп.

## Голяма четворка I - Конструктор по подразбиране (Default constructor)
Нека започнем с първата част от голямата четворка - конструктор по подразбиране. Към него ще добавим и един обикновен конструктор, който да може да създава готов, смислен обект с валидни данни.

### `Transaction` Default Constructor
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
Така би изглеждал един примерен конструктор по подразбиране, тук е важно да се отбележи, че какви са стойностите по подразбиране на полетата е лично мой избор, важното е при нужда, да може да се провери дали дадена транзакция е валидна. Например ако тя няма код на сметката, очевидно транзакцията е невалидна. Затова е хубаво да се стремим, стойността в даденото поле да e извън множеството на всички валидни стойности или да се води за "нулевата" стойност на това множество. 

### `Transaction` Constructor
Нека направим и един **конструктор**, чрез който да инициализираме всички полета на структурата. Тъй като едно полетата ни използва динамична памет, първо трябва да заделим достатъчно място за него. Естествено алокирането на динамична памет ни задължава да я деалокираме, затова трябва да добавим и **деструктор**.
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
```
Още тук в двата конструктора можем да видим угромно повторение на код. Когато забележим нещо такова е хубаво веднага да вземем мерки преди да сме изгубили нишката и да намалим сложността и големината на нашето решение.

### `private void init()` - премахване на дупликация на кода
За да решим проблема с повтарянето на кода без да променяме как нашият клас изглежда отвън, можем да добавим метод с `private` достъп и да го използваме само вътрешно. За тази цел имплементираме ` void init(const char* accountCode, const char* code, const char* description, int amount, int balance)`, който ще задава стойности на нашите полета.
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
};
```
## Голяма четворка II - Деструктор (Destructor)
Тук няма много какво да кажем. Тъй като сме използвали динамична памет, трябва да се грижим за нейната деалокация, това става в **деструктора** - специалният метод, който се свързва с живота на обект и се изпълнява при негово унищожаване. 

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
## Обобщение до тук
Добавихме конструктор по подразбиране, друг обикновен конструктор, който ни е нужен по условие и деструктор, тъй като работим с динамична памет. Също изнесохме повтарящата се логика в отделна `private` член-функция. Много е важно да отбележим казаното отново, имаме нужда от **голяма четворка** само и единствено, защото работим с динамична памет, заделянето на памет в конструктора ни принуждава да я освобождаване някъде, най-доброто място за това освобождаване е деструктора. Ако не използвахме динамична памет, нямаше да има нужда от голяма четворка.

Вече можем да създаваме транзакции по два начина:
```c++
int main()
{
    Transaction emptyTransaction;
    Transaction transaction = Transaction("ABCD", "QQ", "Transaction description", -1200, 99999);
}
```
## Валидация в `private` setter методи
За съжаление в момента имаме проблем - можем да създаваме невалидни транзакции. Трябва да валидираме параметрите, които подаваме и в случай, че те са невалидни, да сложим стойностите по подразбиране за всяко едно такова поле. Дали слагаме стойности по подразбиране или не правим нищо отново е наше решение, избрал съм да слагам невалидни стойности, тъй като при опит за промяна на транзакцията, едно променено поле може да означава напълно друга транзакция, което е лошо, предпочитам да я направя невалидна отколкото да е грешна и някой да загуби пари.

За тази цел отиваме в `init` метода и правим `private set` методи, който ще валидират подадените стойности преди да ги запишат в съответното поле. Правим тази промяна в `init()` тъй като  за момента този метод е единствената точка, през която преминават всички входни данни. 

Нека първо разгледаме какви валидации има нужда да направим:
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

Добавихме двата метода, които валидират и ги използвахме в `init()`, по този начин винаги ще проверяваме дали кодовете, които се подават са валидни, ако не са няма да използваме невалидните стойности. Също добавихме две статични константни променливи, с цел да избегнем магически числа в имплементацията на нашия клас.

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
```

## Голяма четворка III - Оператор= (Operator=)
Сега нека видим един прост случай - нека да създадем транзакция, която е празна(със семантиката на result) - транзакция, която тепърва ще бъде попълвана и след това присвоим някаква стойност на нея.
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
Резултатът е това, има нещо грешно. Първо се инициализира празната транзакция чрез извикването на `init()`, нейните полета са `""` и `0`.

После се попълват всички стойности втората транзакция, която отново е валидна.

### Deep Copy vs Shallow Copy
Проблемът се появява от `emptyTransaction = transaction;`.

**Въпрос: Какво прави `operator=`?** `operator=` копира полетата на `transaction` в полетата на `emptyTransaction`.

**Въпрос: Защо това създава проблеми?** Зависи, някой път няма проблеми, но този път има. Проблемът идва от типовете на полетата и по-точно в полета, които са **указатели**. Тъй като указателите просто пазят адрес като стойност, това което се случва е, че презаписва адреса.
Резултатът от това действие е, че има 2 полета от два различни обекта, които сочат към едно и също място в `heap` паметта. Тоест, когато стане промяна в `description` на единия от тези два обекта, промяната се отразява и в двата обекта.

Това става особено лошо в случая когато един обект бъде унищожен преди друг и те споделят памет. Унищоженият обект изтрива заделената памет чрез деструктора си. Можем да видим, че `setDescription()` изтрива паметта, която е заделена за стойността на полето `description`.
Това изтрива паметта, която и двата обекта използват за `description` като след това `transaction` заделя нова памет и записва новата стойност, но `emptyTransaction` остава в невалидно състояние.

В програмирането този проблем е известен като `deep copy versus shallow copy`. Неговото решение е специално да се грижим за дълбоко копиране чрез правилно използване на `operator=`.

За тази цел в `.hpp` файла добавяме нов публичен метод `operator=`. Присвояването на стойности има някои тънкости, за които трябва да се погрижим, нека ги разгледаме една по една. Това е декларацията на `operator=`.
```c++
    Transaction& operator=(const Transaction& other);
```
Почти всичко тук е ново за нас - връщаме референция към обект от тип `Transaction`, в името на метода има странната думата `operator`, а типа на параметъра е `const Transaction&`. Нека разгледаме новостите една по една:
1. `operator=`  - както можем да имаме различни функции, с различни имена, така можем да претоварваме(overloading) и оператори, можем да **overload-нем** оператори като използваме `operator` и знака на самия оператор, например - `operator+`, `operator==`, `operator=`, etc.
2. `const Transaction& other` - `other` e просто името на параметъра, използването на `other` е нещо като конвенция, която няма нужда да спазваме, използваме го, защото подадения параметър е от същия тип. Нека помислим какво точно означа `const Transaction&`. Ще стигнем до там постъпково като помислим над всички типове, които можем да сложим
    1. `Transaction& operator=(Transaction other)` - Aко типа беше просто `Transaction` при извикването на този метод, езика щеше да прави копие на обекта `other`, това не е добра идея, защото някои обекти може да са много тежки, например обект, който има поле - масив с 1 000 000 елемента.
    2. `Transaction& operator=(Transaction& other)` - Решаваме проблема с копирането като използваме `Transaction&` сега метода използва референция към обекта, тоест подава се адресът на `other` така единственото нещо, което се копира е стойността на адреса и всичко е бързо, проблемът с това е, че можем да променяме `other`, а целта на този оператор не е такава и да позволяваме това нарушава добрите практики за писане на C++ код.
    3. `Transaction& operator=(const Transaction& other)` - Решаваме горния проблем като използваме `const Transaction&` - референция към `const Transaction`, тъй като самия смисъл на `const` е да не можем да променяме стойността на `other` вече се предпазваме от ненужни действия като успешно си спестяваме копирането при подаването. Тъй като преминаването от `Transaction` към `const Transaction` е просто - C++ и Visual Studio не ни позволяват да бъркаме в паметта на `other`, нищо друго не се променя.
3. Return type на самия метод е `Transaction&` - това е така, поради една единствена причина, искаме нашият клас да може да участва в многократно използване на `оператор=`, нека видим пример с `int`

### (x = y) = z Problem
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

Скобите имат най-голяма сила на действие измежду всички оператори, това означа, че първо ще се изпълни кодът в скобите, но какво всъщност връща `(x = y)`? Tова което се случва е, че не просто се взема стойноста на `y` и се слага като стойност на `x`, но и също се връща референция към `x` - `int&`, за да може `x` да участва в следващо използване на оператор=, тоест декларацията на `operator=` за `int` изглежда така `int& operator=(...)`. Тъй като не съм сигурен за параметрите, ще ги оставим празни, важното е, че ако беше `int operator=(...)`, това което щеше да се върне като стойност от `(x = y)` щеше да е просто някаква стойност - `10`, тоест в последствие изпълнението би изглеждало така `(x = y) = z` --> `10 = z`, което не прави смисъл.

Вместо това чрез използването на референция имаме `(x = y) = z` --> `x = z`. По същатата причина, нашия оператор връща `Transaction&`.

### `Transaction operator=` - имплементация
След всички тези разяснение, нека да видим самата дефиниция на този метод.
```c++
Transaction& Transaction::operator=(const Transaction& other)
{
    // Checks for the case when transaction = transaction. (Explained below)
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

Тук отново има няколко неща, на които трябва да обърнем внимание, ще започнем с кода в `if-statement-а`, който прави не 1, а 2 неща. След това ще обясним как връщаме `Transaction&` и накрая ще завършим с обяснение какъв е този магически `if` и защо е там.
1. Дълбоко копиране(Deep copy)
    1. Освобождава всичката динамична памет - Ако имахме повече указатели към `heap` щяхме да имаме повече `delete` и `delete[]`.
    2. Копира полетата от `other` - нищо чудно, идеята е да се присвоят стойностите, след като се погрижим да не използват една и съща памет, можем директно да ги копираме, можем да забележим също, че директно можем да използваме `private` полетата на `other`, тъй като е от същия клас.
2. Връщане на референция към обекта - Всеки клас има специална ключова дума `this` - указател към паметта, където живее самия обект - не класа, а самия обект - нещото което създаваме в `main()`. Тъй като искаме да върнем точно същия обект, който е участвал в изпълнението на `operator=` се възползваме от този указател. Единственото трикче е, че ако искаме да използваме стойността, тоест какво точно сочи този указател, вместо къде, трябва да дереференцираме - да добавим `*` пред `this`, за да вземем стойността. Ако вместо се опитаме върнем само `this`, ще стигнем до заключението, че няма да стане, тъй като трябва типът, който връща оператор= да е `Transaction*` - адрес на обект от тип `Transaction`.
3. `if(this != &other)` - Този ред решава един много краен случай и това е случаят, в който присвояваме един обект на себе си, тоест `transaction = transaction`, ако не се погрижим за този случай, ще се изпълни `delete[] m_description`, паметта ще се изтрие и след това ще бъде направен опит за достъп до нея чрез `other`, който всъщност съвпада изцяло с `*this`.

### Успешно използване на `operator=`
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

## Голяма четворка IV - Copy constructor
Остана да решим един единствен проблем, нека видим как се поражда той. В горната `main()` функция можем да видим, че първо създаваме `emptyTransaction`, а след това присвояваме стойност. Какво става, когато директно декларираме и инициализираме обекта на един и същи ред?
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

Отново имаме проблем, но какъв е той? Вече предефинирахме оператор= и той би трябвало да се оправи с плиткото копиране? За да разберем какво наистина се случва, можем да показваме на конзолата кога даден метод се вика - `cout в конструкторите, деструктора и оператор=`.
```c++
Constructor called.
ABCD, QQ, ▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌▌i, amount: -1200, balance: 99999, valid.
ABCD, QQ, Money in the bank, amount: -1200, balance: 99999, valid.
Destructor called.
```

В началото се извиква конструктор за `transaction`, и накрая се извиква един деструктор, но има 2 създадени обекта и за единия от тях използваме =?
Това, което се случва всъщност е, че не се извиква оператор=, а се извиква **copy constructor** за `copyTransaction`.

**Copy constructor** е конструктор, които приема параметър обект от същия тип, проблема при него е същия както при оператор= - плитко копиране. Нека решим проблема като добавим последната част на **голямата четворта**.
Истината е, че Copy constructor-a е просто опростен оператор= или по-скоро можем да си мислим така за него в началото, поне докато придобием интуиция. Нека добавим декларацията и дефиницията му в нашия клас.
```c++
private:
    void copyFrom(const Transaction& other);
    void del();
public:
    Transaction(const Transaction& other);
```
За яснота добавяме два метода - `del()`, който трие динамичната памет и `copyFrom(const Transaction& other)`, който копира всички полета от `other`. Вече нашия copy constructor и оператор= изгледат по следния начин:
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
Тъй като копираме стойности от друг обект от същия тип няма нужда да ги валидираме, но това зависи от случая, може да се наложи валидация в зависимост от проблема.
Нека рефакторираме малко класа, след това да добавим `getters` и видим финалния продукт.

## Тhe Big Four implemented - Default constructor, Copy constructor, Operator=, Destructor.
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

## The rule of three
Нуждата от голяма четворка идва от правилото **the rule of three**, което гласи че ако имаме имплементация на едно от трите - **деструктор**, **копи конструктор** или **оператор=**, имаме нужда и от трите. Това е така защото деструктора се грижи за освобождаването на динамичната памет, което автоматично означава, че имаме указатели в класа, което значи че при копиране ще срещнем проблем с плитко копиране. Този проблем решаваме чрез копи конструктор и оператор=, не знам защо ни трябва конструктор по подразбиране...

## Обобщение
Започнахме с целта на упражнението, след това разгледахме един абстрактен голям проблем, отделихме една част върху, която можем да работим и започнахме да я обработваме. Показахме 2 конструктора и начин за премахване на дупликацията на код между тях чрез скрити методи. След това добавихме деструктор, тъй като трябва да освобождаваме паметта, която заделяме, което бе последвано от проблем при присвояването, от там предефинирахме оператор=, за да решим този проблем. Накрая видяхме, че всъщност при едновременна декларация и инициализация на обект се извиква копи конструктор вместо оператор=, разбрахме че копи конструктора е просто конструктор, който приема за параметри обект от същия тип, предефинирахме и него и така успяхме да всички проблеми с класовете, който могат да възникнат в текущия момент. По време на обясненията размишлявахме над задачата и какви решения сме взели за самата имплементация спрямо информацията, която имаме от условието.

## Въпроси
 * Кога използваме голямата четворка при писането на класове?
 * Защо когато имплементираме деструктор трябва да имплементираме още 2 неща?
 * Кои са тези 2 неща?
 * Защо типа на параметъра на копи конструктора е `const ClassType& other`, какво означава това?
 * Какво гласи ** the rule of three**?
 * Кога слагаме `const` модификатор на методи?
 * Какъв е типа на `getters` за полета, които са символни низове, защо?
 * Какво е подаване по стойност?
 * Как подаваме по стойност?
 * Какво е подаване по референция?
 * Как подаваме по референция?
 * Какво означават следните типове `char name`, `char * name`, `const char * name`, `char const * name`, `const char const * name`, `char * const name`, `const char * const name`, `const char const * const name`, `Student student`, `Student& student`, `const Student& student`?
 * Какво е дупликация на кода?
 * Какво е инициализиращ списък?
 * Кога се използва?
 * Обяснете Deep copy и Shallow copy.
 * Къде правим валидацията на полетата на един клас?
 * Какво прави `if` проверката в оператор= на един клас с динамична памет?
 * Избройте голямата четворка.
