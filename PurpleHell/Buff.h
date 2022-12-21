#ifndef  ESPECIAL_H
#define	 ESPECIAL_H

#include <iostream>
#include "Entity.h"
class Buff : public Entity

{
public:
	Buff();
	Buff(int i, Entity* entity);
	virtual ~Buff();

	void Heal(Entity* entity);
	void Cleanse(Entity* entity);

	void updateAnimation(const float& dt);

	enum BUFFS_ENUM
	{
		BUFFS_NORMAL = 0,
		BUFFS_HEAL = 1,
		BUFF_CLEANSE = 2
	};


};


#endif // ! SPELL_H