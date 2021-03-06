#include <iostream>
#include <vector>
#include <string>

using namespace std;

//---------------
#include "Hero.h"
//---------------
class HeroManager
{
public: 
public:
	vector <Hero> heroes_manager;
	void CreateHero(int Id, string Name, int HP, int Damage)
	{
		Hero new_hero(Id, Name, HP, Damage);
		heroes_manager.push_back(new_hero);
	}

	Hero GetHeroByName(string HeroName)
	{
		for (int i = 0; i < heroes_manager.size(); i++)
		{
			if (HeroName == heroes_manager[i].Name)
			{
				return heroes_manager[i];
			}
		}
		Hero empty_hero(0, "This player does not exist", 0, 0);
		return empty_hero;
	}

	Hero GetHeroById(int Id)
	{
		for (int i = 0; i < heroes_manager.size(); i++)
		{
			if (Id == heroes_manager[i].Id)
			{
				return heroes_manager[i];
			}
		}
		Hero empty_hero(0, "This player does not exist", 0, 0);
		return empty_hero;
	}
	void DeleteHero(string HeroName = "", int Id = 0)
	{
		this->heroes_manager;
		for (int i = 0; i < heroes_manager.size(); i++)
		{
			if (HeroName == heroes_manager[i].Name || Id == heroes_manager[i].Id)
			{
				heroes_manager.erase(heroes_manager.begin() + i);
				break;
			}
		}
	}
	void AllHeroesInfo()
	{
		for (const auto& elem : heroes_manager)
		{
			cout << "Name: " << elem.Name << "\t" << "Id: " << elem.Id << "\tHP: " << elem.HP << "\tDamage: " << elem.Damage << endl;
		}
	}
	void ShowHeroInfo(string HeroName, int HeroId = 0)
	{
		for (int i = 0; i < heroes_manager.size(); i++)
		{
			if (HeroName == heroes_manager[i].Name || HeroId == heroes_manager[i].Id)
			{
				cout << "Name: " << heroes_manager[i].Name << "\t" << "Id: " << heroes_manager[i].Id << "\tHP: " << heroes_manager[i].HP << "\tDamage: " << heroes_manager[i].Damage << endl;
				break;
			}
		}

	}
};

