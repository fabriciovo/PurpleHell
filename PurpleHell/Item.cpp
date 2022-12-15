#include "Item.h"



Item::Item()
{
}

Item::Item(int x, int y, std::string name,int hp,int power, int type, sf::Texture* texture)
{

	this->name = name;
	this->hp = hp;
	this->power = power;
	this->special = special;
	this->selected = false;
	this->CreateSprite(texture);
	this->SetPosition(x, y);
	this->createAnimationComponent(*texture);

}


Item::~Item()
{
	delete this->sprite;
	delete this->texture;
	delete this->animationComponent;
}

void Item::Action(Entity * entity)
{
	useItem(this->special,entity);
}

void Item::Special(Entity *entity)
{
}

void Item::useItem(int i, Entity * entity)
{
	switch (i)
	{
	case item_potion:
		Potion(entity);
		break;
	case item_knife:
		Knife(entity);
		std::cout << "Knife" << std::endl;
		break;
	case item_sword:
		Sword(entity);
		std::cout << "sword" << std::endl;
		break;
	case item_axe:
		Axe(entity);
		std::cout << "axe" << std::endl;
		break;
	case item_MagicAxe:
		MagicAxe(entity);
		std::cout << "Magic Axe" << std::endl;
		break;

	default:
		break;
	}
	this->selected = false;
	entity->setPlayed(true);
	entity->setSelected(false);
}

void Item::Potion(Entity *entity)
{
	entity->setHp(entity->getHp()+this->getPower());
	this->setSelected(false);
	this->setHp(0);
}

void Item::Sword(Entity *entity)
{
	entity->setPower(entity->getPower() + this->getPower());
	this->setSelected(false);
	this->setHp(0);
}

void Item::MagicAxe(Entity *entity)
{
	entity->setPower(entity->getPower() + this->getPower());
	this->setSelected(false);
	this->setHp(0);
}


void Item::Axe(Entity *entity)
{
	entity->setPower(entity->getPower() + this->getPower());
	this->setSelected(false);
	this->setHp(0);
}

void Item::Knife(Entity *entity)
{
	entity->setPower(entity->getPower() + this->getPower());
	this->setSelected(false);
	this->setHp(0);
}