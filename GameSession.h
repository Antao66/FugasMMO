#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>

using namespace std;

//---------------
#include "Team.h"
#include "TeamManager.h"
//---------------

class GameSession
{
public:
	string start_time;
	Team team_one;
	Team team_two;
	Team winner;

	GameSession(Team _team_one, Team _team_two)
		: team_one(_team_one), team_two(_team_two)
	{
		using clock = chrono::high_resolution_clock;
		chrono::time_point<clock> start_time = clock::now();
		winner = CalculateWinner(_team_one, _team_two);
	}

	Team CalculateWinner(Team _team_one, Team _team_two)
	{
		int team_one_damage = 0, team_two_damage = 0;
		int team_one_health = 0, team_two_health = 0;
		for (int i = 0; i < _team_one.players.size(); i++)
		{
			team_one_damage = _team_one.players[i].hero.Damage;
			team_one_health = _team_one.players[i].hero.HP;
		}
		for (int i = 0; i < _team_two.players.size(); i++)
		{
			team_two_damage = _team_two.players[i].hero.Damage;
			team_two_health = _team_two.players[i].hero.HP;
		}

		if (team_one_health - team_two_damage < team_two_health - team_one_damage)
		{
			return _team_two;
		}
		return _team_one;
	}
};

