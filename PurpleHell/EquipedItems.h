#ifndef EQUIPEITEMS_H
#define EQUIPEDITEMS_H

#include "Inventory.h"

class EquipedItems
{

private:
	static const int maxItems = 6;
	Item *items[maxItems];
	void initEquipedItems();
	void ArquivoEquiped(std::ifstream &ifsEquipedItems, int i);
public:
	EquipedItems();
	virtual ~EquipedItems();

	void renderEquipedItems(sf::RenderTarget *target);
	void updateEquipedItems(sf::Vector2f mousePos,const float &dt);
	void removeItem(Item * equipedItem);
	void removeItem(int equipedItemId);
	void setItem(Item *item);
	void save();

	bool canEquip();
	
	int UnitNumber(Entity *item);
	int getItemId();

	Item *getItem();
	Entity *getItemById(int i);
};

#endif // !EQUIPEITEMS_H