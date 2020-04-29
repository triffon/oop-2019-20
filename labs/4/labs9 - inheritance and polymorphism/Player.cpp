#include "Player.h"
#include <cstring>

Player::Player(int health, const char* name): health(health)
{
	strcpy_s(this->name, strlen(name) + 1, name);
}

