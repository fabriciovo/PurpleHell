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

	this->name = "slash";
	this->power = 10;
	this->texture = new sf::Texture();
	this->texture->loadFromFile("res/img/Spells/" + name + ".png");
	this->CreateSprite(texture);
	this->createAnimationComponent(*texture);
	this->SetPosition(entity->getPosition().x , entity->getPosition().y);
	this->SetScale(0.5f, 0.5f);
	this->animationComponent->addAnimation("SLASH_ANIMATION", 8, 0, 0, 6, 2, 196, 178);

	//Thunder(entity);
	/*switch (i)
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
	}*/
}

void Especial::updateAnimation(const float & dt)
{
	this->animationComponent->play("SLASH_ANIMATION", dt);
	if (this->animationComponent->isDone("SLASH_ANIMATION")) {
		this->animationComponent->~AnimationComponent();
	}
}

