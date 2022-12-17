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
	int gold = 10;
	bool selected;
	bool clear;

	//Init
	void initHeroesMenu();
	void initHeroesBattle();
	void initEquipedItems();
	//Arquivos
	void ArquivoHeroesBattle(std::ifstream& ifsHeroes, int i);
	void ArquivoHeroesMenu(std::ifstream& ifsHeroes, int i);

public:
	Player();
	Player(bool battle);
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
	Entity* getTeam(int i);
	EquipedItems* getEquipedItems();
	Entity* getRandomHero();
};
#endif // !PLAYER_H
