#ifndef INVENTORY_H
#define INVENTORY_H

#include "SFML\Graphics.hpp"
#include <fstream>
#include <sstream>
#include "Item.h"

#include <list> 
#include <iterator> 
class Inventory
{
private:
	static const int maxItems = 6;
	sf::Texture* texture;
	sf::Sprite* sprite;

	std::list<Item*> items;
	
	void initInventory();
public:
	Inventory();
	virtual ~Inventory();

	void renderInventory(sf::RenderTarget *target);
	void updateInventory(sf::Vector2f mousePos, const float &dt);
	void setItem(int i, Item* item);

	bool selectedItem();
	int inventoryNumber();

	Entity* getItem();
	Entity* getItemById(int i);

};

#endif