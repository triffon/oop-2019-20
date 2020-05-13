#include "PlayerTypes.h"
#include <iostream>
#include <string>


bool HumanPlayer::guess(int number)
{
	cout << "Current number is " << number << ". Guess next number! Enter up/down" << endl;
	string input;
	while (true) {
		cin >> input;
		if (input == "up")
			return true;
		else if (input == "down")
			return false;
		cout << "Invalid command. Try again!" << endl;
	}
	return false;
}

bool RandomAIPlayer::guess(int number)
{
	return rand() % 2 == 0;
}

bool SmartAIPlayer::guess(int number)
{
	return number < 50;
}

bool DumbAIPlayer::guess(int number)
{
	return number > 50;
}
