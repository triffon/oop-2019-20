#include "Game.hpp"

std::ostream& operator<<(std::ostream& out, Dungeon dungeon)
{
	out << "[" << std::endl;
	for (size_t i = 0; i < dungeon.count; i++)
	{
		dungeon.monsters[i]->deserialize(out);
		out << "]" << std::endl;
	}

	return out;
}
