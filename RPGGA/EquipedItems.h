#ifndef EQUIPEITEMS_H
#define EQUIPEDITEMS_H

#include "Inventory.h"

class EquipedItems
{

private:
	sf::Texture* texture;
	sf::Sprite* sprite;
	static const int maxItems = 6;
	sf::Texture textures[maxItems];
	Item *items[maxItems];
	void initEquipedItems();
	void ArquivoEquiped(std::ifstream &ifsEquipedItems, int i);
public:
	EquipedItems();
	virtual ~EquipedItems();

	void renderEquipedItems(sf::RenderTarget *target);
	void updateEquipedItems(sf::Vector2f mousePos,const float &dt);
	void useItem(Item *item);

	Entity *getItem();
	Entity *getItemById(int i);
	void setItem(int i, Item *item);
	int UnitNumber(Entity *item);
};

#endif // !EQUIPEITEMS_H