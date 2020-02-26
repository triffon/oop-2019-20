#include <iostream>
#include <cstring>
using namespace std;

const long long MIN_CREDIT_CARD_NUMBER = 1000000000000000; // 1000 0000 0000 0000
const long long MAX_CREDIT_CARD_NUMBER = 9999999999999999; // 9999 9999 9999 9999
const unsigned MAX_ACCOUNTS = 20;
const unsigned MAX_ACCOUNT_NAME_LENGTH = 50;

struct BankAccount {
	char name[30];
	int balance;
	long long creditCard; // starts 1000 0000 0000 0000

	void print() {
		cout << "Bank Account: " << name << endl;
		cout << "Balance:      " << balance << endl;
		cout << "Credit Card:  " << creditCard << endl;
	}
};

struct Bank {
private:
	BankAccount accounts[MAX_ACCOUNTS];
	int accountsLength;
	int bankBalance;
	char name[MAX_ACCOUNT_NAME_LENGTH];

public:
	void setUpBank(const char* bankName) {
		strcpy(name, bankName); // If you are using visual studio, use strcpy_s instead of strcpy
		accountsLength = 0;
		bankBalance = 0;
	}

	bool openBankAccount(const char* accountName, int balance, long long creditCardNumber) {
		if (accountsLength == MAX_ACCOUNTS) {
			cout << "Maximum accounts reached!" << endl;
			return false;
		}
		if (balance < 1) {
			cout << "Invalid account balance! Account balance should be positive!" << endl;
			return false;
		}
		if (!isCreditCardValid(creditCardNumber)) {
			cout << "Invalid credit card number!" << endl;
			return false;
		}
		if (findBankAccountByName(accountName) != NULL) {
			cout << "Bank account with this name already exists!" << endl;
			return false;
		}
		if (findBankAccountByCreditCard(creditCardNumber) != NULL) {
			cout << "Account with this credit card already exists!" << endl;
			return false;
		}
		strcpy(accounts[accountsLength].name, accountName); // If you are using visual studio, use strcpy_s instead of strcpy
		accounts[accountsLength].balance = balance;
		accounts[accountsLength].creditCard = creditCardNumber;
		bankBalance += balance;
		++accountsLength;
		return true;
	}

	bool isCreditCardValid(long long creditCardNumber) {
		return creditCardNumber >= MIN_CREDIT_CARD_NUMBER
			&& creditCardNumber <= MAX_CREDIT_CARD_NUMBER;
	}

	BankAccount* findBankAccountByName(const char* name) {
		for (int idx = 0; idx < accountsLength; ++idx) {
			if (strcmp(accounts[idx].name, name) == 0) {
				return &accounts[idx];
			}
		}
		return NULL;
	}

	BankAccount* findBankAccountByCreditCard(long long creditCard) {
		for (int idx = 0; idx < accountsLength; ++idx) {
			if (accounts[idx].creditCard == creditCard) {
				return &accounts[idx];
			}
		}
		return NULL;
	}

	void printBankInformation() {
		cout << "Accounts for Bank: " << name << endl;
		for (int accountIdx = 0; accountIdx < accountsLength; ++accountIdx) {
			cout << "-------- Account Record Num: " << accountIdx << " --------" << endl;
			accounts[accountIdx].print();
			cout << endl;
		}
		cout << "Total Bank Balance: " << bankBalance << endl;
	}
};

int main() {
	Bank ourBank;
	ourBank.setUpBank("FMI Bank");
	ourBank.openBankAccount("Account 1", 1000, 1000000000000000);
	ourBank.openBankAccount("Account 2", 2000, 1000000000000001);

	// Will not open. Invalid balance.
	ourBank.openBankAccount("Account 3", -1000, 1000000000000002);

	// Will not open. Credit card already exists
	ourBank.openBankAccount("Account 3", 2000, 1000000000000001);

	// Will not open. Ban account already exists
	ourBank.openBankAccount("Account 2", 2000, 1000000000000001);

	ourBank.openBankAccount("Account 3", 2000, 1000000000000002);
	ourBank.openBankAccount("Account 4", 21000, 1000000000000003);

	ourBank.printBankInformation();
	cin.get();
}
