#ifndef HERO_H
#define HERO_H


#include "Especial.h"

class Hero : public Entity
{
private:
	bool attack;
	int originalX;
	int originalY;
	Especial* actionEffect;
	Especial *spell;
	bool viewStatus;

public:
	Hero();
	Hero(float x, float y, std::string name, std::string job, int hp, int power, int special, sf::Texture* texture);
	Hero(std::string name, std::string job, int hp, int power, int special);
	Hero(Entity *hero);
	void Special(Entity *entity);
	void Action(Entity * entity);
	void UpdateAnimation(const float &dt);
	void SetViewStatus(bool);
	bool GetViewStatus();

	Especial* GetAction();
	Especial * GetSpell();

	virtual ~Hero();
};

#endif // !HERO_H