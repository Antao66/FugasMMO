#pragma once

#include <iostream>

using namespace std;

//---------------

//---------------

using namespace std;

class Player
{
public:
	int Id, Rank;
	string Name;
	Hero hero;
	Player(int playerId = 0, string playerName = "", int playerRank = 0)
	{
		Id = playerId;
		Name = playerName;
		Rank = playerRank;
	}
};

