#ifndef PLAYER_H
#define PLAYER_H

#include "Hero.h"
#include "Units.h"
#include "EquipedItems.h"
#include <vector>
class Player
{
private:
	static const int maxUnits = 3;
	Hero* team[maxUnits];
	EquipedItems* equipedItems;
	Units* units;
	bool selected;
	bool clear;

	//player info
	int gold = 0;
	int run = 1;
	int level = 1;


	//Init
	void initPlayerInfo();
	void initHeroes();
	void initEquipedItems();
	//Arquivos
	void heroesFile(std::ifstream& ifsHeroes, int i);
	void infoFile(std::ifstream& ifsHeroes, int i);


public:
	Player();
	virtual ~Player();
	void render(sf::RenderTarget* target);
	void update(sf::Vector2f mousePos, const float& dt);
	void battlePosition();
	void setTeamToTrue();
	void checkDead();
	void setTeam(int i, Hero* hero);
	void setClear(bool value);
	void updateGold(int value);
	void setSpecialToTrue();
	void RemoveHero(Hero* hero);
	void Save();
	void MenuPosition();
	void AddHeroToTeam(Hero* hero);

	int UnitNumber(Entity* hero);
	int teamSize();
	int getGold();

	bool checkPlayed();
	bool checkDeads();
	bool getClear();
	bool canEquipHero();
	bool CanBuy(Item* item, Hero* hero);

	Hero* getHero();
	Hero* getHero(int i);
	Hero* getRandomHero();
	EquipedItems* getEquipedItems();
};
#endif // !PLAYER_H
