#pragma once
#include <iostream>
#include <vector>
#include <string>


using namespace std;

//---------------
#include "Hero.h"
#include "Player.h"
//---------------

class Team
{
public:
	string Name;

	struct PlayerHero
	{
		Player player;
		Hero hero;
		PlayerHero() : player(), hero()
		{
		}
	};

	vector <PlayerHero> players;
};

