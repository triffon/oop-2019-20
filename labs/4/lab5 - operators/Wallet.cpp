#include "Wallet.h"
#include <iostream>
using namespace std;

Wallet::Wallet() {
	money = Money(0, 0);
}

Wallet::Wallet(const Money& money) {
	this->money = money;
}

void Wallet::putMoney(const Money& money)
{
	this->money += money;
}

Money Wallet::drawMoney(const Money& money)
{
	if (this->money < money) {
		Money result = this->money;
		this->money = Money(0, 0);
		return result;
	}
	this->money -= money;
	return money;
}

void Wallet::print()
{
	cout << "Money in wallet: ";
	money.print();
}


