/*
Проблем: Достъпване на място в паметта, което не е заделено от нас.
*/

#include <iostream>

using std::cout;
using std::endl;

struct Base { int a; };

int main() {

    // Заделяме памет динамично за нов масив
    Base* baseArray = new Base[5];

    // Популираме стойности на член-данната
    for (int i = 0; i < 5; i++) {
        baseArray[i].a = i;
    }

    // Отпечатваме масива
    // по грешка итерираме до 55, и нямаме проблеми с достъпването на клетките от паметта
    for (int i = 0; i < 55; i++) {
        cout << baseArray[i].a << " ";
    }
    cout << endl;

    for (int i = 0; i < 55; i++) {
        //... по същия начин можем да преместим поинтъра
        cout << (baseArray++)->a << " ";
    }

    return 0;
}
