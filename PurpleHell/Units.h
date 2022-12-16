#ifndef UNITS_H
#define UNITS_H
// !UNITS_h

#include <fstream>
#include <sstream>
#include <list> 
#include <iterator> 

#include "Hero.h"

class Units
{
private:
	static const int maxUnitsInventory = 10;
	Hero *heroes[maxUnitsInventory];

	void initUnits();
	void ArquivoUnits(std::ifstream &, int);
	
public:
	Units();
	virtual ~Units();

	void renderUnits(sf::RenderTarget* target);
	void updateUnits(sf::Vector2f mousePos,const float &dt);
	void setUnits(Hero* hero);
	void removeHero(Hero* hero);
	void equipHero(Hero* hero);
	void Save();
	int UnitNumber();

	bool selectedHero();
	bool canRemoveHero();

	Hero* getTeam(int i);
	Hero* getHero();


};
#endif 
