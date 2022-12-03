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
	int count = 0;
	int countSecondLine = 0;
	for (auto it = items.begin(); it != items.end(); it++) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if ((*it)->getSprite()->getGlobalBounds().contains(mousePos)) {
				(*it)->setSelected(true);
			}
			else {
				(*it)->setSelected(false);
			}
		}
		if (count < 10) {
			(*it)->SetPosition(92 + (25 * count), 22);

			count++;
		}
		else {
			(*it)->SetPosition(92 + (25 * countSecondLine), 48);
			countSecondLine++;
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

Item * Inventory::getItem()
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
			break;
		}
		count++;

	}
}

void Inventory::setItem(Item* item)
{
	for (auto it = items.begin(); it != items.end(); it++) {
		if ((*it)->getName() == "slot") {
			(*it) = item;
			break;
		}
	}
}

void Inventory::save()
{
	std::fstream ofsInventory;
	ofsInventory.open("res/Player/Inventory.txt", std::ofstream::out | std::ofstream::trunc);

	for (auto it = items.begin(); it != items.end(); it++) {
			ofsInventory
				<< (*it)->getName()
				<< " " << (*it)->getHp()
				<< " " << (*it)->getPower()
				<< " " << (*it)->getType() << std::endl;
	}

	
	ofsInventory.close();
}

bool Inventory::canPutItemInInventory()
{
	for (auto it = items.begin(); it != items.end(); it++) {
		if ((*it)->getName() == "slot") {
			return true;
		}
	}
	return false;
}

Item * Inventory::getItemById(int i)
{
	int count = 0;
	for (auto it = items.begin(); it != items.end(); it++) {

		if (i == count) {
			return (*it);
		}
		count++;
	}


}
void Inventory::removeItem(Item* inventoryItem)
{
	sf::Texture emptyTex;
	emptyTex.loadFromFile("res/img/items/slot.png");
	Item* empty = new Item(0, 0, "slot", 0, 0, 0, &emptyTex);
	for (auto it = items.begin(); it != items.end(); it++) {
		if ((*it) == inventoryItem) {
			(*it) = empty;
			break;
		}
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
