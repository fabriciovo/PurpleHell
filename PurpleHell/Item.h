#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"
#include "Especial.h"

class Item : public Entity
{
private:
	Especial* actionEffect;
public:
	Item();
	Item(int x, int y, std::string name, int hp, int power, int special, sf::Texture* texture);
	virtual ~Item();
	void Action(Entity* entity);
	void Special(Entity *entity);
	void useItem(int i, Entity *entity);
	
	void Potion(Entity *entity);
	void Axe(Entity *entity);
	void MagicAxe(Entity *entity);
	void Sword(Entity *entity);
	void Knife(Entity *entity);

	Especial* GetAction();

	enum Items
	{
		item_slot = 0,
		item_potion = 1,
		item_knife = 2,
		item_axe = 3,
		item_sword = 4,
		item_MagicAxe = 5
	};
};
#endif // !ITEM_H
