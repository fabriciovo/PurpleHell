#include "Especial.h"



Especial::Especial()
{
}

Especial::~Especial()
{
}

void Especial::Thunder(Entity * entity)
{
	entity->setHp(entity->getHp()-10);
}

void Especial::Fireball(Entity * entity)
{
	entity->setHp(entity->getHp() - 10);
}

void Especial::MegaSlash(Entity * entity)
{
	entity->setHp(entity->getHp() - 10);
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


