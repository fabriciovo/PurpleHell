#include "Units.h"


void Units::initUnits()
{
	std::ifstream ifsUnits("res/Player/Units.txt");
	ArquivoUnits(ifsUnits, 0);
}

Units::Units()
{
	this->initUnits();
}

Units::~Units()
{

}

void Units::renderUnits(sf::RenderTarget* target)
{
	for (int i = 0; i < this->maxUnitsInventory; i++) {
			this->heroes[i]->render(target);
	}
}

void Units::updateUnits(sf::Vector2f mousePos,const float &dt)
{
	for (int i = 0; i < this->maxUnitsInventory; i++) {
		if (this->heroes[i])
			this->heroes[i]->update(mousePos, dt);
	}
}

bool Units::selectedHero()
{
	for (int i = 0; i < this->maxUnitsInventory; i++) {
		if (this->heroes[i]) {
			if (heroes[i]->getSelected()) {
				return true;
			}
		}
	}
	return false;
}

Entity* Units::getHero()
{
	for (int i = 0; i < this->maxUnitsInventory; i++) {
		if (this->heroes[i]) {
			if(this->heroes[i]->getName() != "slot"){
				if (heroes[i]->getSelected()) {
					return this->heroes[i];
				}
			}
		}
	}
	return nullptr;
}


void Units::setUnits(int i, Hero* hero)
{
	this->heroes[i] = hero;
}

Entity* Units::getTeam(int i)
{
	return this->heroes[i];
}

int Units::UnitNumber()
{
	for (int i = 0; i < this->maxUnitsInventory; i++) {
		if (this->heroes[i]) {
				if (heroes[i]->getSelected()) {
					return i;
				}
		}
	}
}
//Arquivos
void Units::ArquivoUnits(std::ifstream &ifsUnits, int i)
{
	std::string name = " ";
	int hp = 0, power = 0, spell = 0;

	if (ifsUnits.is_open())
	{

		if (!ifsUnits.eof())
		{

			ifsUnits >> name >> hp >> power >> spell;

			if (name != " ") {
				sf::Texture *tex;
				tex = new sf::Texture();
				tex->loadFromFile("res/img/Player/" + name + ".png");
				this->heroes[i] = new Hero(93 + (25 * i), 23, name, hp, power, spell, tex);
				i++;
			}
			ArquivoUnits(ifsUnits, i);
		}
		else {
			ifsUnits.close();
		}
	}

}