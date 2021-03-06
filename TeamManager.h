#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

//---------------
#include "Team.h"
//---------------

class TeamManager
{
public:

	vector <Team> teams_manager;
	void GenerateNewTeams(PlayerManager players, HeroManager heroes)
	{
		this->teams_manager;
		teams_manager.clear();

		int p_iterator;
		int random_player;
		vector <int> random_players(players.players.size());
		iota(random_players.begin(), random_players.end(), 0);

		int h_iterator;
		int random_hero;
		vector <int> random_heroes(heroes.heroes_manager.size());
		iota(random_heroes.begin(), random_heroes.end(), 0);

		for (int t = 0; t < 2; t++)
		{
			teams_manager.resize(t + 1);
			for (int i = 0; i < 5; i++)
			{
				p_iterator = rand() % random_players.size();
				random_player = random_players[p_iterator];
				random_players.erase(random_players.begin() + p_iterator);

				h_iterator = rand() % random_heroes.size();
				random_hero = random_heroes[h_iterator];
				random_heroes.erase(random_heroes.begin() + h_iterator);

				teams_manager[t].players.resize(i + 1);
				teams_manager[t].players[i].player = players.players[random_player];
				teams_manager[t].players[i].hero = heroes.heroes_manager[random_hero];
			}
		}
	}
	void GetTeamInfo(PlayerManager players, HeroManager heroes)
	{
		for (const auto& elem : teams_manager)
		{
			for (int i = 0; i < 5; i++)
			{
				players.ShowPlayerInfo(elem.players[i].player.Name);
				heroes.ShowHeroInfo(elem.players[i].hero.Name);
			}
			cout << "\n\n\n";
		}
	}
};

