#include "Enemy.h"



Enemy::Enemy()
{
}

Enemy::Enemy(float x, float y, std::string name, int hp, int power, sf::Texture* texture)
{
	this->name = name;
	this->hp = hp;
	this->power = power;
	this->CreateSprite(texture);
	this->SetPosition(x, y);
	this->createAnimationComponent(*texture);
	this->animationComponent->addAnimation("IDLE_MONSTER", 0, 0, 0, 1, 0, 16, 16);
}

Enemy::Enemy(std::string name, int hp, int power, sf::Texture* texture)
{
	this->name = name;
	this->hp = hp;
	this->power = power;
	this->CreateSprite(texture);
	this->createAnimationComponent(*texture);
	this->animationComponent->addAnimation("IDLE_MONSTER", 0, 0, 0, 1, 0, 16, 16);

}


Enemy::~Enemy()
{
}

void Enemy::action(Entity* entity)
{
	if(this->hp > 0){
		std::cout << "ENEMY " << this->name << " ATTACK" << std::endl;
		entity->setDamage(this->power);
		this->setPlayed(true);
		entity->setSelected(false);
		this->setSelected(false);
	}
}

void Enemy::special(Entity *entity)
{
}



void Enemy::update(sf::Vector2f mousePos)
{
	if (this->hp > 0) {
		if (this->sprite->getGlobalBounds().contains(mousePos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->selected = true;
			}
		}

		if (!this->sprite->getGlobalBounds().contains(mousePos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				this->selected = false;

			}
		}

		if (selected) {
			this->sprite->setColor(sf::Color::Yellow);
		}
		else {
			this->sprite->setColor(sf::Color::White);
		}
	}
	else {
		this->selected = false;
		this->sprite->setColor(sf::Color::Black);
	}
}

int Enemy::getHp()
{
	return this->hp;
}

std::string Enemy::getName()
{
	return this->name;
}

void Enemy::removeSelected()
{
	this->selected = false;
}

void Enemy::updateAnimation(const float & dt)
{
	this->animationComponent->play("IDLE_MONSTER", dt);
}

