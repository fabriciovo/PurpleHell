#ifndef  ESPECIAL_H
#define	 ESPECIAL_H

#include <iostream>
#include "Entity.h"
class Especial : public Entity

{
public:
	Especial();
	Especial(int i, Entity *entity);
	virtual ~Especial();

	void Thunder(Entity *entity);
	void Fireball(Entity *entity);
	void MegaSlash(Entity *entity);

	void action(Entity* entity);
	void special(Entity *entity);
	void updateAnimation(const float &dt);

	enum Especials
	{
		especial_thunder =  0,
		especial_fireball = 1,
		especial_megaslash =2
	};


};


#endif // ! SPELL_H