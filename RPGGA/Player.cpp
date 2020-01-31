#include "Player.h"



Player::Player()
{
	this->initHeroesMenu();
	this->initEquipedItems();
}

Player::Player(bool battle)
{
	if (battle) {
		this->initHeroesBattle();
		this->initEquipedItems();
	}
	else {
		this->initHeroesMenu();
		this->initEquipedItems();
	}
}


Player::~Player()
{
	for (int i = 0; i < this->maxUnits; i++) {
		delete this->team[i];
	}
}
void Player::initHeroesMenu()
{
	std::ifstream ifsHeroes("res/Player/Team.txt");
	this->ArquivoHeroesMenu(ifsHeroes, 0);
}

void Player::initHeroesBattle()
{
	std::ifstream ifsHeroes("res/Player/Team.txt");
	this->ArquivoHeroesBattle(ifsHeroes, 0);

}


void Player::initEquipedItems()
{
	this->equipedItems = new EquipedItems();
}


void Player::render(sf::RenderTarget * target)
{
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i]) {
			this->team[i]->render(target);

			if(this->team[i]->getSpell()){
				this->team[i]->getSpell()->render(target);
			}
		}
	}
}

void Player::update(sf::Vector2f mousePos,const float &dt)
{
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i]){
			this->team[i]->update(mousePos,dt);
			this->team[i]->updateAnimation(dt);

			if (this->team[i]->getSpell()) {
				this->team[i]->getSpell()->updateAnimation(dt);
			}

		}
	}
}

void Player::battlePosition()
{
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i])
			this->team[i]->SetPosition(250 + (23 * i), 150);
	}
}


Entity* Player::getHero()
{
	
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i]){
			if (team[i]->getSelected() ) {
				return this->team[i];
			}
		}
	}
	return nullptr;


}

Entity* Player::getTeam(int i)
{
	return this->team[i];
}

void Player::setTeam(int i, Hero * hero)
{
	this->team[i] = hero;
}

EquipedItems * Player::getEquipedItems()
{
	return this->equipedItems;
}

bool Player::getClear()
{
	return this->clear;
}
void Player::setClear(bool value)
{
	this->clear = value;
}

int Player::teamSize()
{
	int a = 0;
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i]) {
			if (this->team[i]->getName() != "slot") {
				a++;
			}
		}
	}
	return a;
}

bool Player::checkPlayed()
{
	for (int i = 0; i < this->maxUnits; i++) {
		if(team[i]){
			if (!team[i]->getPlayed()) {
				return true;
			}
		}
	}
	return false;
}

void Player::setTeamToTrue()
{
	for (int i = 0; i < this->maxUnits; i++) {
		if(this->team[i] && this->team[i]->getName() != "slot")
			this->team[i]->setPlayed(false);
		
	}

}

bool Player::checkDeads()
{
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i])
			if (this->team[i]->getHp() > 0) {
				return false;
				break;
			}
	}
	return true;
}

void Player::checkDead()
{
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i])
			if (this->team[i]->getHp() <= 0 && this->team[i]->getPlayed() == false) {
					this->team[i]->setPlayed(true);
			}
	}
}

int Player::UnitNumber(Entity *hero)
{
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i]->getName() == hero->getName()) {
				return i;
		}
	}
}
//Arquivos
void Player::ArquivoHeroesMenu(std::ifstream &ifsHeroes,int i)
{

	std::string name = " ";
	int hp = 0, power = 0, job = 0;

	if (ifsHeroes.is_open())
	{
		if (!ifsHeroes.eof())
		{

			ifsHeroes >> name >> hp >> power >> job;
				if(name != " "){
					sf::Texture *tex;
					tex = new sf::Texture();
					tex->loadFromFile("res/img/Player/" + name + ".png");
					this->team[i] = (new Hero(200 + (23 * i), 148, name, hp, power, job, tex));
					i++;
				}
			ArquivoHeroesMenu(ifsHeroes,i);
		}
		else {
			ifsHeroes.close();
		}
	}

}

void Player::ArquivoHeroesBattle(std::ifstream &ifsHeroes, int i)
{
	std::string name = " ";
	int hp = 0, power = 0, spell = 0;

	if (ifsHeroes.is_open())
	{

		if (!ifsHeroes.eof())
		{
			ifsHeroes >> name >> hp >> power >> spell;
			if (name != "slot") {
				sf::Texture *tex;
				tex = new sf::Texture();
				tex->loadFromFile("res/img/Player/" + name + ".png");
				this->team[i] = (new Hero(0, 0, name, hp, power, spell, tex));
				i++;
			}
			ArquivoHeroesBattle(ifsHeroes,i);
		}
		else {
			ifsHeroes.close();
		}
	}

}