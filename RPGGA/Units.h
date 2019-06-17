#ifndef UNITS_H
#define UNITS_h
// !UNITS_h

#include "Player.h"

class Units
{
private:
	sf::Texture* texture;
	sf::Sprite* sprite;
	static const int maxUnitsInventory = 3;
	Hero *heroes[maxUnitsInventory];

	void initUnits();
	void ArquivoUnits(std::ifstream &, int);
	
public:
	Units();
	virtual ~Units();

	void renderUnits(sf::RenderTarget* target);
	void updateUnits(sf::Vector2f mousePos,const float &dt);

	bool selectedHero();
	Entity* getHero();
	void setUnits(int i, Hero* hero);
	Entity* getTeam(int i);
	int UnitNumber();

};
#endif 
