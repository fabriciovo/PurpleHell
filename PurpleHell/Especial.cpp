#include "Especial.h"

Especial::Especial()
{

}
Especial::Especial(int i, Entity* entity, std::string name)
{
	this->texture = new sf::Texture();
	this->texture->loadFromFile("res/img/Spells/" + name + ".png");
	this->CreateSprite(texture);
	this->createAnimationComponent(*texture);
	this->SetPosition(entity->getPosition().x, entity->getPosition().y);
	this->SetScale(0.5f, 0.5f);
	this->animationComponent->addAnimation(name + "_animation", 8, 0, 0, 6, 2, 196, 178);
}

Especial::~Especial()
{
	delete this->sprite;
	delete this->texture;
	delete this->animationComponent;
}

void Especial::Thunder(Entity * entity[5])
{

}

void Especial::Fireball(Entity* entity)
{
	entity->setHp(entity->getHp() - 10);
}

void Especial::MegaSlash(Entity* entity)
{
	entity->setHp(entity->getHp() - 10);
}

void Especial::Action(Entity* entity)
{
}

void Especial::Special(Entity* entity)
{
}




void Especial::updateAnimation(const float& dt)
{
	std::string animation = this->name + "_animation";
	this->animationComponent->play(animation, dt);
	if (this->animationComponent->isDone(animation) && this->shouldDestroy) {
		this->animationComponent->~AnimationComponent();
	}
}

