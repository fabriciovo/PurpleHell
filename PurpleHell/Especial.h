#ifndef  ESPECIAL_H
#define	 ESPECIAL_H

#include <iostream>
#include "Entity.h"
class Especial : public Entity

{
private:
	bool shouldDestroy = false;
public:
	Especial();
	Especial(int i, Entity *entity, std::string name);
	virtual ~Especial();

	void Thunder(Entity *entity[5]);
	void Fireball(Entity *entity);
	void MegaSlash(Entity *entity);

	void Action(Entity* entity);
	void Special(Entity *entity);
	void updateAnimation(const float &dt);

	enum Especials
	{
		especial_thunder =  0,
		especial_fireball = 1,
		especial_megaslash =2
	};

	enum CombatBuffs
	{
		combatbuff_normal = 0,
		combatbuff_normal_shield = 1,
	};

	enum Buffs
	{
		buff_normal = 0,
		buff_heal = 1,
	};

	enum Debuffs
	{
		debuff_normal = 0,
		debuff_poison = 1,
		debuff_fire = 2,
		debuff_stun = 3
	};



};


#endif // ! SPELL_H