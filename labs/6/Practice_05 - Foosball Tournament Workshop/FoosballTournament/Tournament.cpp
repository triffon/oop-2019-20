#include "Tournament.hpp"
#include <time.h>

void Tournament::registerTeam(Team team)
{
	if (!team.isValid())
	{
		std::cout << "Team is invalid." << std::endl;
		return;
	}

	if (!teamIsValidForTournament(team))
	{
		std::cout << "Invalid number of CTOs or CEOs." << std::endl;
		return;
	}

	if (f_size >= f_capacity)
	{
		resize(f_capacity * 2);
	}

	f_teams[f_size] = team;
	f_size++;
}

void Tournament::begin()
{
	if (!teamCountIsPowerOfTwo())
	{
		removeTeamsUntilTeamCountIsPowerOfTwo();
	}

	randomlyShuffleTeams();

	Team** winningTeams = new Team * [f_size];
	size_t winningTeamSize = f_size;

	for (size_t i = 0; i < f_size; i++)
	{
		winningTeams[i] = &(f_teams[i]);
	}

	while (winningTeamSize != 1)
	{
		commenceSingleQualification(winningTeams, winningTeamSize);
	}

	winningTeams[0]->print();
}

Tournament::Tournament(size_t capacity)
	: f_capacity(capacity), f_size(0)
{
	f_teams = new Team[capacity];
}

Tournament::Tournament(const Tournament& other)
	: Tournament()
{
	if (this != &other)
	{
		copy(other);
	}
}

Tournament& Tournament::operator=(const Tournament& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

Tournament::~Tournament()
{
	del();
}

void Tournament::del()
{
	delete[] f_teams;
	f_teams = nullptr;
}

void Tournament::copy(const Tournament& other)
{
	f_capacity = other.f_capacity;
	f_size = other.f_size;

	f_teams = new Team[f_capacity];
	for (size_t i = 0; i < f_size; i++)
	{
		f_teams[i] = other.f_teams[i];
	}
}

void Tournament::resize(size_t newCapacity)
{
	f_capacity = newCapacity;
	Team* newTeams = new Team[newCapacity];

	for (size_t i = 0; i < f_size; i++)
	{
		newTeams[i] = f_teams[i];
	}

	delete[] f_teams;
	f_teams = newTeams;
}

bool Tournament::teamIsValidForTournament(const Team& team) const
{
	int ceoCount = 0;
	int ctoCount = 0;

	for (size_t i = 0; i < f_size; i++)
	{
		ceoCount += f_teams[i].getCeoCount();
		ctoCount += f_teams[i].getCtoCount();
	}

	ceoCount += team.getCeoCount();
	ctoCount += team.getCtoCount();

	bool officersDuplicationDoesNotExist = ceoCount < 2 && ctoCount < 2;

	return officersDuplicationDoesNotExist;
}

bool Tournament::teamCountIsPowerOfTwo() const
{
	// Bit operations way.
	// return (f_size & f_size-1) == 0;

	int currentSize = f_size;
	while (currentSize > 1)
	{
		if (currentSize % 2 != 0)
		{
			return false;
		}
		currentSize /= 2;
	}

	return true;
}

void Tournament::removeTeamsUntilTeamCountIsPowerOfTwo()
{
	int targetSize = findClosestPowerOfTwo(f_size);
	while (f_size > targetSize)
	{
		removeLastTeam();
	}
}

int Tournament::findClosestPowerOfTwo(int number) const
{
	int powerOfTwo = 1;
	int twoToThePower = 2;

	while (twoToThePower < number)
	{
		twoToThePower *= 2;
		powerOfTwo++;
	}
	return twoToThePower / 2;
}

void Tournament::removeLastTeam()
{
	if (f_size == 0)
	{
		return;
	}

	f_size--;
}

void Tournament::randomlyShuffleTeams()
{
	srand(time(NULL));
	int shuffleCount = rand() % (f_size * 2);

	int indexOne;
	int indexTwo;
	for (size_t i = 0; i < shuffleCount; i++)
	{
		indexOne = rand() % f_size;
		indexTwo = rand() % f_size;

		// TODO: Implement custom swap if time is left.
		std::swap(f_teams[indexOne], f_teams[indexTwo]);
	}
}

const Team& Tournament::commenceDuel(const Team& first, const Team& second) const
{
	const int RoundCount = 3;
	int firstWinsCount = 0;
	int secondWinsCount = 0;

	Team winningTeam;

	for (size_t i = 0; i < RoundCount; i++)
	{
		winningTeam = commenceRound(first, second);

		if (&winningTeam == &first)
		{
			firstWinsCount++;
		}
		else
		{
			secondWinsCount++;
		}
	}

	const char* winningTeamText = (firstWinsCount > secondWinsCount) ? "First" : "Second";
	std::cout << "Duel winner is: " << winningTeamText << " team!" << std::endl;

	return firstWinsCount > secondWinsCount ? first : second;
}

const Team& Tournament::commenceRound(const Team& first, const Team& second) const
{
	const int DiceRollCount = 3;
	const int DiceSideCount = 6;

	int firstTeamDiceRoll;
	int secondTeamDiceRoll;

	do
	{
		firstTeamDiceRoll = rollDie(3, 6);
		secondTeamDiceRoll = rollDie(3, 6);

	} while (firstTeamDiceRoll == secondTeamDiceRoll);

	std::cout << "First team rolled " << firstTeamDiceRoll
		<< ", second team dice roll: " << secondTeamDiceRoll << std::endl;

	return firstTeamDiceRoll > secondTeamDiceRoll ? first : second;

}

int Tournament::rollDie(int repetitions, int sideCount) const
{
	srand(time(NULL));

	int result = 0;

	for (size_t i = 0; i < repetitions; i++)
	{
		result += rand() % (sideCount + 1);
	}

	return result;
}

void Tournament::commenceSingleQualification(Team** teams, size_t& size) const
{
	for (int i = size - 1; i >= 0; i -= 2)
	{
		// 0 1 2 3
		const Team& winner = commenceDuel(*(teams[i]), *(teams[i - 1]));

		if (&winner != teams[i])
		{
			removeElement(teams, size, i);
		}
		else
		{
			removeElement(teams, size, i - 1);
		}
	}
}

void Tournament::removeElement(Team** teams, size_t& size, int index) const
{
	for (size_t i = index; i < size - 1; i++)
	{
		teams[i] = teams[i + 1];
	}

	size--;
}
