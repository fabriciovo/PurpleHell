#ifndef  ENTITY_H
#define ENTITY_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <map>
#include <stack>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "AnimationComponent.h"


enum ENUM_BUFFS_ACTIVE {
	NORMAL,
	SHIELD,
};

enum ENUM_BUFFS_PASSIVE {
	NORMAL,
	HEAL,
};

enum ENUM_DEBUFFS {
	NORMAL,
	POISON,
	FIRE,
	FREEZE,
	STUN,
};


class Job;

class Entity
{
private:
	void initVariables();
protected:

	sf::Texture* texture;
	sf::Sprite* sprite;

	std::string name;
	std::string job;

	int hp;
	int power;
	int special;

	std::vector<ENUM_BUFFS_ACTIVE> activeBuff;
	std::vector <ENUM_BUFFS_PASSIVE> passiveBuff;
	std::vector <ENUM_DEBUFFS> debuff;


	bool selected = false;
	bool played = false;
	bool canUseSpecial = true;

	AnimationComponent *animationComponent;

public:


	Entity();
	virtual ~Entity();

	//Component
	void CreateSprite(sf::Texture*);
	void createAnimationComponent(sf::Texture& texture_sheet);

	virtual void SetPosition(const float x, const float y);
	virtual void SetScale(const float x, const float y);
	virtual void Action(Entity* entity) = 0;
	virtual void Special(Entity *entity) = 0;
	virtual void update(sf::Vector2f mousePos, const float &dt);
	virtual void render(sf::RenderTarget* target);

	sf::Sprite *getSprite();
	sf::Vector2f getPosition();
	
	std::string getName();
	std::string GetJob();

	int getType();
	int getHp();
	int getPower();

	const bool &getSelected() const;
	const bool &getPlayed() const;		
	bool getEspecial();

	std::vector <ENUM_BUFFS_ACTIVE> GetActiveBuff();
	std::vector <ENUM_BUFFS_PASSIVE> GetPassiveBuff();
	std::vector <ENUM_DEBUFFS> GetDebuff();

	void setDamage(int hp);	 
	void setHp(int hp);
	void setPower(int power);
	void setEspecial(bool value);
	void setPlayed(bool value);
	void setSelected(bool value);
	bool AddDebuff(ENUM_DEBUFFS effect);
	void AddActiveBuff(ENUM_BUFFS_ACTIVE effect);
	void AddPassiveBuff(ENUM_BUFFS_PASSIVE effect);
	void ApplyDebuff();
	void ApplyActiveBuff();
	void ApplyPassiveBuff();
};

#endif // ! ENTITY_H