#ifndef HERO_H
#define HERO_H


#include "Especial.h"

class Hero : public Entity
{
private:
	bool attack;
	int originalX;
	int originalY;

	Especial *spell;

public:
	Hero();
	Hero(float x, float y, std::string name, int hp, int power, int type, sf::Texture* texture);
	Hero(std::string name, int hp, int power);
	Hero(Entity *hero);
	virtual ~Hero();
	void special(Entity *entity);
	void action(Entity * entity);
	Especial * getSpell();
	void updateAnimation(const float &dt);

};

#endif // !HERO_H