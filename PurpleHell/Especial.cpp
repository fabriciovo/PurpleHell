#include "Especial.h"



Especial::Especial()
{

}

Especial::~Especial()
{
	delete this->animationComponent;
}

void Especial::Thunder(Entity * entity)
{
	/*this->name = "Thunder";
	this->power = 10;
	this->texture = new sf::Texture();
	this->texture->loadFromFile("res/img/Spells/" + name + ".png");
	this->CreateSprite(texture);

	//this->SetPosition(entity->->getPosition().x, entity->sprite->getPosition().y);
	this->createAnimationComponent(*texture);
	this->animationComponent->addAnimation("THUNDER_ANIMATION", 20.f, 0, 0, 3, 0, 128, 128);
	entity->setHp(entity->getHp()-10);*/

	entity->setHp(entity->getHp() - 20);
}

void Especial::Fireball(Entity * entity)
{
	entity->setHp(entity->getHp() - 10);
}

void Especial::MegaSlash(Entity * entity)
{
	entity->setHp(entity->getHp() - 10);
}

void Especial::action(Entity * entity)
{
}

void Especial::special(Entity * entity)
{
}


Especial::Especial(int i, Entity *entity)
{
	switch (i)
	{
	case especial_thunder:
		Thunder(entity);
		break;
	case especial_fireball:
		Fireball(entity);
		break;
	case especial_megaslash:
		MegaSlash(entity); 
		break;
	default:
		break;
	}
}

void Especial::updateAnimation(const float & dt)
{
	/*this->animationComponent->play("THUNDER_ANIMATION", dt);
	if (this->animationComponent->isDone("THUNDER_ANIMATION")) {
		this->animationComponent->~AnimationComponent();
	}*/
}

