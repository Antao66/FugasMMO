#include <iostream>
#include <vector>
#include <string>

using namespace std;

//---------------
#include "Player.h"
//---------------

class PlayerManager
{
public:
	vector <Player> players;
	void CreateNewPlayer(int playerId, string playerName, int playerRank)
	{
		Player new_player(playerId, playerName, playerRank);
		players.push_back(new_player);
	}
	void AssignHero(int Id, Hero hero)
	{
		this->players;
		for (auto& elem : players)
		{
			if (Id = elem.Id)
			{
				elem.hero = hero;
			}
		}
	}
	Player GetPlayerByName(string playerName)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (playerName == players[i].Name)
			{
				return players[i];
			}
		}
		Player empty_player(0, "This player does not exist", 0);
		return empty_player;
	}

	Player GetPlayerById(int playerId)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (playerId == players[i].Id)
			{
				return players[i];
			}
		}
		Player empty_player(0, "This player does not exist", 0);
		return empty_player;
	}
	void DeletePlayer(string playerName = "", int playerId = 0)
	{
		this->players;
		for (int i = 0; i < players.size(); i++)
		{
			if (playerName == players[i].Name || playerId == players[i].Id)
			{
				players.erase(players.begin() + i);
				break;
			}
		}
	}
	void ChangeRank(int playerId, int rank_change = 0)
	{
		this->players;

		players[playerId - 1].Rank += rank_change;
	}
	void AllPlayersInfo()
	{
		for (const auto& elem : players)
		{
			cout << "Name: " << elem.Name << "\t" << "Id: " << elem.Id << "\tRank: " << elem.Rank << endl;
		}
	}
	void ShowPlayerInfo(string playerName, int playerId = 0)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (playerName == players[i].Name || playerId == players[i].Id)
			{
				cout << "Name: " << players[i].Name << "\t" << "Id: " << players[i].Id << "\tRank: " << players[i].Rank << endl;
				break;

			}
		}
	}
};

