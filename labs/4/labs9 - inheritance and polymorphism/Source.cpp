#include <iostream>
#include "Monster.h"
#include "Soldier.h"
#include "Villigar.h"
using namespace std;


void fight(Player* player1, Player* player2) {
	if (player1 == player2)
		return;
	cout << "Fight " << player1->getName()
		 << " vs " << player2->getName() << endl;

	player1->takeDamage(player2->getDamage()); // polymorphism
	player2->takeDamage(player1->getDamage()); // polymorphism

	cout << "After fight: " << endl;
	player1->print();
	player2->print();
	cout << "----------------------" << endl;
}

int main() {
	Soldier soldier1;
	Soldier toughSoldier(200, 50, 300);
	Monster monster;
	Villager villigar;
	Villager v2;

	fight(&soldier1, &monster);
	fight(&toughSoldier, &monster);
	fight(&soldier1, &toughSoldier);
	fight(&monster, &villigar);

	Player* soldier = new Soldier();
	soldier->print(); // polymorphism
	delete soldier;   // Soldier destructor will be called, since it is virtual
					  // If it was not virtual, we would only call Player's destructor
}