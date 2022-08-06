#ifndef  ENEMY_H
#define ENEMY_H

#include "Especial.h"
class Enemy : public Entity
{

public:
	Enemy();
	Enemy(float x, float y, std::string name, int hp, int power, sf::Texture* texture);
	Enemy(std::string name, int hp, int power, sf::Texture* texture);
	virtual ~Enemy();

	void action(Entity* entity);
	void special(Entity *entity);
	void update(sf::Vector2f mousePos, const float& dt);
	int getHp();
	std::string getName();
	void removeSelected();

	void updateAnimation(const float &dt);
};

#endif