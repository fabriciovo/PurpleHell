#ifndef  ESPECIAL_H
#define	 ESPECIAL_H

#include <iostream>
#include "Entity.h"
class Especial : public Entity

{
private:
	bool shouldDestroy = true;
	bool isPlaying = false;

	std::string description;
	std::string job;
	int special = 0;
	void specialInit();
public:
	Especial();
	Especial(std::string jobName, int special);
	Especial(std::string name, Entity * entity);
	Especial(std::string name);

	virtual ~Especial();

	void Thunder(Entity *entity[5]);
	void Fireball(Entity *entity);
	void MegaSlash(Entity *entity);

	void Action(Entity* entity);
	void Special(Entity *entity);
	void SetIsPlaying(bool value);
	bool GetIsPlaying();
	void updateAnimation(const float &dt);

	std::string GetDescription();


	enum mage_specials
	{
		mage_thunder =  0,
		mage_fireball = 1,
		mage_waterfall = 2,
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
		debuff_stun = 3,
		debuff_blood = 4
	};



};


#endif // ! SPELL_H