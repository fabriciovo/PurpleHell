#ifndef  ENEMY_H
#define ENEMY_H

#include "Especial.h"
class Enemy : public Entity
{
private:
	Especial* actionEffect;
	Especial* spell;

public:
	Enemy();
	Enemy(float x, float y, std::string name, int hp, int power, sf::Texture* texture);
	virtual ~Enemy();

	void Action(Entity* entity);
	void Special(Entity *entity);
	void update(sf::Vector2f mousePos, const float& dt);
	void removeSelected();
	void updateAnimation(const float &dt);
	

	int getHp();
	std::string getName();

	Especial* GetSpell();
	Especial* GetAction();
};

#endif