#ifndef PLAYER_H
#define PLAYER_H

#include "Hero.h"
#include "EquipedItems.h"
#include <vector>
class Player
{
private:
	static const int maxUnits = 3;
	Hero* team[maxUnits];
	EquipedItems *equipedItems;
	
	bool selected;
	bool clear;

	//Init
	void initHeroesMenu();
	void initHeroesBattle();
	void initEquipedItems();
	//Arquivos
	void ArquivoHeroesBattle(std::ifstream &ifsHeroes, int i);
	void ArquivoHeroesMenu(std::ifstream &ifsHeroes, int i);

public:
	Player();
	Player(bool battle);
	virtual ~Player();
	void render(sf::RenderTarget* target);
	void update(sf::Vector2f mousePos,const float &dt);
	void battlePosition();

	Entity* getHero();
	Entity* getTeam(int i);
	bool checkPlayed();
	void setTeamToTrue();
	bool checkDeads();
	void checkDead();
	int UnitNumber(Entity* hero);
	void setTeam(int i, Hero* hero);
	EquipedItems *getEquipedItems();
	bool getClear();
	void setClear(bool value);
	int teamSize();
};
#endif // !PLAYER_H
