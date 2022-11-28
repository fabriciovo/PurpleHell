#include "Inventory.h"

void Inventory::initInventory()
{
	std::ifstream ifsInventory("res/Player/Inventory.txt");
	std::string title = " ", name = " ";
	int type = 0,hp = 0, power = 0, it = 0;


	if (ifsInventory.is_open())
	{
		//std::getline(ifsInventory, title);
		while (ifsInventory.good())
		{
			ifsInventory >> name >> hp >> power >> type;

			sf::Texture *tx;
			tx = new sf::Texture();
			tx->loadFromFile("res/img/items/" + name + ".png");

			this->items.push_back(new Item(93 + (25 * it), 23, name, hp, power, type, tx));
			
			it++;

			if (it == this->maxItems) {
				break;
			}

		}

		ifsInventory.close();
	}
}

Inventory::Inventory()
{
	this->initInventory();
}

Inventory::~Inventory()
{
}

void Inventory::updateInventory(sf::Vector2f mousePos, const float &dt)
{
	for (auto it = items.begin(); it != items.end(); it++) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if ((*it)->getSprite()->getGlobalBounds().contains(mousePos)) {
				(*it)->setSelected(true);
			}
			else {
				(*it)->setSelected(false);
			}
		}
		(*it)->update(mousePos,dt);	
	}


}

void Inventory::renderInventory(sf::RenderTarget * target)
{
	for (auto it = items.begin(); it != items.end(); it++){
		(*it)->render(target);
	}
}

bool Inventory::selectedItem()
{
	for (auto it = items.begin(); it != items.end(); it++) {
		
		if ((*it)->getSelected()) {
			return true;
		}
	}
	return false;
}

Entity * Inventory::getItem()
{

	for (auto it = items.begin(); it != items.end(); it++) {
		if ((*it)->getName() != "slot") {
			if ((*it)->getSelected()) {
				return (*it);
			}
		}
	}
	return nullptr;
}

void Inventory::setItem(int i, Item * item)
{
	int count = 0;
	for (auto it = items.begin(); it != items.end(); it++) {

		if(i == count){
			(*it) = item;
		}
		count++;
	}
}

Entity * Inventory::getItemById(int i)
{
	int count = 0;
	for (auto it = items.begin(); it != items.end(); it++) {

		if (i == count) {
			return (*it);
		}
		count++;
	}


}
int Inventory::inventoryNumber()
{

	int i = 0;
	for (auto it = items.begin(); it != items.end(); it++) {
		if ((*it)->getSelected()) {
			return i;
		}
		i++;
	}

}
