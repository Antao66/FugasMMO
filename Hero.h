#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Hero
{
public:
	int Id, HP, Damage;
	string Name;
	Hero(int heroId = 0, string heroName = "", int heroHP = 0, int heroDamage = 0)
	{
		Id = heroId;
		Name = heroName;
		HP = heroHP;
		Damage = heroDamage;
	}
};

