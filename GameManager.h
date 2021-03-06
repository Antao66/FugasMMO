#include <iostream>
#include <vector>
#include <string>

using namespace std;

//----------------------
#include "GameSession.h"
//----------------------

class GameManager
{
	vector <GameSession> GameSessions;
	PlayerManager players;
	HeroManager heroes;
	TeamManager teams;
public:

	GameManager(PlayerManager _players, HeroManager _heroes)
		: players(_players), heroes(_heroes)
	{
	}

	void PerformGameSession(PlayerManager& players)
	{
		teams.GenerateNewTeams(players, heroes);

		for (int i = 0; i < teams.teams_manager.size() - 1; i++)
		{
			GameSession temp(teams.teams_manager[i], teams.teams_manager[i + 1]);

			for (int i = 0; i < temp.team_one.players.size(); i++)
			{
				players.ChangeRank(temp.team_one.players[i].player.Id, -25);
				players.ChangeRank(temp.team_two.players[i].player.Id, -25);
				players.ChangeRank(temp.winner.players[i].player.Id, 50);
			}

			GameSessions.push_back(temp);
		}

		teams.GetTeamInfo(players, heroes);
	}
};

void InitializeUnits(PlayerManager& players, HeroManager& heroes)
{
	vector<string> player_names = { "Christopher-Jay Garcia", "Cjay Jones", "Colby-Jay Johnson", "C-Jay Smith","Chasey Rodriguez", "Cary Miller","Coady Davis","Cally Jackson","Cassidy Thompson","Carter-Jay Anderson","Cortney Thomas","Cauley Moore","Chesley White","Charlie-Jay Martinez","Chaudry Martin", "Chankoowashtay Hall" };
	vector<string> hero_names = { "Terrifying-Man", "Professor Terri", "Howling-Man", "Captain How","Alarming","Struthio-Camelus-Man", "Alligator-Man", "Angora","Wonderful-Man","Agent Ant","The Lucky Sage","Glorious Daggers", "Remix", "Karma", "Starlight", "Electron Swan", "Dark Slayer", "Armed", "Phantom Archer", "Doctor Gentle Hawk", "Ace" };
	int random;
	string temp_name;
	for (int i = 0; i < 10; i++)
	{
		random = rand() % player_names.size();
		temp_name = player_names[random];
		player_names.erase(player_names.begin() + random);

		players.CreateNewPlayer(i + 1, temp_name, 0);
	}
	for (int i = 0; i < 15; i++)
	{
		random = rand() % hero_names.size();
		temp_name = hero_names[random];
		hero_names.erase(hero_names.begin() + random);

		heroes.CreateHero(i + 1, temp_name, rand() % 60 + 10, rand() % 60 + 10);
	}
};

