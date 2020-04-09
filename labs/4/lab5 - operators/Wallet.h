#pragma once
#include "Money.h"

class Wallet {
	Money money;
public:
	Wallet(const Money& money);
	Wallet();

	void putMoney(const Money& money);
	Money drawMoney(const Money& money);

	void print();
};