#include "Wallet.h"
#include "Money.h"
#include <iostream>
using namespace std;




int main() {
	Money m1(3, 30);
	Money moneyToDraw(2, 15);
	Wallet wallet(m1);

	Money moneyDrawn = wallet.drawMoney(moneyToDraw);
	moneyDrawn.print();
	wallet.print();

	moneyDrawn = wallet.drawMoney(moneyToDraw);
	moneyDrawn.print();
	wallet.print();

	Money moneyToPut(10, 10);
	wallet.putMoney(moneyToPut);
	wallet.print();
}