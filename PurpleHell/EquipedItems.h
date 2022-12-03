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
	void removeItem(Item * equipedItem);
	Item *getItem();
	Entity *getItemById(int i);
	void setItem(Item *item);
	int UnitNumber(Entity *item);
	bool canEquip();
	void save();
};

#endif // !EQUIPEITEMS_H