#pragma once
#include <iostream>
#include "Team.hpp"

class Tournament
{
public:
	void registerTeam(Team team);
	void begin();
public:
	Tournament(size_t capacity = DefaultCapacity);
	Tournament(const Tournament& other);
	Tournament& operator=(const Tournament& other);
	~Tournament();

private:
	void del();
	void copy(const Tournament& other);
	void resize(size_t newCapacity);
	bool teamIsValidForTournament(const Team& team) const;
	bool teamCountIsPowerOfTwo() const;
	void removeTeamsUntilTeamCountIsPowerOfTwo();
	int findClosestPowerOfTwo(int number) const;
	void removeLastTeam();
	void randomlyShuffleTeams();
	const Team& commenceDuel(const Team& first, const Team& second) const;
	const Team& commenceRound(const Team& first, const Team& second) const;
	int rollDie(int repetitions, int sideCount) const;

	void commenceSingleQualification(Team** teamsArray, size_t& size) const;
	void removeElement(Team** teams, size_t& size, int index) const;
private:

	Team* f_teams;
	size_t f_size;
	size_t f_capacity;

	static const size_t DefaultCapacity = 16;
};

