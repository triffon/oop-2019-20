#include <iostream>
#include <cassert>
using namespace std;

#include "food.h"
#include "pizza.h"
#include "salad.h"
#include "menu.h"
  

int main() {

	Pizza p1("Margherita", 420, 6, 5.90);
	Pizza p2("Capricciosa", 560, 8, 9.30);
	// p1.print();
	// p1.consume();
	// p1.print();

	Salad s1(3, false, 330, 4.70);
	// s1.print();
	// s1.consume();
	// s1.print();

	Food* f = &p2;
	// f->print();

	Menu m(10);
	m.addFood(&p1);
	m.addFood(&s1);
	m.addFood(f);
	m.addFood(&p2);
	m.remove(f);
	m.print();

	m.getCheapestFood();

	cout << endl << endl;
	cout << "Consume" << endl;
	m.consumeFood(&s1);
	m.consumeFood(&p2);
	m.print();

	return 0;
}