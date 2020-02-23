#include <iostream>
#include <cmath>

using namespace std;

struct Rectangle {
    int a;
    int b;

    Rectangle(int a, int b) {
        //Конструктора играе ролята на функция за правене на правоъгълник по 2 страни.
        //Помислете каква е разликата от това да имаме отделна функция (не конструктор) за правенето на правоъгълник.
        //По желание тук може да направите проверка дали страните му са валидни.
        this->a = a;
        this->b = b;
    }

    void showEasy() {
        cout << "One of the sides is: " << a << endl;
        cout << "The other side is: " << b << endl;
    }

    void showHard() {
        //Това е бонус задачата, с която трябваше да си принтите правоъгълника.
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cout << '*';
            }
            cout << endl;
        }
    }

    double findRadius() {
        //пробвайте да го направите без pow (с побитова операция)
        return (sqrt(pow(a, 2) + pow(b, 2))) / 2;
    }

    int findPerimeter() {
        return 2 * a + 2 * b;
    }

    int findArea() {
        return a * b;
    }
};


int main() {
    int a, b;
    cout << "Enter one of the sides:";
    cin >> a;
    cout << "Enter the second side:";
    cin >> b;
    Rectangle first(a, b);
    first.showEasy();
    first.showHard();
    cout << "The radius of the circle circumscribing the rectangle is: " << first.findRadius() << endl;
    cout << "This rectangle's area is: " << first.findArea() << endl;
    cout << "This rectangle's parameter is: " << first.findPerimeter() << endl;

    return 0;
}
