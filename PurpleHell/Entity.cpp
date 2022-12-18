#include "Entity.h"

void Entity::initVariables()
{
	this->texture = NULL;
	this->sprite = NULL;
	this->animationComponent = NULL;
	this->selected = false;
	this->played = false;
}

Entity::Entity()
{
	this->initVariables();
}


Entity::~Entity()
{
	delete this->texture;
	delete this->sprite;
	delete this->animationComponent;
}

void Entity::CreateSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
	this->sprite->setTexture(*this->texture);
}

void Entity::createAnimationComponent(sf::Texture & texture_sheet)
{
	this->animationComponent = new AnimationComponent(*this->sprite, texture_sheet);
}

const bool & Entity::getSelected() const
{
	// TODO: inserir instru��o de retorno aqui
	return this->selected;
}

const bool& Entity::getPlayed() const
{
	return this->played;
}

sf::Sprite* Entity::getSprite()
{
	return this->sprite;
}


void Entity::setDamage(int damage)
{
	this->hp -= damage;

}
void Entity::setHp(int hp)
{
	this->hp = hp;

}

void Entity::setPower(int power)
{
	this->power = power;
}

void Entity::ApplyEffect()
{
	switch (battleStatus)
	{
	case poison:
		std::cout << "poison" << std::endl;
		break;
	case fire:
		std::cout << "fire" << std::endl;
		break;
	case stun:
		std::cout << "stun" << std::endl;
		break;
	case shield:
		std::cout << "shield" << std::endl;
		break;
	default:
		std::cout << "No effect" << std::endl;
		break;
	}
}
ENUM_STATUS Entity::GetEffect()
{
	return this->battleStatus;
}


int Entity::getType()
{
	return this->special;
}

void Entity::SetPosition(const float x, const float y)
{
	if (this->sprite)
		this->sprite->setPosition(sf::Vector2f(x, y));
}

void Entity::SetScale(const float x, const float y)
{
	this->sprite->setScale(x, y);
}

void Entity::update(sf::Vector2f mousePos, const float &dt)
{
	if (this->selected ) {
		this->sprite->setColor(sf::Color::Yellow);
	}
	else if (this->played && this->hp > 0) {
		this->sprite->setColor(sf::Color::Green);
	}
	else if (this->hp <= 0) {
		this->sprite->setColor(sf::Color::Black);
	}
	else {
		this->sprite->setColor(sf::Color::White);
	}
}


void Entity::render(sf::RenderTarget * target)
{
	if (this->sprite)
		target->draw(*this->sprite);
}

std::string Entity::getName()
{
	return this->name;
}
std::string Entity::GetJob()
{
	return this->job;
}
int Entity::getHp()
{
	return this->hp;
}

int Entity::getPower()
{
	return this->power;
}

bool Entity::getEspecial()
{
	return this->canUseSpecial;
}

void Entity::setEspecial(bool value)
{
	this->canUseSpecial = value;
}

sf::Vector2f Entity::getPosition()
{
	return this->sprite->getPosition();
}

void Entity::setPlayed(bool value)
{
	this->played = value;
}

void Entity::setSelected(bool value)
{
	this->selected = value;

}


