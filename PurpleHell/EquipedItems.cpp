#include "EquipedItems.h"



void EquipedItems::initEquipedItems()
{
	std::ifstream ifsEquipedItems("res/Player/equiped.txt");
	ArquivoEquiped(ifsEquipedItems, 0);
}

EquipedItems::EquipedItems()
{
	this->initEquipedItems();
}


EquipedItems::~EquipedItems()
{
}

void EquipedItems::renderEquipedItems(sf::RenderTarget * target)
{
	for (int i = 0; i < this->maxItems; i++) {
		this->items[i]->render(target);
	}
}

void EquipedItems::updateEquipedItems(sf::Vector2f mousePos,const float &dt)
{
	for (int i = 0; i < this->maxItems; i++) {
		if (this->items[i])
			this->items[i]->update(mousePos, dt);
	}
}


Entity* EquipedItems::getItem()
{
	for (int i = 0; i < this->maxItems; i++) {
		if (this->items[i]) {
			if (items[i]->getSelected()) {
				return this->items[i];
			}
		}
	}
	return nullptr;


}

Entity* EquipedItems::getItemById(int i)
{
	return this->items[i];
}

void EquipedItems::setItem(int i, Item * item)
{
	this->items[i] = item;
}


int EquipedItems::UnitNumber(Entity *item)
{
	for (int i = 0; i < this->maxItems; i++) {
		if (this->items[i]->getName() == item->getName()) {
			return i;
		}
	}
}
//Arquivos
void EquipedItems::ArquivoEquiped(std::ifstream &ifsEquipedItems, int i)
{
	std::string name = " ";
	int hp = 0, power = 0, type = 0;

	if (ifsEquipedItems.is_open())
	{

		if (!ifsEquipedItems.eof())
		{

			ifsEquipedItems >> name >> hp >> power >> type;

			sf::Texture *tex;
			tex = new sf::Texture();
			tex->loadFromFile("res/img/items/" + name + ".png");
			this->items[i] = (new Item(93 + (25 * i), 118, name, hp, power, type, tex));
			i++;

			ArquivoEquiped(ifsEquipedItems, i);
		}
		else {
			ifsEquipedItems.close();
		}
	}
}
