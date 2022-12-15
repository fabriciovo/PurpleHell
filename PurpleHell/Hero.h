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
	Hero(float x, float y, std::string name, std::string job, int hp, int power, int special, sf::Texture* texture);
	Hero(std::string name, std::string job, int hp, int power, int special);
	Hero(Entity *hero);
	virtual ~Hero();
	void Special(Entity *entity);
	void Action(Entity * entity);
	Especial * GetSpell();
	void UpdateAnimation(const float &dt);

};

#endif // !HERO_H