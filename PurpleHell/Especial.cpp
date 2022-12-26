#include "Especial.h"

void Especial::specialInit()
{
	if (this->job == "mage") {

		switch (this->special)
		{
		case 1:
			this->name = "thunder";
			this->description = "Deals damage to all enemies.";
			this->createAnimation(0, 0, 4, 0, 16, 64, 0, -48);
			
			break;
		case 2:
			this->name = "Fireball";
			this->description = "Deals damage to one enemy and burn it";
			break;
		case 3:
			this->name = "Waterfall";
			this->description = "Deals extra damage to one enemy.";
			break;
		}
	}
	else if (this->job == "rogue") {
		switch (this->special)
		{
		case 1:
			this->name = "Steal";
			this->description = "Deals damage to one enemy and steal gold";
			break;
		case 2:
			this->name = "Poison Dagger";
			this->description = "Deals damage to one enemy with a poison knife";
			break;
		case 3:
			this->name = "Kick";
			this->description = "Stun an enemy";
			break;
		}
	}
	else if (this->job == "knight") {
		switch (this->special)
		{
		case 1:
			this->name = "Double slash";
			this->description = "Deals .";
			break;
		case 2:
			this->name = "Rage";
			this->description = "Deals x4 more damage";
			break;
		case 3:
			this->name = "Kick";
			this->description = "Stun an enemy.";
			break;
		}
	}
	else if (this->job == "demon hunter") {
		switch (this->special)
		{
		case 1:
			this->name = "Scars slash";
			this->description = "Deals ";
			break;
		case 2:
			this->name = "Drain Blood";
			this->description = "Deals damage to one enemy with a poison knife.";
			break;
		case 3:
			this->name = "Punch";
			this->description = "Deals damage to one enemy.";
			break;
		}
	}
	else if (this->job == "warlock") {
		switch (this->special)
		{
		case 1:
			this->name = "Drain Life";
			this->description = "Deals damage to one enemy and heal half of the damage.";
			break;
		case 2:
			this->name = "Death Touch";
			this->description = "Instant kill an enemy but you lost half of the life.";
			break;
		case 3:
			this->name = "Curse";
			this->description = "Deals curse damage to one enemy.";
			break;
		}
	}
	else if (this->job == "archer") {
		switch (this->special)
		{
		case 1:
			this->name = "Double slash";
			this->description = "Deals ";
			break;
		case 2:
			this->name = "Poison Dagger";
			this->description = "Deals damage to one enemy with a poison knife";
			break;
		case 3:
			this->name = "Kick";
			this->description = "Stun an enemy";
			break;
		}
	}
}

Especial::Especial()
{

}
Especial::Especial(std::string name)
{
	this->name = name;
	this->texture = new sf::Texture();
	this->texture->loadFromFile("res/img/Effects/" + this->name + ".png");
	this->CreateSprite(texture);
	this->createAnimationComponent(*texture);
	this->animationComponent->addAnimation(this->name + "_animation", 4, 0, 0, 6, 0, 16, 16);
}
Especial::Especial(std::string jobName, int special)
{
	this->special = special;
	this->job = jobName;
	this->specialInit();
}

Especial::Especial(std::string name, Entity* entity)
{
	this->name = name;
	this->texture = new sf::Texture();
	this->texture->loadFromFile("res/img/Effects/" + this->name + ".png");
	this->CreateSprite(texture);
	this->createAnimationComponent(*texture);
	this->SetPosition(entity->getPosition().x, entity->getPosition().y);
	this->animationComponent->addAnimation(this->name + "_animation", 8, 0, 0, 4, 0, 16, 16);
}

Especial::~Especial()
{
	//delete this->sprite;
	//delete this->texture;
	//delete this->animationComponent;
}

void Especial::Thunder(Entity* entity[5])
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

void Especial::SetIsPlaying(bool value)
{
	 this->isPlaying = value;
}

bool Especial::GetIsPlaying()
{
	return this->isPlaying;
}




void Especial::updateAnimation(const float& dt)
{
	if (isPlaying) {
		std::string animation = this->name + "_animation";
		this->animationComponent->play(animation, dt);
		if (this->animationComponent->isDone(animation)) {
			isPlaying = false;
		}

	}
}

std::string Especial::GetDescription()
{
	return this->description;
}

int Especial::GetOffsetX()
{
	return this->offsetx;
}

int Especial::GetOffsetY()
{
	return this->offsety;
}


void Especial::createAnimation(int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height, int offsetx, int offsety)
{
	this->offsetx = offsetx;
	this->offsety = offsety;
	this->texture = new sf::Texture();
	this->texture->loadFromFile("res/img/Effects/" + this->name + ".png");
	this->CreateSprite(texture);
	this->createAnimationComponent(*texture);
	this->animationComponent->addAnimation(this->name + "_animation", 4, start_frame_x, start_frame_y, frames_x, frames_y, width, height);

}
